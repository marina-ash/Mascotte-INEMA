#include "servo.h"

Servo servo1;
Servo servo2;

void setupServos() {
    servo1.setPeriodHertz(50);  // Fréquence PWM standard SG90 (50 Hz)
    servo2.setPeriodHertz(50);

    servo1.attach(PIN_SERVO1, 500, 2400); // Calibration (min et max en µs)
    servo2.attach(PIN_SERVO2, 500, 2400);
}

void moveServos() {
    // Exemple animation aller-retour entre 0° et 50°
    for (int angle = 0; angle <= 50; angle++) {
        servo1.write(angle);
        servo2.write(50 - angle);
        delay(30);
    }
    for (int angle = 50; angle >= 0; angle--) {
        servo1.write(angle);
        servo2.write(50 - angle);
        delay(30);
    }
}

void servoPositionDebout() {
    // Exemple position "debout" (ajuste selon tes besoins)
    servo1.write(0);
    servo2.write(50);
}

void servoPositionAssis() {
    // Exemple position "assis" (ajuste selon tes besoins)
    servo1.write(50);
    servo2.write(0);
}
