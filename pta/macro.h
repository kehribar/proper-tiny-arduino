/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#ifndef MACROS
#define MACROS
 
#define sbi(reg,bit) (reg |= (1<<bit))
#define cbi(reg,bit) (reg &= ~(1<<bit))
#define checkBit(reg,bit) (reg&(1<<bit))

#endif
