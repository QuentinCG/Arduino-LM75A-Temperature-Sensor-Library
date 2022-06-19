/*
 * \brief I2C LM75A temperature sensor library
 *
 * This library can :
 *   - Show a LM75A sensor temperature in Degrees and Fahrenheit
 *   - Use multiple LM75A sensors on the same I2C network (by changing A0/A1/A2 LM75A pin state)
 *   - Use multiple LM75A sensors on default I2C board or using multi-I2C board logic (TwoWire) if available (this doubles the number of usable LM75A on compatible boards)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 19 June 2022
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2022 Quentin Comte-Gaz
 * \version 1.3
 */

#ifndef LM75A_h
#define LM75A_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>

// TODO: Uncomment this line if you want to use TwoWire
// #define USE_TWO_WIRE_FOR_LM75A 1

#define INVALID_LM75A_TEMPERATURE 1000

class LM75A
{
  public:
    /*!
     * \brief LM75A Initialize I2C LM75A Temperature sensor instance
     * \param specific_wire (TwoWire*, needed ONLY if USE_TWO_WIRE_FOR_LM75A is defined BEFORE include of this header)
     *                      This wire will be used instead of default board "Wire". It must be initialized with "TwoWire::begin"
     * \param A0_value (bool) A0 Pin value (connected to ground = false, this will be used for I2C address)
     * \param A1_value (bool) A1 Pin value (connected to ground = false, this will be used for I2C address)
     * \param A2_value (bool) A2 Pin value (connected to ground = false, this will be used for I2C address)
     */
    LM75A(
          #ifdef USE_TWO_WIRE_FOR_LM75A
          TwoWire* specific_wire,
          #endif
          bool A0_value = false,
          bool A1_value = false,
          bool A2_value = false
          );

    /*!
     * \brief LM75A Initialize I2C LM75A Temperature sensor instance using the raw address
     * \param specific_wire (TwoWire*, needed ONLY if USE_TWO_WIRE_FOR_LM75A is defined BEFORE include of this header)
     *                      This wire will be used instead of default board "Wire". It must be initialized with "TwoWire::begin"
     * \param address (int) the actual I2C address
     */
    LM75A(
          #ifdef USE_TWO_WIRE_FOR_LM75A
          TwoWire* specific_wire,
          #endif
          int address
    );

    /*!
     * \brief getTemperatureInDegrees Get temperature from LM75A sensor in degrees
     * \return (float) Sensor temperature in degrees (return INVALID_LM75A_TEMPERATURE if error happened)
     */
    float getTemperatureInDegrees() const;

    /*!
     * \brief getTemperatureInFahrenheit Get temperature from LM75A sensor in fahrenheit
     * \return (float) Sensor temperature in fahrenheit (return INVALID_LM75A_TEMPERATURE if error happened)
     */
    float getTemperatureInFahrenheit() const;

    /*!
     * \brief fahrenheitToDegrees Convert temperature from fahrenheit to degrees
     */
    static float fahrenheitToDegrees(float temperature_in_fahrenheit);

    /*!
     * \brief degreesToFahrenheit Convert temperature from degrees to fahrenheit
     */
    static float degreesToFahrenheit(float temperature_in_degrees);

  private:
    int _i2c_device_address;
    #ifdef USE_TWO_WIRE_FOR_LM75A
    TwoWire* _specific_wire;
    #endif
};

#endif //LM75A_h

