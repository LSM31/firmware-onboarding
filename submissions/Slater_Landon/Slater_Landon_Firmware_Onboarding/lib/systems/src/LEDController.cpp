#include <Arduino.h>

#include "LEDController.h"

LEDController::LEDController(int pin) : pin_(pin) {}

bool LEDController::begin()
{
    pinMode(pin_, OUTPUT);
    digitalWrite(pin_, LOW);
    prevToggle_ = millis(); // so prevToggle_ doesn't bug when loop begins
    return true;
}

void LEDController::set_temp(float temp)
{
    temp_ = temp;
    
    // also calc interval
    // might need to update this to account for temp being a float...
    intervalMs_ = map(  temp_,
                        TEMP_THRESHOLD_LOW,
                        TEMP_THRESHOLD_HIGH,
                        INTERVAL_THRESHOLD_SLOW,
                        INTERVAL_THRESHOLD_FAST);

    return;
}

void LEDController::update()
{
    unsigned long currentTime = millis();
    if (currentTime - prevToggle_ >= intervalMs_)
    {
        prevToggle_ = currentTime;
        on_ = !on_;
        digitalWrite(pin_, on_ ? HIGH : LOW);
    }

    return;
}