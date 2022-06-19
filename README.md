# I2C Temperature Sensor (LM75A) Library for Arduino
[![Build Status](https://travis-ci.org/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library.svg?branch=master)](https://travis-ci.org/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/4264aac910e4471584e5af61e65497d4)](https://www.codacy.com/manual/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=QuentinCG/Arduino-LM75A-Temperature-Sensor-Library&amp;utm_campaign=Badge_Grade) [![License: MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library/blob/master/LICENSE.md) [![Donate](https://img.shields.io/badge/Donate-PayPal-blue.svg)](https://paypal.me/QuentinCG)

## What is it

This library (with example) is designed to be integrated in projects using LM75A sensors to get temperature with most Arduino boards.

You'll be able to use between 1 and 8 LM75A sensor on a single board (or up to 16 if your board handles multiple I2C).

<img src="device.png" width="300">

## How to install

1) Download <a target="_blank" href="https://github.com/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library/releases/download/1.2.0/LM75A_v1_2_0.zip">latest release</a>

2) On your Arduino IDE, click "Sketch" menu and then "Include Library > Add .ZIP Libraries"

3) You can now use the library for your project or launch an example ("File > Examples")

## How to connect the sensor to your Arduino

|LM75A sensor|Arduino                                  |
|--------    |--------                                 |
|VCC         |3.3V                                     |
|GND         |GND                                      |
|SDA         |A4 (SDA)                                 |
|SCL         |A5 (SCL)                                 |
|A0          |GND (or VCC to increase I2C address of 1)|
|A1          |GND (or VCC to increase I2C address of 2)|
|A2          |GND (or VCC to increase I2C address of 4)|
|OS          |None                                     |

<img src="schematics.png" width="400">

(Note: SDA and SCL of your board may change depending on your Arduino board)

## Examples

Three examples are provided with this library:

### Show temperature in degrees and fahrenheit every second (1 sensor)

<a target="_blank" href="https://github.com/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library/blob/master/examples/LM75A_ShowTemperature/LM75A_ShowTemperature.ino">Link to source code</a>

### Show temperature in degrees and fahrenheit every second (2 sensors in same I2C network)

<a target="_blank" href="https://github.com/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library/blob/master/examples/LM75A_ShowTemperature2Sensors/LM75A_ShowTemperature2Sensors.ino">Link to source code</a>

### Show temperature in degrees and fahrenheit every second (2 sensors in different I2C network)

<a target="_blank" href="https://github.com/QuentinCG/Arduino-LM75A-Temperature-Sensor-Library/blob/master/examples/LM75A_MultiI2cWire/LM75A_MultiI2cWire.ino">Link to source code</a>

## Interesting forks

- <a target="_blank" href="https://github.com/Stov1k/ESPHome-LM75A-Temperature-Sensor-Component">Fork of this Arduino library but adapted to ESPHome module.</a>

## License

This project is under MIT license. This means you can use it as you want (just don't delete the library header).

## Contribute

If you want to add more examples or improve the library, just create a pull request with proper commit message and right wrapping.

## Contributors

- Thank you <a target="_blank" href="https://github.com/andrzejboro">andrzejboro</a> for your help on a bug for negative temperature.
- Thank you <a target="_blank" href="https://github.com/damianjwilliams">damianjwilliams</a> for your idea and help on multi I2C handling.
- Thank you <a target="_blank" href="https://github.com/BirdAPI">BirdAPI</a> for your idea to add a raw contructor using directly the I2C address.
