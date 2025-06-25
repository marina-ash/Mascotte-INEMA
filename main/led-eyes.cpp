#include "led-eyes.h"

CRGB leds[NUM_LEDS];
bool eyesOn = false;

void setupLeds() {
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(128); // Luminosité globale à 50% (0-255)
    FastLED.clear();
    FastLED.show();
}

void effetRegard() {
    if (!eyesOn) return;

    fill_solid(leds, NUM_LEDS, CRGB::White);       // Fond blanc
    for (int i : {4, 5, 10, 11}) leds[i] = CRGB(0, 150, 0);  // Yeux verts foncés
    for (int i : {5, 10}) leds[i] = CRGB(0, 255, 0);         // Pupilles vert clair

    FastLED.show();
}

void clignement(std::initializer_list<int> eyes, CRGB eyeColor, CRGB backgroundColor) {
    for (int i = 0; i < 2; i++) {
        for (int b = 50; b >= 0; b -= 10) {
            fillEyes(eyes, eyeColor, backgroundColor, b);
            delay(40);
        }
        delay(100);
        for (int b = 0; b <= 50; b += 10) {
            fillEyes(eyes, eyeColor, backgroundColor, b);
            delay(40);
        }
    }
}

void fillEyes(std::initializer_list<int> eyes, CRGB eyeColor, CRGB backgroundColor, int brightness) {
    fill_solid(leds, NUM_LEDS, backgroundColor);
    for (int eye : eyes) leds[eye] = eyeColor;

    brightness = constrain(brightness, 0, 255);
    FastLED.setBrightness(brightness);
    FastLED.show();
}

void eteindreYeux() {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(100);
    FastLED.clear();
    FastLED.show();
    eyesOn = false;
}

// Nouvelles fonctions appelées par la web interface

void allumerYeux() {
    eyesOn = true;
    effetRegard();
}

void eteindreYeuxWeb() {
    eyesOn = false;
    eteindreYeux();
}
