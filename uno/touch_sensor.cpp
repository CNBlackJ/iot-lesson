#include <Arduino.h>

int TOUCH_SENSOR_PIN = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(TOUCH_SENSOR_PIN, INPUT);
}

void loop()
{
  int sensorVal = digitalRead(TOUCH_SENSOR_PIN);
  Serial.println(sensorVal);
}
