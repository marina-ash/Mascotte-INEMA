#ifndef LED_EYES_H
#define LED_EYES_H

#include <FastLED.h>
#include <initializer_list>

#define NUM_LEDS 16
#define DATA_PIN 5

extern CRGB leds[NUM_LEDS];
extern bool eyesOn;

void setupLeds();
void effetRegard();
void clignement(std::initializer_list<int> eyes, CRGB eyeColor, CRGB backgroundColor);
void fillEyes(std::initializer_list<int> eyes, CRGB eyeColor, CRGB backgroundColor, int brightness);
void eteindreYeux();

#endif