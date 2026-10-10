#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

#include "BMEConstants.h"
#include "LEDController.h"
#include "BMEI2CInterface.h"

unsigned long prevSensorRead = 0; // ms from millis()

void setup()
{
    Serial.begin(115200);
    
    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    LEDControllerInstance::instance().begin();
    BMEI2CInterfaceInstance::instance().begin();
}

void loop()
{
    unsigned long time = millis();
    if (time - prevSensorRead >= SENSOR_DELAY)
    {
        // read sensor over i2c
        prevSensorRead = time;
        float temp = BMEI2CInterfaceInstance::instance().get_temperature();
        LEDControllerInstance::instance().set_temp(temp); // this automatically updates interval
    }

    LEDControllerInstance::instance().update(); // always update since that is what writes to the LED
}