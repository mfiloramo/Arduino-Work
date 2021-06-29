#include "SR04.h"
#define TRIG_PIN 4
#define ECHO_PIN 3
#include <LiquidCrystal.h>
#include <Servo.h>
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
Servo myservo;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Target Distance:");
}

void loop() {
  myservo.attach(5);
  a=sr04.Distance();
  lcd.setCursor(0, 1);
  lcd.print(a);
  delay(10);
  lcd.print("    ");

  if (a <= 180) {
  myservo.write(a);
  }
}
