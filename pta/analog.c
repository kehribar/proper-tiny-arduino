/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "analog.h"


uint16_t analogRead(uint8_t ch)
{
	uint16_t value;
		
	ADCSRA = (1<<ADEN); // Prescaler:2 ,Voltage ref: VDD

	ADMUX = ch; 	
	
	ADCSRA|=(1<<ADSC); // Start conversion
	while(ADCSRA & (1<<ADSC)); // Wait for conversion

	value = ADCL;	value += ADCH << 8;

	return value;
}
 
 
 
 
 
 
 
