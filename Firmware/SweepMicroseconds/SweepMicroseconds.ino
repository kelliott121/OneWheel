/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int us = 0;    // variable to store the servo position

void setup() {
  myservo.attach(5, 500, 2500);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (us = 0; us <= 100; us += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.writeMicroseconds(1500 + us);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (us = 100; us >= -100; us -= 1) { // goes from 180 degrees to 0 degrees
    myservo.writeMicroseconds(1500 + us);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (us = -100; us >= 0; us += 1) { // goes from 180 degrees to 0 degrees
    myservo.writeMicroseconds(1500 + us);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

