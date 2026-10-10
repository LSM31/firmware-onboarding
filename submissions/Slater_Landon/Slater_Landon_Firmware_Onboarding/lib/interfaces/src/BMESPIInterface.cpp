#include "BMESPIInterface.h"

bool BMESPIInterface::begin()
{
    return bme_.begin();
}

float BMESPIInterface::get_temperature()
{
    return bme_.readTemperature();
}