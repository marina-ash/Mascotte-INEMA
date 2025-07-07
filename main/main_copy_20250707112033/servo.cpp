#include "servo.h"

Servo servo1;
Servo servo2;

void setupServos() {
    servo1.setPeriodHertz(50);  // Fréquence PWM pour le SG90
    servo2.setPeriodHertz(50);

    servo1.attach(PIN_SERVO1, 500, 2400); // Calibration du servo 1
    servo2.attach(PIN_SERVO2, 500, 2400); // Calibration du servo 2
}

void moveServos() {

      // Rotation de 180° à 0°
    for (int pos = 50; pos >= 0; pos -= 1) {
        servo1.write(50-pos);
        servo2.write(pos);
        delay(30);
    }
    // Rotation de 0 à 180°
    for (int pos = 0; pos <= 50; pos += 1) {
        servo1.write(50-pos);
        servo2.write(pos);
        delay(30);
    }


}
