#include "SR04.h"
#include <Servo.h>

#define TRIG_PIN 12
#define ECHO_PIN 11
#define RED 7
#define YELLOW 4
#define GREEN 2

Servo myservo_l;
Servo myservo_r;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

long a;
int buzzer = 12;

void setup() {
   Serial.begin(9600);
   myservo_l.attach(9);
   myservo_r.attach(6);
   pinMode(RED, OUTPUT);
   pinMode(YELLOW, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(buzzer, OUTPUT);
}

void loop() {
  a=sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
   delay(15);

  // Go if the coast is clear
  if (a > 30) {
    myservo_l.write(500);
    myservo_r.write(0);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(buzzer, LOW);
  }

  // Stop and back up if wall is reached
  else if (a <= 30) {
    wait();
    turn();
    }
}

void wait() {
  // Stop and back up
  myservo_l.write(1500);
    myservo_r.write(1500);
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(buzzer, HIGH);
     delay(250);
    myservo_l.write(0);
    myservo_r.write(500);
     delay(250);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(buzzer, LOW);
    myservo_l.write(1500);
    myservo_r.write(1500);
     delay(250);
}

void turn() {
      // Turn left, pause, then record the distance
      myservo_l.write(0);
      myservo_r.write(0);
       delay(400);
      myservo_l.write(1500);
      myservo_r.write(1500);
      int left_dis = a;
       delay(400);
       
      // Turn right, pause, then record the distance
      myservo_l.write(500);
      myservo_r.write(500);
      delay(800);
      myservo_l.write(1500);
      myservo_r.write(1500);
      int rite_dis = a;
      delay(400);
       
      if (left_dis > rite_dis) {
      myservo_l.write(0);
      myservo_r.write(0);
       delay(800);
      }
  }
