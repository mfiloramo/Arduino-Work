
#define ENABLE_M1 5
#define ENABLE_M2 8
#define DIRA_M1 3
#define DIRB_M1 4
#define DIRA_M2 6
#define DIRB_M2 7

int i;
 
void setup() {
  //---set pin direction
  pinMode(ENABLE_M1,OUTPUT);
  pinMode(ENABLE_M2,OUTPUT);
  pinMode(DIRA_M1,OUTPUT);
  pinMode(DIRB_M1,OUTPUT);
  pinMode(DIRA_M2,OUTPUT);
  pinMode(DIRB_M2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
//    Serial.println("One way, then reverse");
    digitalWrite(ENABLE_M1,HIGH);
    digitalWrite(ENABLE_M2,HIGH);
    for (i=0;i<5;i++) {
    digitalWrite(DIRA_M1,HIGH);
    digitalWrite(DIRB_M2,HIGH);
//    digitalWrite//one way
    }
    
    }
//    digitalWrite(DIRB,LOW);
//    delay(500);
//    digitalWrite(DIRA,LOW);  //reverse
//    digitalWrite(DIRB,HIGH);
//    delay(500);
//  }
//  digitalWrite(ENABLE,LOW); // disable
//  delay(2000);
//
//  Serial.println("fast Slow example");
//  //---fast/slow stop example
//  digitalWrite(ENABLE,HIGH); //enable on
//  digitalWrite(DIRA,HIGH); //one way
//  digitalWrite(DIRB,LOW);
//  delay(3000);
//  digitalWrite(ENABLE,LOW); //slow stop
//  delay(1000);
//  digitalWrite(ENABLE,HIGH); //enable on
//  digitalWrite(DIRA,LOW); //one way
//  digitalWrite(DIRB,HIGH);
//  delay(3000);
//  digitalWrite(DIRA,LOW); //fast stop
//  delay(2000);
//
//  Serial.println("PWM full then slow");
//  //---PWM example, full speed then slow
//  analogWrite(ENABLE,255); //enable on
//  digitalWrite(DIRA,HIGH); //one way
//  digitalWrite(DIRB,LOW);
//  delay(2000);
//  analogWrite(ENABLE,180); //half speed
//  delay(2000);
//  analogWrite(ENABLE,128); //half speed
//  delay(2000);
//  analogWrite(ENABLE,50); //half speed
//  delay(2000);
//  analogWrite(ENABLE,128); //half speed
//  delay(2000);
//  analogWrite(ENABLE,180); //half speed
//  delay(2000);
//  analogWrite(ENABLE,255); //half speed
//  delay(2000);
//  digitalWrite(ENABLE,LOW); //all done
//  delay(10000);
//}
//   
