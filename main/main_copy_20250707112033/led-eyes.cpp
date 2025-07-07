#include "led-eyes.h"

CRGB leds[NUM_LEDS];
#define DATA_PIN 5
extern bool eyesOn;


void setupLeds() {
    Serial.begin(115200);  // Pour debug
    Serial.println("Initialisation des LEDs...");
    
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.clear();
    FastLED.show();
    
    Serial.println("LEDs initialisées et éteintes.");
}

void updateLeds() {
    if (!eyesOn) return;  // ne rien faire si les yeux sont désactivés

    effetRegard();
    delay(random(3000, 7000));
    clignement({4, 5, 10, 11}, CRGB::Green, CRGB::White);
}


void effetRegard() {
    if (!eyesOn) return;  // Ne fait rien si les yeux doivent être éteints

    Serial.println("Les yeux s'allument...");
    
    fill_solid(leds, NUM_LEDS, CRGB::White); // Fond blanc au lieu de noir
    std::initializer_list<int> yeux = {4, 5, 10, 11};
    std::initializer_list<int> pupille = {5, 10};

    for (int eye : yeux) {
        leds[eye] = CRGB(0, 150, 0);  // Vert foncé pour les yeux
    }
    for (int pupil : pupille) {
        leds[pupil] = CRGB(0, 255, 0);  // Vert clair pour la pupille
    }

    FastLED.show();
}


void clignement(std::initializer_list<int> eyes, CRGB eyeColor, CRGB backgroundColor) {
    for (int i = 0; i < 2; i++) {
        for (int b = 50; b >= 0; b -= 10) {
            fillEyes(eyes, eyeColor, backgroundColor, b);
            delay(40);
        }
        delay(random(100, 500));
        for (int b = 0; b <= 50; b += 10) {
            fillEyes(eyes, eyeColor, backgroundColor, b);
            delay(40);
        }
    }
}

void fillEyes(std::initializer_list<int> eyes, CRGB eyeColor, CRGB backgroundColor, int brightness) {
    fill_solid(leds, NUM_LEDS, backgroundColor); // Toutes les LED inactives en blanc
    for (int eye : eyes) {
        leds[eye] = eyeColor; // Seules les LED des yeux prennent la couleur verte
    }
    FastLED.setBrightness(brightness);
    FastLED.show();
}

void eteindreYeux() {
    Serial.println("Extinction des LEDs...");
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(100);  
    FastLED.clear();
    FastLED.show();
    delay(100);  // Ajout d'une pause pour s'assurer que l'extinction est bien prise en compte

    pinMode(DATA_PIN, OUTPUT);
    digitalWrite(DATA_PIN, LOW);
    
    Serial.println("LEDs devraient être éteintes.");
}

void allumerYeux() {
    effetRegard();  // alias vers ta fonction existante
}


void debugFastLED() {
    Serial.println("État actuel des LEDs :");
    for (int i = 0; i < NUM_LEDS; i++) {
        Serial.print("LED ");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(leds[i].r);
        Serial.print(",");
        Serial.print(leds[i].g);
        Serial.print(",");
        Serial.print(leds[i].b);
        Serial.println();
    }
}
#define FastLED_show FastLED.show(); debugFastLED();
