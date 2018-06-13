#include <Arduino.h>

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
void setup ()
{
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}
void loop()
{
  int len = 8;
  int array[len] = { 1, 2, 4, 8, 16, 32, 64, 128 };
  for (int i = 0; i < len; i ++) {
    Serial.println(array[i]);
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,array[i]);
    digitalWrite(latchPin,HIGH);
    delay(500);
  }
}