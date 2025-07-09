#include "led-eyes.h"
#include "site-web.h"
#include "servo.h"

unsigned long lastServoMove = 0;

void setup() {
    Serial.begin(115200);
    delay(1000);

    setupLeds();
    setupWebServer();
    setupServos();
}

void loop() {
    server.handleClient();
    updateLeds();
    moveServos(); 
    
    
}
