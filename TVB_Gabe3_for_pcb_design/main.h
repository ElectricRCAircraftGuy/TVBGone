#include <avr/pgmspace.h>
#include <Arduino.h> //GS edit


// The TV-B-Gone for Arduino can use either the EU or the NA database of POWER CODES
// EU is for Europe, Middle East, Australia, New Zealand, and some countries in Africa and South America
// NA is for North America, Asia, and the rest of the world not covered by EU

// Two regions!
#define NA 1 //set by a HIGH on REGIONSWITCH pin
#define EU 0 //set by a LOW on REGIONSWITCH pin

// What pins do what
//#define DBG 12
//#define LED 13
//#define IRLED 3
//#define TRIGGER 2
//#define REGIONSWITCH 5
//Gabriel Staples's edits of the above:
const byte DBG = 12; //debug pin
const byte LED = 13; //LED 13
const byte IRLED = 3; //the IR LED 
const byte TRIGGER = 2; //the button pin; [make 3 so that the button can easily be soldered straight to 3 and GND]<--NEVERMIND!!! This creates other complications,
                        //                since the TVBGone code uses Timer2 & PWM outputs on some IR codes; so...keep the TRIGGER (button) on Pin 2 afterall...
                        //[NO LONGER APPLIES, SEE ABOVE] IMPORTANT: BY CHANGING THE TRIGGER FROM PIN 2 TO PIN 3 I ALSO HAD TO EDIT the attachInterrupt and detachInterrupt
                        //commands in the sleepNow() function in the primary .ino file.
const byte REGIONSWITCH = 5; //HIGH (1) = NA, LOW (0) = EU; Pin 5 (REGIONSWITCH) is HIGH (via in input pullup resistor) for North America, or wired to ground for Europe.
//const byte EXTRA_GND_PIN = 4; //make pin 4 an extra ground, so that the button can to from 2 to 4 easily instead

// Lets us calculate the size of the NA/EU databases
#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)));

// set define to 0 to turn off debug output
#define DEBUG 0
#define DEBUGP(x) if (DEBUG == 1) { x ; }

// Shortcut to insert single, non-optimized-out nop
#define NOP __asm__ __volatile__ ("nop")

// Tweak this if neccessary to change timing
#define DELAY_CNT 25

// Makes the codes more readable. the OCRA is actually
// programmed in terms of 'periods' not 'freqs' - that
// is, the inverse!
#define freq_to_timerval(x) (F_CPU / 8 / x - 1)

// The structure of compressed code entries
struct IrCode {
  uint8_t timer_val;
  uint8_t numpairs;
  uint8_t bitcompression;
  uint16_t const *times;
  uint8_t const*codes;
};
