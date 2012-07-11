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

// Sets the desired bit of a register.
#define sbi(reg,bit) (reg |= (1<<bit)) 

// Clears the desired bit of a register.
#define cbi(reg,bit) (reg &= ~(1<<bit)) 

// Returns non-zero if the desired bit of a register is set.
#define checkBit(reg,bit) (reg&(1<<bit)) 

#endif
