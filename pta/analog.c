/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "analog.h"

uint8_t adcSetting = 0;

void initADC(uint8_t VREF,uint8_t PRESCALE)
{
	sbi(ADCSRA,ADEN); // Enable the ADC peripheral

	if(PRESCALE>128) PRESCALE = 128;

	ADCSRA |= (PRESCALE>1); // Last three bits are prescale settings

	switch(VREF)
	{
		case 0: // Use VCC as Vref.
			adcSetting = 0;
			break;
		case 1: // 1.1V -> Available at x4 and x5 series.
			sbi(adcSetting,REFS1);
			break;
		case 2: // 2.56V -> Available at x5 series.
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

	ADMUX = adcSetting | ch; 	

	sbi(ADCSRA,ADSC); // Start conversion

	while(checkBit(ADCSRA,ADSC)); // Wait for conversion	

	value = ADCL;	value += ADCH << 8; // Read the result

	return value;
}
 
 
 
 
 
 
 
