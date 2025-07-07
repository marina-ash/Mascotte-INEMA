#include "led-eyes.h"
#include "site-web.h"
#include "servo.h"

void setup() {
    Serial.begin(115200);
    delay(1000);  // Laisse le temps au port série de s'initialiser
    
    setupLeds();
    setupWebServer();
    setupServos();
}

void loop() {

    // Gestion des requêtes du serveur web
    server.handleClient();
    updateLeds();

   
}
