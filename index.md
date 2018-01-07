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

{% include image.html file="assets/img/diagram.png"
  alt="Wiring Diagram"
  caption="Wiring Diagram"
  %}

## Libraries

* [L298N](https://github.com/AndreaLombardo/L298N)
* [HCSR04](https://github.com/jeremylindsayni/Bifrost.Arduino.Sensors.HCSR04)

## Code

```cpp
#include <L298N.h>
#include <hcsr04.h>
```

#### References
* [Tutorial – L298N Dual Motor Controller Modules and Arduino](http://tronixstuff.com/2014/11/25/tutorial-l298n-dual-motor-controller-modules-and-arduino/)
* [How to Build an Arduino Self-balancing Robot](https://create.arduino.cc/projecthub/zac-jackson/how-to-build-an-arduino-self-balancing-robot-46d992)
* [Controlling DC Motors with the L298N Dual H-Bridge and an Arduino](https://dronebotworkshop.com/dc-motors-l298n-h-bridge/)
