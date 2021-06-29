//www.elegoo.com
//2016.12.08

#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define RED 5
#define GREEN 6
#define BLUE 7


SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
int buzzer = 13;//the pin of the active buzzer
int redValue;
int greenValue;
int blueValue;

void setup()
{
 Serial.begin(9600);
 pinMode(buzzer,OUTPUT);
 pinMode(RED, OUTPUT);
 pinMode(GREEN, OUTPUT);
 pinMode(BLUE, OUTPUT);
 digitalWrite(RED, HIGH);
 digitalWrite(GREEN, LOW);
 digitalWrite(BLUE, LOW);
}

void loop()
{
 a=sr04.Distance();
 Serial.print(a);
 Serial.println("cm");
 #define delayTime 0

 redValue = 255;
 greenValue = 255;
 blueValue = 255;
 
 digitalWrite(buzzer,LOW);
 
 if (a < 30)
    {
    digitalWrite(buzzer,HIGH);
    analogWrite(RED, redValue);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 0);
    }

 if (a >= 30 and a < 80)
    {
    digitalWrite(buzzer,LOW);
    analogWrite(RED, redValue);
    analogWrite(GREEN, 150);
    analogWrite(BLUE, 0);
    }

 if (a >= 60)
    {
    digitalWrite(buzzer,LOW);
    analogWrite(RED, 0);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, 0);
    }
 
 }
