#include <Arduino.h>

int ledPin = 9;

void setup() {
    pinMode(9, OUTPUT);
}

void loop() {
    int flag = 0;
    int sped = 5;
    int maxVal = 250;
    for (int fadeValue = 0; fadeValue <= maxVal;) {
        analogWrite(ledPin, fadeValue);
        delay(60);
        if (fadeValue >= maxVal) {
            flag = 1;
        }
        if (fadeValue <= 0) {
            flag = 0;
        }
        if (flag == 1) {
            fadeValue -= sped;
        } else {
            fadeValue += sped;
        }
    }
}