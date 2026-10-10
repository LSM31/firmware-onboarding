#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMESPIInterface
{
public:
    // Code here!
    BMESPIInterface() = default;

    bool begin();
    float get_temperature();

private:
   // Code here!
   Adafruit_BME280 bme_{SPI_SS, SPI_MOSI, SPI_MISO, SPI_SCK};

};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;