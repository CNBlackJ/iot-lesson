#include "FastLED.h"

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
  for(int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB::Blue;
  }
  FastLED.show();
}