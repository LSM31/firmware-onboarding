#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    // Code here!
    LEDController(int pin = LED_PIN);

    bool begin();
    void update();
    void set_temp(float temp);

private:
    // Code here!
    int pin_;
    float temp_;
    unsigned long intervalMs_ = 500;
    unsigned long prevToggle_;       // set equal to millis() when toggle occurs
    bool on_ = false;

};
using LEDControllerInstance = etl::singleton<LEDController>;