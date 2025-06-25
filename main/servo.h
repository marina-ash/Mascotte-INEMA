#ifndef SERVO_H
#define SERVO_H

#include <ESP32Servo.h>

#define PIN_SERVO1 18  // Broche du premier servo
#define PIN_SERVO2 19  // Broche du deuxième servo

extern Servo servo1;
extern Servo servo2;

void setupServos();
void moveServos();  // Fonction pour animer les servos

#endif
