#include <Arduino.h>
 
void setup()
{
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  digitalWrite(D4, HIGH);
  digitalWrite(D3, HIGH);
  delay(500);
  digitalWrite(D3, LOW);
  delay(500);
}
