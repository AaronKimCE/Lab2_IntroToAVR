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

// Part 2 - Parking space sensor
int main(void) { 
    DDRB = 0x00; PORTB = 0xFF; // Port A becomes inputs
    DDRC = 0xFF; PORTC = 0x00; // Port C becomes outputs init 0
    unsigned char cntavail = 0x00;
    unsigned char tmpA = 0x00; // Temporary variables to hold C and A
    while (1) {
      //Read Input & Reset count of cars
      cntavail = 0x00;
      tmpA = PINB;
      if ((tmpA & 0x01) != 0x01 ) {// Checking spot 1
        ++cntavail;  // Incrementing available spots
      }
      if ((tmpA & 0x02) != 0x02 ) {// spot 2
        ++cntavail;
      }
      if ((tmpA & 0x04) != 0x04 ) {// spot 3
        ++cntavail;
      }
      if ((tmpA & 0x08) != 0x08 ) {// spot 4
        ++cntavail;
      }
      //Write output
      PORTC = cntavail;
    }
    return 0;
}
