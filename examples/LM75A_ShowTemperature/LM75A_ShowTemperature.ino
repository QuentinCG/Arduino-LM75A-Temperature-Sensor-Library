/*
 * \brief Show temperature in degrees and fahrenheit every second
 *
 * Note:
 * This library is by default usable in MOST cases.
 * But, if you need for some reason to use two I2C ranges (TwoWire), you will need to:
 *  - Uncomment "#define USE_TWO_WIRE_FOR_LM75A 1" in LM75A.h IN the library BEFORE importing it (or edit
      C:\Users\YOUR_USERNAME\Documents\Arduino\libraries\LM75A\LM75A.h if already imported)
 *  - Create the LM75A class like this (value to fill your need):
 *       ```
         //Define I2C pins
         #define SDA_1 27
         #define SCL_1 26
         // Begin the first wire
         I2C_one.begin(SDA_1, SCL_1, 400000);
         TwoWire I2C_one = TwoWire(0);
         LM75A lm75a_one(&I2C_one,
		                 false,  //A0 LM75A pin state
                         false,  //A1 LM75A pin state
                         false); //A2 LM75A pin state
         // You can do the same with the second wire
         ```
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 27 December 2021
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2021 Quentin Comte-Gaz
 * \version 1.0
 */

#include <LM75A.h>

// Create I2C LM75A instance
LM75A lm75a_sensor(false,  //A0 LM75A pin state
                   false,  //A1 LM75A pin state
                   false); //A2 LM75A pin state
// Equivalent to "LM75A lm75a_sensor;"

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Temperatures will be displayed every second:");
}

void loop()
{
  float temperature_in_degrees = lm75a_sensor.getTemperatureInDegrees();

  if (temperature_in_degrees == INVALID_LM75A_TEMPERATURE)
  {
    Serial.println("Error while getting temperature");
  }
  else
  {
    Serial.print("Temperature: ");
    Serial.print(temperature_in_degrees);
    Serial.print(" degrees (");
    Serial.print(LM75A::degreesToFahrenheit(temperature_in_degrees));
    Serial.println(" fahrenheit)");
  }

  delay(1000);
}
