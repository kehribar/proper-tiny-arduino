/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */
 
#include "tone_t84.h" 
static uint8_t toneStatus = 0;

/*****************************************************
*	freq = F_CPU / Prescale / (value+1) / 2 ;
* 	Max freq = F_CPU / Prescale / 2;
* 	Min freq = F_CPU / Prescale / 512 ; 
*	For 1MHZ , 256 prescale => 
*		MAX: ~1953 Hertz , MIN: ~7 Hertz
******************************************************/
void toneWrite(uint8_t ch, uint8_t val)
{
	switch(ch)
	{
		case 0:
		{
			if(!checkBit(toneStatus,0))
			{
				sbi(toneStatus,0);
				initTone(PWM0A);
			}
			_updatePWM0A(val);
			break;
		}
		case 1:
		{
			if(!checkBit(toneStatus,1))
			{
				sbi(toneStatus,1);
				initTone(PWM0B);
			}
			_updatePWM0B(val);
			break;
		}		
		case 2:
		{
			if(!checkBit(toneStatus,2))
			{
				sbi(toneStatus,2);
				initTone(PWM1A);
			}
			_updatePWM1A(val);
			break;
		}
		case 3:
		{
			if(!checkBit(toneStatus,3))
			{
				sbi(toneStatus,3);
				initTone(PWM1B);
			}
			_updatePWM1B(val);
			break;
		}		
	}
}

/**************************************************************
/ Mode: CTC waveform mode
/ Clock: F_OSC / 256
/*************************************************************/
void initTone(uint8_t mode)
{
	switch(mode)
	{
		case PWM0A:
		{
			DDRB |= (1<<2);
			sbi(TCCR0A,COM0A0);
			sbi(TCCR0A,WGM01);
			sbi(TCCR0B,CS02); 
			break;
		}
		case PWM0B:
		{
			DDRA |= (1<<7);
			sbi(TCCR0A,COM0B0);
			sbi(TCCR0A,WGM01);
			sbi(TCCR0B,CS02); 
			break;
		}
		case PWM1A:
		{
			DDRA |= (1<<6);
			sbi(TCCR1A,COM1A0);
			sbi(TCCR1B,WGM12);
			sbi(TCCR1B,WGM13);
			sbi(TCCR1B,CS12); 
			ICR1 = 0xFF;
			break;
		}
		case PWM1B:
		{
			DDRA |= (1<<5);
			sbi(TCCR1A,COM1B0);
			sbi(TCCR1B,WGM12);
			sbi(TCCR1B,WGM13);
			sbi(TCCR1B,CS12);
			ICR1 = 0xFF; 
			break;
		}
	}
}
