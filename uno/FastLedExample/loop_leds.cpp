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
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(200);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}