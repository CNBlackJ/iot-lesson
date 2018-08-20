#include "FastLED.h"

<<<<<<< HEAD
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
=======
#define NUM_LEDS 16
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
void loop()
{
  int val = analogRead(A0);
  int numLedsToLight = map(val, 0, 1023, 0, NUM_LEDS);

  FastLED.clear(); // 清除LED灯的现存状态
  for(int led = 0; led < numLedsToLight; led++) {
    leds[led] = CRGB::Blue;
  }
  FastLED.show();
>>>>>>> 881d9d39f2511d49c8620373b4c8bea45116f579
}