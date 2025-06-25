#include "led-eyes.h"
#include "site-web.h"
#include "servo.h"

void setup() {
    Serial.begin(115200);
    setupLeds();       // Initialisation des LEDs
    setupWebServer();  // Serveur Web
    setupServos();     // Servomoteurs (à adapter selon tes besoins)
}

void loop() {
    server.handleClient();  // Webserver actif
    // Pas besoin de boucle updateLeds automatique si contrôle via site
}
