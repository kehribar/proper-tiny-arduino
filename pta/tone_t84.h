/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef TONE_T84
#define TONE_T84

#include <avr/io.h>
#include "macro.h"

#define PWM0A 0 // PWM #0
#define PWM0B 1 // PWM #1
#define PWM1A 2 // PWM #2
#define PWM1B 3 // PWM #3

#define _updatePWM0A(value) (OCR0A = value);
#define _updatePWM0B(value) (OCR0B = value);
#define _updatePWM1A(value) (OCR1A = value);
#define _updatePWM1B(value) (OCR1B = value);

void initTone(uint8_t mode);
void toneWrite(uint8_t ch, uint8_t val);

#define NOTE_B2	 123
#define NOTE_C3	 131
#define NOTE_CS3	 139
#define NOTE_D3	 147
#define NOTE_DS3	 156
#define NOTE_E3	 165
#define NOTE_F3	 175
#define NOTE_FS3	 185
#define NOTE_G3	 196
#define NOTE_GS3	 208
#define NOTE_A3	 220
#define NOTE_AS3	 233
#define NOTE_B3	 247
#define NOTE_C4	 262
#define NOTE_CS4	 277
#define NOTE_D4	 294
#define NOTE_DS4	 311
#define NOTE_E4	 330
#define NOTE_F4	 349
#define NOTE_FS4	 370
#define NOTE_G4	 392
#define NOTE_GS4	 415
#define NOTE_A4	 440
#define NOTE_AS4	 466
#define NOTE_B4	 494
#define NOTE_C5	 523
#define NOTE_CS5	 554
#define NOTE_D5	 587
#define NOTE_DS5	 622
#define NOTE_E5	 659
#define NOTE_F5	 698
#define NOTE_FS5	 740
#define NOTE_G5	 784
#define NOTE_GS5	 831
#define NOTE_A5	 880
#define NOTE_AS5	 932
#define NOTE_B5	 988
#define NOTE_C6	 1047
#define NOTE_CS6	 1109
#define NOTE_D6	 1175
#define NOTE_DS6	 1245
#define NOTE_E6	 1319
#define NOTE_F6	 1397
#define NOTE_FS6	 1480
#define NOTE_G6	 1568
#define NOTE_GS6	 1661
#define NOTE_A6	 1760
#define NOTE_AS6	 1865
#define NOTE_B6	 1976
#define NOTE_C7	 2093
#define NOTE_CS7	 2217
#define NOTE_D7	 2349
#define NOTE_DS7	 2489
#define NOTE_E7	 2637
#define NOTE_F7	 2794
#define NOTE_FS7	 2960
#define NOTE_G7	 3136
#define NOTE_GS7	 3322
#define NOTE_A7	 3520
#define NOTE_AS7	 3729
#define NOTE_B7	 3951
#define NOTE_C8	 4186
#define NOTE_CS8	 4435
#define NOTE_D8	 4699
#define NOTE_DS8	 4978

#endif
