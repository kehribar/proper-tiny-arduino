/*
 * ----------------------------------------------------------------------------
 * “THE COFFEEWARE LICENSE” (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * -----------------------------------------------------------------------------
 */

#include "onewire.h"

/* Data port is predefined as PORTB */
#define DATA_PIN 2

/******************************************************************************
/ Drives the line HIGH or LOW
/*****************************************************************************/
void onewire_driveLine(uint8_t state)
{
	pinMode(B,DATA_PIN,OUTPUT);
	digitalWrite(B,DATA_PIN,state);
}

/******************************************************************************
/ Reads the data line and returns the state
/*****************************************************************************/
uint8_t onewire_readLine()
{
	uint8_t value;

	pinMode(B,DATA_PIN,INPUT);
	
	if(digitalRead(B,DATA_PIN))	
		value = 0;
	else	
		value = 1;

	return value;
}

/******************************************************************************
/ Sends the reset pulse and returns 1 if any device present at the bus
/*****************************************************************************/
uint8_t onewire_resetPulse()
{
	uint8_t isDevicePresent;
	
  	onewire_driveLine(LOW);			// Drive the bus low
 	
 	delayMicroseconds(500); 			// delay 480 microsecond (us)		

 	onewire_driveLine(HIGH);			// Release the bus
	
	delayMicroseconds(80);			// delay 70 microsecond (us)
	
	isDevicePresent = onewire_readLine();	//Sample for presence pulse from slave

 	delayMicroseconds(420);			// delay 410 microsecond (us)		
	
	onewire_driveLine(HIGH);		    	// Release the bus
	
	return isDevicePresent;
}

/******************************************************************************
/ Sends a single bit to the slave device
/*****************************************************************************/
void onewire_writeBit(uint8_t bitValue)
{
	if (bitValue)
	{
		//writing a bit '1'
		onewire_driveLine(LOW);			// Drive the bus low
		delayMicroseconds(10);			// delay 6 microsecond (us)
		onewire_driveLine(HIGH); 		// Release the bus
		delayMicroseconds(55);			// delay 64 microsecond (us)
	}
	else
	{
		//writing a bit '0'
		onewire_driveLine(LOW);			// Drive the bus low
		delayMicroseconds(65);			// delay 60 microsecond (us)
		onewire_driveLine(HIGH); 		// Release the bus
		delayMicroseconds(5);			// delay 10 microsecond (us)
	}
}	

/******************************************************************************
/ Reads a single bit from the slave device
/*****************************************************************************/
uint8_t onewire_readBit()
{
	uint8_t value; 

	onewire_driveLine(LOW);					// Drive the bus low
	delayMicroseconds(6);					// delay 6 microsecond (us)
	onewire_driveLine(HIGH); 				// Release the bus
	delayMicroseconds(10);					// delay 9 microsecond (us)

	value = onewire_readLine();				// Read the status of OW_PIN

	delayMicroseconds(55);					// delay 55 microsecond (us)	

	return !value;
}

/******************************************************************************
/ Writes a byte to the slave device
/*****************************************************************************/
void onewire_writeByte(uint8_t byteValue)
{
	uint8_t i;
	
	for (i=0;i<8;i++)
	{
		onewire_writeBit(byteValue & 0x01); 	// sending LS-bit first
		byteValue >>= 1;					// shift the data byte for the next bit to send
	}	
}

/******************************************************************************
/ Reads a byte from the slave device
/*****************************************************************************/
uint8_t onewire_readByte()
{
	uint8_t value=0;
	uint8_t i;
	
	for(i=0;i<8;i++)
	{
		value >>= 1; 					// shift the result to get it ready for the next bit to receive
		if (onewire_readBit())
			value |= 0x80;				// if result is one, then set MS-bit
	}

	return value;					
}	

/******************************************************************************
/ Do the crc8 calculation
/ Taken from: http://www.maxim-ic.com/appnotes.cfm/appnote_number/187
/*****************************************************************************/
uint8_t docrc8(uint8_t value)
{
   // See Maxim Application Note 27

   crc8 = pgm_read_byte(dscrc_table + (crc8 ^ value));

   return crc8;
}

/******************************************************************************
/ Find the next address and store them int ROM_NO[8] array.
/ 	- If no new device had found, returns 0
/ Taken from: http://www.maxim-ic.com/appnotes.cfm/appnote_number/187
/*****************************************************************************/
int onewire_nextAddress()
{
   int id_bit_number;
   int last_zero, rom_byte_number, search_result;
   int id_bit, cmp_id_bit;
   uint8_t rom_byte_mask, search_direction;

   // initialize for search
   id_bit_number = 1;
   last_zero = 0;
   rom_byte_number = 0;
   rom_byte_mask = 1;
   search_result = 0;
   crc8 = 0;

   // if the last call was not the last one
   if (!LastDeviceFlag)
   {
      // 1-Wire reset
      if (!onewire_resetPulse())
      {
         // reset the search
         LastDiscrepancy = 0;
         LastDeviceFlag = FALSE;
         LastFamilyDiscrepancy = 0;
         return FALSE;
      }

      // issue the search command 
      onewire_writeByte(0xF0);  

      // loop to do the search
      do
      {
         // read a bit and its complement
         id_bit = onewire_readBit();
         cmp_id_bit = onewire_readBit();

         // check for no devices on 1-wire
         if ((id_bit == 1) && (cmp_id_bit == 1))
            break;
         else
         {
            // all devices coupled have 0 or 1
            if (id_bit != cmp_id_bit)
               search_direction = id_bit;  // bit write value for search
            else
            {
               // if this discrepancy if before the Last Discrepancy
               // on a previous next then pick the same as last time
               if (id_bit_number < LastDiscrepancy)
                  search_direction = ((ROM_NO[rom_byte_number] & rom_byte_mask) > 0);
               else
                  // if equal to last pick 1, if not then pick 0
                  search_direction = (id_bit_number == LastDiscrepancy);

               // if 0 was picked then record its position in LastZero
               if (search_direction == 0)
               {
                  last_zero = id_bit_number;

                  // check for Last discrepancy in family
                  if (last_zero < 9)
                     LastFamilyDiscrepancy = last_zero;
               }
            }

            // set or clear the bit in the ROM byte rom_byte_number
            // with mask rom_byte_mask
            if (search_direction == 1)
              ROM_NO[rom_byte_number] |= rom_byte_mask;
            else
              ROM_NO[rom_byte_number] &= ~rom_byte_mask;

            // serial number search direction write bit
            onewire_writeBit(search_direction);

            // increment the byte counter id_bit_number
            // and shift the mask rom_byte_mask
            id_bit_number++;
            rom_byte_mask <<= 1;

            // if the mask is 0 then go to new SerialNum byte rom_byte_number and reset mask
            if (rom_byte_mask == 0)
            {
                docrc8(ROM_NO[rom_byte_number]);  // accumulate the CRC
                rom_byte_number++;
                rom_byte_mask = 1;
            }
         }
      }
      while(rom_byte_number < 8);  // loop until through all ROM bytes 0-7

      // if the search was successful then
      if (!((id_bit_number < 65) || (crc8 != 0)))
      {
         // search successful so set LastDiscrepancy,LastDeviceFlag,search_result
         LastDiscrepancy = last_zero;

         // check for last device
         if (LastDiscrepancy == 0)
            LastDeviceFlag = TRUE;
         
         search_result = TRUE;
      }
   }

   // if no device found then reset counters so next 'search' will be like a first
   if (!search_result || !ROM_NO[0])
   {
      LastDiscrepancy = 0;
      LastDeviceFlag = FALSE;
      LastFamilyDiscrepancy = 0;
      search_result = FALSE;
   }

   return search_result;
}

/******************************************************************************
/ Start searching for device adress on the onewire bus and store into them
/ ROM_NO[8] array. 
/	- If no new device had found, returns 0
/*****************************************************************************/
int onewire_firstAddress()
{
   // reset the search state
   LastDiscrepancy = 0;
   LastDeviceFlag = FALSE;
   LastFamilyDiscrepancy = 0;

   return onewire_nextAddress();
}

