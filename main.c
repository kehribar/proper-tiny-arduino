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
		i=atoi(buf+1);		

		switch(buf[0])
		{
			case 'r':
				analogWrite(0,i);
			break;
			case 'g':
				analogWrite(1,i);
			break;
			case 'b':
				analogWrite(3,i);			
			break;
		}

		togglePin(A,6);
	}
	
	return 0;
}


