/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */
 
#ifndef PWM_T84
#define PWM_T84

#include <avr/io.h>
#include "macro.h"

#define PWM0A 0 // PWM #0
#define PWM0B 1 // PWM #1
#define PWM1A 2 // PWM #2
#define PWM1B 3 // PWM #3

#define updatePWM0A(value) (OCR0A = value);
#define updatePWM0B(value) (OCR0B = value);
#define updatePWM1A(value) (OCR1A = value);
#define updatePWM1B(value) (OCR1B = value);

void initPWM(uint8_t mode);
void analogWrite(uint8_t ch, uint8_t val);

#endif
