#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // constants here!
    #define BME_ADDRESS 0x76 // for I2C

    #define SENSOR_DELAY 500  // ms

    // pins from Arduino Uno Pinout
    #define I2C_SDA     A4
    #define I2C_SCL     A5

    #define SPI_SCK     13
    #define SPI_MISO    12
    #define SPI_MOSI    11
    #define SPI_SS      10

    #define LED_PIN     LED_BUILTIN  // hoping it is not 13 since that is the SPI_SCK pin but pinout says it is ????

    // thresholds for temperature and frequency
    #define TEMP_THRESHOLD_LOW  0.0
    #define TEMP_THRESHOLD_HIGH 100.0
    #define INTERVAL_THRESHOLD_SLOW  500  // ms
    #define INTERVAL_THRESHOLD_FAST  100  // ms


} // namespace BMEConstants
