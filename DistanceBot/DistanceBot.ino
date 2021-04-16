/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
int pos = 0;
int red = 7;
int yellow = 6;
int green = 5;
int buzzer = 3;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  Serial.begin(9600);
  delay(100);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  detect();
  for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    detect();
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 5) {
    myservo.write(pos);
    detect();
    delay(15);
  }
}

void detect() { // constantly outputs HC-SR04 module's distance in serial monitor
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   changeLights();
}

void changeLights(){ // outputs different colored lights based on HC-SR04 module output
  a=sr04.Distance();
  if (a <= 30) {
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, HIGH);
  }
  else if (a > 30 and a < 80) {
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, LOW);
  }
  else if (a > 80) {
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, LOW);
  }
}
