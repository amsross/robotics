# Arduino Nano Motor Control

## Parts List

* [Arduino Nano V3.0 with ATMEGA328P Module](https://smile.amazon.com/gp/product/B071JBYDGM)
* [HC-SR04 Ultrasonic Sensor Distance Module](https://smile.amazon.com/gp/product/B01MA4O5G5)
* [L298N Motor Drive Controller Board](https://smile.amazon.com/gp/product/B06X9D1PR9)
* [3-6V DC Gear Motors with Wheels](https://smile.amazon.com/gp/product/B072HRR8W4)
* [USB-to-Mini-B Cable](https://smile.amazon.com/dp/B00NH13S44/)
* [Jumper Wires](https://smile.amazon.com/dp/B072L1XMJR)
* [Mini Breadboards](https://smile.amazon.com/gp/product/B01EV6SBXQ)
* [AA batteries](https://smile.amazon.com/gp/product/B00NTCH52W)
* [4xAA Battery Holders](https://smile.amazon.com/gp/product/B077C1QGC7)
* [Arduino Web IDE](https://create.arduino.cc)

## Gotchas
1. Because I used a Nano with a different USB module than the official Nano, I needed to download drivers for it.  ([windows](assets/CH341SER.zip) [linux](assets/CH341SER_LINUX.zip) [mac](assets/CH341SER_MAC.zip))

2. I initially started with a USB-to-Mini-B cable that was not capable of transmitting data (only power). It took me a while to figure this out.

## Setup

{% include image.html file="assets/img/diagram_bb.png"
  alt="Wiring Diagram"
  caption="Wiring Diagram"
  %}

## Code

### Libraries

* [L298N](https://github.com/AndreaLombardo/L298N)
* [HCSR04](https://github.com/jeremylindsayni/Bifrost.Arduino.Sensors.HCSR04)

### Motors

```cpp
#include <L298N.h>

// Motor A
#define ENA 10 // D10
#define IN1 9  // D9
#define IN2 8  // D8

// Motor B
#define IN3 7  // D7
#define IN4 6  // D6
#define ENB 5  // D5

// create both motor instances
L298N motorA(ENA, IN1, IN2);
L298N motorB(ENB, IN3, IN4);

void setup() {
  // set the motor speed between 0 and 255
  motorA.setSpeed(255);
  motorB.setSpeed(255);
}

void forward() {
  motorA.forward();
  motorB.forward();
}

void backward() {
  motorA.backward();
  motorB.backward();
}

void left() {
  motorA.forward();
  motorB.backward();
}

void right() {
  motorA.backward();
  motorB.forward();
}

void loop() {
  forward();
  delay(2000);
  backward();
  delay(2000);
  left();
  delay(2000);
  right();
  delay(2000);
}
```

### Sensor

```cpp
#include <hcsr04.h>

#define TRIG 12
#define ECHO 13

// TRIG, ECHO, MIN_RANGE, MAX_RANGE
HCSR04 sensorA(TRIG, ECHO, 20, 4000);

void setup(){
  Serial.begin(9600);
}

void loop() {
  Serial.println(sensorA.distanceInMillimeters());
  delay(250);
}
```

#### References
* [Arduino Nano Pinout](http://www.pighixxx.com/test/wp-content/uploads/2014/11/nano.png)
* [Controlling DC Motors with the L298N Dual H-Bridge and an Arduino](https://dronebotworkshop.com/dc-motors-l298n-h-bridge/)
* [How to Build an Arduino Self-balancing Robot](https://create.arduino.cc/projecthub/zac-jackson/how-to-build-an-arduino-self-balancing-robot-46d992)
* [Tutorial – L298N Dual Motor Controller Modules and Arduino](http://tronixstuff.com/2014/11/25/tutorial-l298n-dual-motor-controller-modules-and-arduino/)
