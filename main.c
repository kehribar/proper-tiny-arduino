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
	uint16_t i;
	
	initSerial();
	
	pinMode(A,6,OUTPUT);
	
	while(1)
	{	
		readLine(buf,64);
		
		i=atoi(buf);

		xprintf(PSTR("#val: %d\r\n"),i);

		toneWrite(PWM0A,i);
	}
	
	return 0;
}


