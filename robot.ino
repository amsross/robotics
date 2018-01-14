#include <L298N.h>
#include <hcsr04.h>

#define TRIG 3
#define ECHO 4

// Motor A
#define ENA 10 // D10
#define IN1 9  // D9
#define IN2 8  // D8

// Motor B
#define IN3 7  // D7
#define IN4 6  // D6
#define ENB 5  // D5

// TRIG, ECHO, MIN_RANGE, MAX_RANGE
HCSR04 sensorA(TRIG, ECHO, 20, 4000);

// create both motor instances
L298N motorA(ENA, IN1, IN2);
L298N motorB(ENB, IN3, IN4);

void setup() {
  setSpeed(100);
}

// set the motor speed between 0 and 255
void setSpeed(int speed) {
  motorA.setSpeed(speed);
  motorB.setSpeed(speed);
}

void forward(int i) {
  motorA.forward();
  motorB.forward();
  delay(i);
}

void backward(int i) {
  motorA.backward();
  motorB.backward();
  delay(i);
}

void left(int i) {
  motorA.forward();
  motorB.backward();
  delay(i);
}

void right(int i) {
  motorA.backward();
  motorB.forward();
  delay(i);
}

void loop() {
  if (sensorA.distanceInMillimeters() > 400) {
    forward(250);
  } else if (sensorA.distanceInMillimeters() > 200) {
    left(250);
  } else {
    backward(250);
    right(250);
    backward(250);
    left(250);
  }
}
