/*
 * ----------------------------------------------------------------------------
 * “THE COFFEEWARE LICENSE” (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * -----------------------------------------------------------------------------
 */

#include "./pta/pta.h"
char buf[64];

int main()
{
	uint16_t i,t;
	
	initSerial();

	initADC(VREF_1100mV,PRESCALE_128);

	while(1)
	{	
		i = 0;
		
		for(t=0;t<64;t++)
			i += analogRead(1);

		i >>= 6;		

		xprintf(PSTR("#val: %d\r\n"),i);
	}
	
	return 0;
}




