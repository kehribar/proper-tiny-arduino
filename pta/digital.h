/*
 * ----------------------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 1):
 * <ihsan@kehribar.me> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a coffee in return.
 * ----------------------------------------------------------------------------
 */
 
#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0

#define digitalWrite(pin,state) state ? (PORTB |= (1<<pin)) : (PORTB &= ~(1<<pin))  
#define pinMode(pin,state) state ? (DDRB |= (1<<pin)) : (DDRB &= ~(1<<pin))
#define digitalRead(pin) (PINB & (1<<pin))


