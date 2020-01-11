/*	Author: jorte057
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
	DDRC = 0xFF; PORTC = 0x00; //configure pport B's 8 pins as outputs, initialize to 00s
	unsigned char tmpA = 0x00; //Temporary variable to hold the value of A
	unsigned char cntavail = 0x00; //value to be written to C
	unsigned char parking_spaces = 0x04; //number of parking spots 
   /* Insert your solution below */
    while (1) {
	// Read input
	tmpA = PINA & 0x0F;
	
	//filter correct values from input, e.g. 0111 is read as 3 parking spaces not 7 parking spaces
	cntavail = parking_spaces - (((tmpA & 0x08) && 1) + ((tmpA & 0x04) && 1) + ((tmpA & 0x02) && 1) + ((tmpA & 0x01) && 1));
	
	//write output
	//
	//Swet PC7 to 1 if lot is full
	if (cntavail == 0x00){
		PORTC = (PORTC & 0x7F) | 0x80;
		PORTC = (PORTC & 0xF0) | cntavail;
	}
	//Write available parking spots to PC3...PC0
	else {
		PORTC = (PORTC & 0xF0) | cntavail;
	} 
    }
    return 1;
}
