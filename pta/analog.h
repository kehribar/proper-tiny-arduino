/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef ANALOG
#define ANALOG
 
#include <avr/io.h>
#include "macro.h"

#define closeAdc() ADCSRA = 0x00;

#define VREF_VCC		0
#define VREF_1100mV		1
#define VREF_2560mV		2 // Not available at Tiny13 and Tiny24/44/84

#define PRESCALE_2		1
#define PRESCALE_4		2
#define PRESCALE_8		3
#define PRESCALE_16		4
#define PRESCALE_32		5	
#define PRESCALE_64		6
#define PRESCALE_128	7

uint8_t adcSetting;
uint16_t analogRead(uint8_t ch);
void initADC(uint8_t VREF,uint8_t PRESCALE);

#endif
