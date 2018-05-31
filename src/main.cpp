#include <Arduino.h>

int START_PIN = 2;
int END_PIN = 7;
int index = 0;

void setup() {
    // put your setup code here, to run once:
    for (int i = START_PIN; i <= END_PIN; i++) {
			pinMode(i, OUTPUT);
		}
}

void loop() {
    // put your main code here, to run repeatedly:
    for (int i = START_PIN; i <= END_PIN; i++) {
			digitalWrite(i, LOW);
		}
    digitalWrite(START_PIN + index, HIGH);
		index = (index + 1) % (END_PIN - START_PIN + 1);
    delay(100);
}