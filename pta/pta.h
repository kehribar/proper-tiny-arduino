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

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h> 

#include "macro.h"
#include "digital.h"
#include "analog.h"
#include "pwm_t84.h"
#include "tone_t84.h"
#include "softSerial.h"

#define delay(value) _delay_ms(value)
#define delayMicroseconds(value) _delay_us(value)

#endif
