/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef PTA
#define PTA

#include <stdio.h> 
#include <string.h>
#include <avr/io.h>
#include <stdlib.h> 
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "macro.h"
#include "digital.h"
#include "analog.h"
#include "softSerial.h"
#include "onewire.h"

#if defined(__AVR_ATtiny84__)
	#include "pwm_t84.h"
	#include "tone_t84.h"
#endif

#endif
