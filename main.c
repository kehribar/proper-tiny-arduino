/*
* ----------------------------------------------------------------------------
* “THE COFFEEWARE LICENSE” (Revision 1):
* <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a coffee in return.
* -----------------------------------------------------------------------------
*/

#include "./pta/pta.h"

int main()
{
	initSerial();
	
	pinMode(A,6,OUTPUT);

	while(1)
	{	
		xprint("Hello World!\n");
		_delay_ms(500);
		togglePin(A,6);
	}
	
	return 0;
}


