/*

  MSE 2202 Example 1
  Language: Arduino
  Author: Michael Naish
  Date: 23/01/26

  This code will create a "sweep" of LEDs moving in sequence. For full effect, the number of LEDs in the sweep
  pattern should be less than the total number of LEDs

  Rev 1 - Initial version 
  
*/

const int ledPins[] = {
  4, 16, 17, 18};                          // select the digital pins for the LEDs
const int numberLEDs = 
  sizeof(ledPins) / sizeof(ledPins[0]);    // number of LEDs in display
int sweep = 3;                             // number of LEDs in sweep pattern
int state = 0;                             // current state of LEDs
unsigned long prevMillis = 0;              // start time for delay cycle, in milliseconds
unsigned long curMillis = 0;               // current time, in milliseconds
unsigned long rate = 300;                  // time delay for switching effect

void setup() {
 // set all LED pins as outputs
  for (int i = 0; i < numberLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  curMillis = millis();                          // get the current time in milliseconds
  if(curMillis - prevMillis > rate) {            // check to see if elapsed time matched the desired delay
    prevMillis = curMillis;                      // update the start time for the next delay cycle
    if(state <= numberLEDs && state > 0) {       // turn on LEDs for states 1 to numberLEDs 
      digitalWrite(ledPins[state-1], HIGH);      // account for zero index of ledPins
    }
    if(state >= sweep)                           // once number of LEDs in sweep has been turned on, start
    {                                            // turning off trailing LEDs
      digitalWrite(ledPins[state-sweep-1], LOW); // account for zero index of ledPins
    }
    if(state == 0)                               // clear last LED turned on from previous state sequence
    {
      digitalWrite(ledPins[numberLEDs-1], LOW);  // account for zero index of ledPins
    }
    state++;                                     // shift to next state
    if(state == numberLEDs+sweep)                // if past last state (with zero index)
       state = 0;                                // reset state to zero to restart sequence
  }
}
