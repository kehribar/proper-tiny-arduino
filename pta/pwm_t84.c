/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include "pwm_t84.h"

static uint8_t pwmStatus = 0x00;

void analogWrite(uint8_t ch, uint8_t val)
{
	switch(ch)
	{
		case PWM0A:
		{
			if(!checkBit(pwmStatus,0))
			{
				sbi(pwmStatus,0);
				initPWM(PWM0A);
			}
			updatePWM0A(val);
			break;
		}
		case PWM0B:
		{
			if(!checkBit(pwmStatus,1))
			{
				sbi(pwmStatus,1);
				initPWM(PWM0B);
			}
			updatePWM0B(val);
			break;
		}		
		case PWM1A:
		{
			if(!checkBit(pwmStatus,2))
			{
				sbi(pwmStatus,2);
				initPWM(PWM1A);
			}
			updatePWM1A(val);
			break;
		}
		case PWM1B:
		{
			if(!checkBit(pwmStatus,3))
			{
				sbi(pwmStatus,3);
				initPWM(PWM1B);
			}
			updatePWM1B(val);
			break;
		}		
	}
}

/**************************************************************
/ Mode: 8bit Fast PWM
/ Clock: F_OSC/1
/ Period: 256/F_OSC
/ Update freq: F_OSC/256
/*************************************************************/
void initPWM(uint8_t mode)
{
	switch(mode)
	{
		case PWM0A:
		{
			DDRB |= (1 << 2); 
			sbi(TCCR0A,COM0A1);
			sbi(TCCR0A,WGM00);
			sbi(TCCR0A,WGM01);
			sbi(TCCR0B,CS00);
			break;
		}
		case PWM0B:
		{
			DDRA |= (1 << 7);
			sbi(TCCR0A,COM0B1);
			sbi(TCCR0A,WGM00);
			sbi(TCCR0A,WGM01);
			sbi(TCCR0B,CS00);
			break;
		}
		case PWM1A:
		{
			DDRA |= (1<<6); 
			sbi(TCCR1A,COM1A1);			
			sbi(TCCR1A,WGM10);
			sbi(TCCR1B,WGM12);
			sbi(TCCR1B,CS10); 
			break;
		}
		case PWM1B:
		{
			DDRA |= (1<<5);
			sbi(TCCR1A,COM1B1);			
			sbi(TCCR1A,WGM10);
			sbi(TCCR1B,WGM12);
			sbi(TCCR1B,CS10);
			break;
		}
	}
}
