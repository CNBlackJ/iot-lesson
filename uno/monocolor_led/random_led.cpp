#include <Arduino.h>

int START_PIN = 2;
int END_PIN = 7;

int random_pin;

void setup() {
    for (int i = START_PIN; i <= END_PIN; i++) {
			pinMode(i, OUTPUT);
		}
}

void loop() {
		// get random pin
		random_pin = START_PIN + (rand() % static_cast<int>(END_PIN - START_PIN + 1));
		digitalWrite(random_pin, HIGH);
		delay(200);
		digitalWrite(random_pin, LOW);
    delay(100);
}