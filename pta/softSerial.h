/*
* ----------------------------------------------------------------------------
* “THE COFFEEWARE LICENSE” (Revision 1):
* <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a coffee in return.
* -----------------------------------------------------------------------------
*/

#ifndef SOFT_SERIAL
#define SOFT_SERIAL

/******************************************************************************
/ ----------------------------------------------------------------------------- 
/ Baud rates are predefined for ease of use.
/ ----------------------------------------------------------------------------- 
/ For 1Mhz	-> 9600 bps
/ For 8Mhz	-> 19200 bps
/ For 16Mhz	-> 38400 bps
/ For 20Mhz	-> 115200 bps
/ -------------------- ---------------------------------------------------------
/ TX and RX pins can be configured from the ./pta/elmChan_serial/suart.S file.
/ -----------------------------------------------------------------------------
/ Default TX pin: PORTB.0
/ Default RX pin: PORTB.1
/*****************************************************************************/
#include "./elmChan_serial/suart.h" 
#include "./elmChan_serial/xitoa.h"
#include "digital.h"

#define serialRead() rcvr()

void initSerial();
void xprint(char* tx);

#endif
