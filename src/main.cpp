#include <Arduino.h>

const int pinSensor = D3;
const int pinLed = D4;
int ismotion;
 
void setup() {
  Serial.begin(9600); 
  pinMode (pinSensor, INPUT);
  pinMode (pinLed, OUTPUT);
}
void loop() {
  ismotion = digitalRead(pinSensor);
  if(ismotion == 1){                
    digitalWrite(pinLed,HIGH);      
    Serial.println("Detectived");    
  }
  else{
    noTone(pinLed); 
    Serial.println("Not Detectived"); 
  }
}