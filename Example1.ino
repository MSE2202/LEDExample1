/*

  MSE 2202 Example 1
  Language: Arduino
  Author: Michael Naish
  Date: 23/01/26

  Rev 1 - Initial version 
  
*/

const int ledPins[] = {
  4, 16, 17, 18};                          // select the digital pins for the LEDs
const int numberLEDs = 
  sizeof(ledPins) / sizeof(ledPins[0]);    // number of LEDs in display
int state = 0;                             // current state of LEDs
int sweep = 3;                             // number of LEDs in pattern
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
  curMillis = millis();                     // get the current time in milliseconds
  if(curMillis - prevMillis > rate) {       // check to see if elapsed time matched the desired delay
    prevMillis = curMillis;                 // update the start time for the next delay cycle
    if(state < numberLEDs) {
      digitalWrite(ledPins[state], HIGH);
    }
    if(state >= sweep)
    {
      digitalWrite(ledPins[state-sweep], LOW);
    }
    state++;
    if(state == numberLEDs+sweep)
       state = 0;
  }
}
