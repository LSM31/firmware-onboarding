#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMEI2CInterface
{
public:
    // Code here!
    BMEI2CInterface() = default;

    bool begin();
    float get_temperature();

private:
   // Code here!
   Adafruit_BME280 bme_{};
};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;