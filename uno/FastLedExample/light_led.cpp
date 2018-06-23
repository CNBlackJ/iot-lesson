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
  leds[0] = CRGB::White;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}