#include "led-eyes.h"
#include "site-web.h"
#include "servo.h"

void setup() {
    Serial.begin(115200);

    // Initialisation des modules
    setupLeds();       // Initialisation des LEDs
    setupWebServer();  // Initialisation du serveur web
    setupServos();     // Initialisation des servomoteurs
}

void loop() {
    // Gestion des LEDs
    updateLeds();

    // Gestion des requêtes du serveur web
    server.handleClient();

    // Mouvement des servomoteurs
    moveServos();
}
