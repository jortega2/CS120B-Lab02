/*	Author: jorte057
 *      Partner(s) Name: none 
 *	Lab Section: 022
 *	Assignment: Lab 2 Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //configre port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; //configure pport B's 8 pins as outputs, initialize to 00s
	unsigned char tmpA = 0x00; //Temporary variable to hold the value of B
	unsigned char tmpB = 0x00; //Temporary variable to hold the value of A
   /* Insert your solution below */
    while (1) {
	//1) Read input
	tmpA = PINA & 0x03;
	//if PA1PA0 = 01,set PB0 = 1  else = 0 
	if (tmpA == 0x01) {
		tmpB = (tmpB & 0xFE) | 0x01; // Set tmpB to bbbbbbb1
	}else{
		tmpB = (tmpB & 0xFE) | 0x00; // sets tmpB to bbbbbbb0
	}
	//write output
	PORTB = tmpB;
    }
    return 1;
}
