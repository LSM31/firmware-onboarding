#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

#include "BMEConstants.h"
#include "LEDController.h"
#include "BMESPIInterface.h"

unsigned long prevSensorRead = 0; // ms from millis()

void setup()
{
    Serial.begin(115200);
    
    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create();

    LEDControllerInstance::instance().begin();
    BMESPIInterfaceInstance::instance().begin();
}

void loop()
{
    unsigned long time = millis();
    if (time - prevSensorRead >= SENSOR_DELAY)
    {
        // read sensor over SPI
        prevSensorRead = time;
        float temp = BMESPIInterfaceInstance::instance().get_temperature();
        LEDControllerInstance::instance().set_temp(temp); // this automatically updates interval
    }

    LEDControllerInstance::instance().update(); // always update since that is what writes to the LED
}