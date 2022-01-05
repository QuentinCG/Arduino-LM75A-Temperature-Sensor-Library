/*
 * \brief Show temperature in degrees and fahrenheit every second
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 05 January 2022
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2022 Quentin Comte-Gaz
 * \version 1.2
 */

#include <LM75A.h>

// Create I2C LM75A instance
LM75A lm75a_sensor(false,  // A0 LM75A pin state (connected to ground = false)
                   false,  // A1 LM75A pin state (connected to ground = false)
                   false); // A2 LM75A pin state (connected to ground = false)
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
