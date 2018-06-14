#include <Arduino.h>

int ANALOG_PIN = A5;
int val = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
  val = analogRead(ANALOG_PIN);
  Serial.println(val);
  delay(1000);
}