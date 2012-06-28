/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "digital.h"
#include "analog.h"

/*
	Todo: 
		* analogWrite(); // very bad name for the PWM function.
		* servo stuff
			- attachServo
			- detachServo
			- goTo(degree);
		* setupADC(); // Voltage reference and prescale setting.
		* setup timer
		* uart library
		* i2c library
		* spi library
		* pin change interrupt example
		* timer interrupt example
*/
