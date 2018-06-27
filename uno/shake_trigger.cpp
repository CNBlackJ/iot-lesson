#include <Arduino.h>

#define SensorLED     13
#define SensorINPUT   3  //Connect the sensor to digital Pin 3 which is Interrupts 1.

unsigned char state = 0;

void blink()
{
  state++;
}

void setup() 
{
    Serial.begin(9600);
    pinMode(SensorLED, OUTPUT);
    pinMode(SensorINPUT, INPUT);
    attachInterrupt(1, blink, FALLING);
}
void loop()
{
    Serial.println(state);
    if(state!=0) {
        state = 0;
        digitalWrite(SensorLED, HIGH);
        delay(500);
    } else {
        digitalWrite(SensorLED,LOW);
    }
}
