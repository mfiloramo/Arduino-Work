#include <Stepper.h>
#include <Servo.h>
//#include <elapsedMillis.h>

const int stepsPerRevolution = 10;  // change this to fit the number of steps per revolution
const int rolePerMinute = 1900;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

Stepper myStepper_1(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper_2(stepsPerRevolution, 4, 6, 5, 7);
Servo myservo;

//elapsedMillis timeElapsed;
//unsigned int interval = 6000;

int pos = 0;

void setup() {
  myStepper_1.setSpeed(rolePerMinute);
  myStepper_2.setSpeed(rolePerMinute);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  myStepper_1.step(stepsPerRevolution);
  myStepper_2.step(-stepsPerRevolution);
  
//    for (pos = 0; pos <= 120; pos +=1) {
//    myservo.write(pos);
//    delay(10);
//  }
//    
//    for (pos = 120; pos >= 0; pos -= 1) {
//    myservo.write(pos);
//    delay(10);
//  }
}
