#include <Arduino.h>
#include <ESP32Servo.h>  // Nouvelle bibliothèque utilisée

Servo servo1;
Servo servo2;

// Broches pour l'ESP32
const int servo1Pin = 18;
const int servo2Pin = 19;

void setupServos() {
    servo1.attach(servo1Pin);
    servo2.attach(servo2Pin);

    // Position initiale
    servo1.write(30);
    servo2.write(30);
}

void moveServos() {
    // Monter (ou descendre selon montage)
    for (int angle = 0; angle <= 30; angle++) {
        servo1.write(angle);
        servo2.write(30 - angle);
        delay(20);
    }

    // Retour
    for (int angle = 30; angle >= 0; angle--) {
        servo1.write(angle);
        servo2.write(30 - angle);
        delay(20);
    }
}
