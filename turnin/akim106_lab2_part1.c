/*	Author: akim106
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

// Part 1 - Garage door sensor
int main(void) { 
    DDRA = 0x00; PORTA = 0xFF; // Port A becomes inputs
    DDRB = 0xFF; PORTB = 0x00; // Port B becomes outputs init 0
    unsigned char tmpB = 0x00;
    unsigned char tmpA = 0x00; // Temporary variables to hold B and A
    while (1) {
      //Read Input
      tmpA = PINA & 0x03;
      //Perform computation
      if (tmpA == 0x01) { // Sets tmpB to bbbbbbb1
        tmpB = (tmpB & 0xFE) | 0x01;
      } else {            // Sets tmpB to bbbbbbb0
        tmpB = (tmpB & 0xFE) | 0x00;
      }
      //Write output
      PORTB = tmpB;
    }
    return 0;
}
