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
    DDRA = 0x00; PORTA = 0xFF; // Port A becomes inputs
    DDRC = 0xFF; PORTC = 0x00; // Port C becomes outputs init 0
    unsigned char cntavail = 0;
    unsigned char tmpA = 0x00; // Temporary variables to hold C and A
    while (1) {
      //Read Input & Reset count of cars
      cntavail = 0;
      tmpA = PINA & 0x0F;

      if ((tmpA & 0x01) != 0x01) { //Check first spot
       cntavail = cntavail + 1;
      }
      if ((tmpA & 0x02) != 0x02) { //Check second spot
       cntavail = cntavail + 1;
      }
      if ((tmpA & 0x04) != 0x04) { //Check third spot
       cntavail = cntavail + 1;
      }
      if ((tmpA & 0x08) != 0x08) { //Check fourth spot
       cntavail = cntavail + 1;
      }
      //Write output
      PORTC = cntavail;
    }
    return 0;
}
