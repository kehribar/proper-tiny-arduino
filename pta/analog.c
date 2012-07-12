/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "analog.h"

void initADC(uint8_t VREF,uint8_t PRESCALE)
{
	adcSetting = 0;
	
	sbi(ADCSRA,ADEN); // Enable the ADC peripheral

	ADCSRA |= PRESCALE; // Least significant three bits are prescale settings

	switch(VREF)
	{
		case 0: // Use VCC as Vref.
			adcSetting = 0;
			break;
		case 1: // 1.1V 
			#if defined(__AVR_ATtiny13__)
				sbi(adcSetting,REFS0);
			#else
				sbi(adcSetting,REFS1);
			#endif
			break;
		case 2: // 2.56V -> Available only at x5 series.
			#if defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny84__)
				// "Not available for this series."		
			#else
				sbi(adcSetting,REFS1);
				sbi(adcSetting,REFS2);
			#endif
			break;
	}

}

uint16_t analogRead(uint8_t ch)
{
	uint16_t value;

	ADMUX = adcSetting | ch; // Set the desired channel

	sbi(ADCSRA,ADSC); // Start conversion

	while(checkBit(ADCSRA,ADSC)); // Wait for conversion	

	value = ADCL;	value += ADCH << 8; // Read the result

	return value; // Return value
}
 

