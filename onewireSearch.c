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
		
	while(1)
	{
		// ...
	}	
	
	return 0;
}


