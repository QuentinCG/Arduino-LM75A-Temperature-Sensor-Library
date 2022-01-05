/*
 * \brief Show temperature in degrees and fahrenheit every second from 2 different LM75A sensors on board I2C network
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 05 January 2022
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2022 Quentin Comte-Gaz
 * \version 1.2
 */

#include <LM75A.h>

// Create I2C LM75A instance
LM75A lm75a_sensor_1(false,  // A0 LM75A pin state (connected to ground = false)
                     false,  // A1 LM75A pin state (connected to ground = false)
                     false); // A2 LM75A pin state (connected to ground = false)
// Equivalent to "LM75A lm75a_sensor_1;"

LM75A lm75a_sensor_2(true,   // A0 LM75A pin state (connected to Vcc = true)
                     false,  // A1 LM75A pin state (connected to ground = false)
                     false); // A2 LM75A pin state (connected to ground = false)

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Temperatures or 2 LM75A sensors will be displayed every second:");
}

void loop()
{
  // Get temperature of both sensors
  float temperature_in_degrees_1 = lm75a_sensor_1.getTemperatureInDegrees();
  float temperature_in_degrees_2 = lm75a_sensor_2.getTemperatureInDegrees();

  // Display temperature of first sensor
  if (temperature_in_degrees_1 == INVALID_LM75A_TEMPERATURE)
  {
    Serial.println("Error while getting temperature of sensor 1");
  }
  else
  {
    Serial.print("Temperature of sensor 1: ");
    Serial.print(temperature_in_degrees_1);
    Serial.print(" degrees (");
    Serial.print(LM75A::degreesToFahrenheit(temperature_in_degrees_1));
    Serial.println(" fahrenheit)");
  }

  // Display temperature of second sensor
  if (temperature_in_degrees_2 == INVALID_LM75A_TEMPERATURE)
  {
    Serial.println("Error while getting temperature of sensor 2");
  }
  else
  {
    Serial.print("Temperature of sensor 2: ");
    Serial.print(temperature_in_degrees_2);
    Serial.print(" degrees (");
    Serial.print(LM75A::degreesToFahrenheit(temperature_in_degrees_2));
    Serial.println(" fahrenheit)");
  }

  delay(1000);
}
