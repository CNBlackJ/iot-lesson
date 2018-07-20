#include <Arduino.h>
#include <VarSpeedServo.h> 
 
VarSpeedServo myservo;
 
const int servoPin = 9;
 
void setup() { 
  myservo.attach(servoPin);
  myservo.write(0,255,true);
} 

void loop() {
  myservo.write(180,255,true);
  myservo.write(0,30,true);
} 
