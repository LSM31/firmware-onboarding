#include <Wire.h>

#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    Wire.begin();
    return bme_.begin(BME_ADDRESS, &Wire);
}

float BMEI2CInterface::get_temperature()
{
    return bme_.readTemperature();
}