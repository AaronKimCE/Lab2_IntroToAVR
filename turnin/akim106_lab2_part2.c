/*      Author: akim106
 *  Partner(s) Name:
 *      Lab Section:
 *      Assignment: Lab #  Exercise #
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

// Part 2 - Parking space sensor
int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Port A becomes inputs
    DDRC = 0xFF; PORTC = 0x00; // Port C becomes outputs init 0
    unsigned char cntavail = 0x00;
    unsigned char tmpA = 0x00; // Temporary variables to hold B and A
    while (1) {
      //Read Input
      tmpA = PINA & 0x0F;
      if (tmpA == 0x00) {// checking spots
        cntavail = 4;  // 4 open
      }
      else if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08) {//3 open
        cntavail = 3;
      }
      else if (tmpA == 0x03 || tmpA == 0x06 || tmpA == 0x0C || tmpA == 0x05 || tmpA == 0x0A || tmpA == 0x09) {// 2 open
        cntavail = 2;
      }
      else if (tmpA == 0x07 || tmpA == 0x0E || tmpA == 0x0B || tmpA == 0x0D ) {// 1 open
        cntavail = 1;
      } else {
        cntavail = 0;  //Lot full
      }
      //Write output
      PORTC = cntavail;
    }
    return 0;
}


