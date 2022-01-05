/*
 * \brief Show temperature in degrees and fahrenheit every second of 2 LM75A connected on DIFFERENT i2C networks (or 'on different i2c wires')
 *
 * IMPORTANT NOTE:
 * To use this example, you need to uncomment "#define USE_TWO_WIRE_FOR_LM75A 1" in LM75A.h IN the library BEFORE importing it (or edit
 *    C:\Users\{YOUR_USERNAME_HERE}\Documents\Arduino\libraries\LM75A\LM75A.h if already imported)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 05 January 2022
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2022 Quentin Comte-Gaz
 * \version 1.2
 */

#include <LM75A.h>

//Define I2C pins for first I2C wire
#define SDA_1 27
#define SCL_1 26

//Define I2C pins for second I2C wire
#define SDA_2 33
#define SCL_2 32

//Create the two I2C Bus instances
TwoWire I2C_one = TwoWire(0);
TwoWire I2C_two = TwoWire(1);

// Create I2C LM75A instance
LM75A lm75a_from_I2C_one(&I2C_one, // I2C network to use
                           false,  // A0 LM75A pin state (connected to ground = false)
                           false,  // A1 LM75A pin state (connected to ground = false)
                           false); // A2 LM75A pin state (connected to ground = false)

LM75A lm75a_from_I2C_two(&I2C_two, // I2C network to use
                           false,  // A0 LM75A pin state (connected to ground = false)
                           false,  // A1 LM75A pin state (connected to ground = false)
                           false); // A2 LM75A pin state (connected to ground = false)

void setup(void)
{
  Serial.begin(9600);

  Serial.println("Initializing both I2C wires");
  I2C_one.begin(SDA_1, SCL_1);
  I2C_two.begin(SDA_2, SCL_2);

  Serial.println("Temperatures from both sensors from 2 different I2C wires will be displayed every second:");
}

void loop()
{
  // Get temperature of both sensors
  float temperature_in_degrees_one = lm75a_from_I2C_one.getTemperatureInDegrees();
  float temperature_in_degrees_two = lm75a_from_I2C_two.getTemperatureInDegrees();

  // Display temperature of first sensor
  if (temperature_in_degrees_one == INVALID_LM75A_TEMPERATURE)
  {
    Serial.println("Error while getting temperature of sensor 1");
  }
  else
  {
    Serial.print("Temperature sensor 1: ");
    Serial.print(temperature_in_degrees_one);
    Serial.print(" degrees (");
    Serial.print(LM75A::degreesToFahrenheit(temperature_in_degrees_one));
    Serial.println(" fahrenheit)");
  }

  // Display temperature of second sensor
  if (temperature_in_degrees_two == INVALID_LM75A_TEMPERATURE)
  {
    Serial.println("Error while getting temperature of sensor 2");
  }
  else
  {
    Serial.print("Temperature sensor 2: ");
    Serial.print(temperature_in_degrees_two);
    Serial.print(" degrees (");
    Serial.print(LM75A::degreesToFahrenheit(temperature_in_degrees_two));
    Serial.println(" fahrenheit)");
  }

  delay(1000);
}
