#include <Arduino.h>

const int pinSensor = 10;
const int pinLed = 9;
int ismotion;
 
void setup() {
  Serial.begin(9600); 
  pinMode (pinSensor, INPUT);
  pinMode (pinLed, OUTPUT);
}
void loop() {
  ismotion = digitalRead(pinSensor);
  Serial.println(ismotion);
  if(ismotion == 1){                
    digitalWrite(pinLed,HIGH);      
    Serial.println("Detectived");    
  }
  else{
    noTone(pinLed); 
    Serial.println("Not Detectived"); 
  }
}