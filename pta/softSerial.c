/*
* ----------------------------------------------------------------------------
* “THE COFFEEWARE LICENSE” (Revision 1):
* <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a coffee in return.
* -----------------------------------------------------------------------------
*/

#include "softSerial.h"

void initSerial()
{
	xfunc_out = xmit;

	pinMode(B,0,OUTPUT);
	pinMode(B,1,INPUT);
	internalPullup(B,1,DISABLE);
	xmit('\n');
}

void xprint(char* tx)
{
	while(*tx) 
		xmit(*tx++);
}


void readLine(char* lineBuf,uint8_t len)
{
	uint8_t c, i;
	len--; i=0;

	xmit('>');	
	for (;;) 
	{
		c = serialRead();
		if (i == len) break;
		if (c == '\r' || c == '\n') break;
		if (c >= ' '){
			lineBuf[i++] = c;
			xmit(c);
		}
	}
	lineBuf[i]=0;
	xmit('\r');	
	xmit('\n');
}
