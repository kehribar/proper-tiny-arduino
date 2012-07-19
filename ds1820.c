/*
 * ----------------------------------------------------------------------------
 * “THE COFFEEWARE LICENSE” (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * -----------------------------------------------------------------------------
 */

#include "./pta/pta.h"
uint8_t readVal[9];

int main()
{
	uint16_t i,t;
	
	initSerial();
	
	xputs(PSTR("\r\n"));
	xputs(PSTR("> -------------------------------\r\n"));
	xputs(PSTR("> Hello Console!\r\n"));
	
	if(onewire_firstAddress())
	{
		xprintf(PSTR("> Addr: %X\t"),ROM_NO[0]);
		for(t=0;t<7;t++)
			xprintf(PSTR("%X\t"),ROM_NO[t+1]);			
		xmit('\r');
		xmit('\n');
		i=1;
	}

	while(onewire_nextAddress())
	{
		xprintf(PSTR("> Addr: %X\t"),ROM_NO[0]);
		for(t=0;t<7;t++)
			xprintf(PSTR("%X\t"),ROM_NO[t+1]);			
		xmit('\r');
		xmit('\n');
		i++;
	}
		
	xprintf(PSTR("> End of search with %d device(s) found\r\n"),i);
	
	delay(1000);	
		
	while(1)
	{
		i = onewire_resetPulse(); /* Send reset */
				
		onewire_writeByte(0x55); /* Match ROM command*/
		
		onewire_writeByte(ROM_NO[0]); /* Address begins */
		onewire_writeByte(ROM_NO[1]);
		onewire_writeByte(ROM_NO[2]);
		onewire_writeByte(ROM_NO[3]);
		onewire_writeByte(ROM_NO[4]);
		onewire_writeByte(ROM_NO[5]);
		onewire_writeByte(ROM_NO[6]);
		onewire_writeByte(ROM_NO[7]); /* Address ends */
		
		onewire_writeByte(0x44); /* Convert! command */
		
		delay(500); /* Wait a little ... */
		
		i = onewire_resetPulse(); /* Send reset */
		
		onewire_writeByte(0x55); /* Match ROM command*/
		
		onewire_writeByte(ROM_NO[0]); /* Address begins */
		onewire_writeByte(ROM_NO[1]);
		onewire_writeByte(ROM_NO[2]);
		onewire_writeByte(ROM_NO[3]);
		onewire_writeByte(ROM_NO[4]);
		onewire_writeByte(ROM_NO[5]);
		onewire_writeByte(ROM_NO[6]);
		onewire_writeByte(ROM_NO[7]); /* Address ends */			
		
		onewire_writeByte(0xBE); /* Read scratchpad command */
		
		xputs(PSTR("> Raw data: "));
		for(i=0;i<9;i++)
		{	
			readVal[i]=onewire_readByte();
			xprintf(PSTR("%X\t"),readVal[i]);
		}
	
		/* 1st and 2nd bytes represents temp value. Resoluton is 0.5 celcius degrees*/
		xprintf(PSTR("> Temp: %d c\r\n"),((readVal[1]<<8)+readVal[0])>>1); 
		
		i = onewire_resetPulse(); /* Send reset */

		xputs(PSTR("> ------------------\r\n"));		
	}
	
	return 0;
}


