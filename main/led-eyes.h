#ifndef LED_EYES_H
#define LED_EYES_H

#include <FastLED.h>
#include <initializer_list>
extern bool eyesOn;
#define NUM_LEDS 16
extern CRGB leds[NUM_LEDS]; // Déclaration des LEDs, la définition doit être ailleurs

// Déclaration des fonctions (pas de code ici)
void setupLeds();
void updateLeds();
void effetRegard();
void clignement(std::initializer_list<int> eyes, CRGB eyeColor, CRGB backgroundColor);
void fillEyes(std::initializer_list<int> eyes, CRGB eyeColor, CRGB backgroundColor, int brightness);


#endif
