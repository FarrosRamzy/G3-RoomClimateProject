#include <sensors.h>

void setupFanSystem()
{
    pinMode(FAN_PIN_A, OUTPUT);
    pinMode(FAN_PIN_B, OUTPUT);
    pinMode(FAN_PWM_PIN, OUTPUT);
    digitalWrite(FAN_PIN_A, LOW);
    digitalWrite(FAN_PIN_B, HIGH);
}

void processFanSpeed(float tempVal, float humidVal, char gasStatus[])
{
    if (tempVal >= 25 || humidVal >= 58)
    {
        analogWrite(FAN_PWM_PIN, 255);
    }
    else if (tempVal < 25 && humidVal < 55)
    {
        analogWrite(FAN_PWM_PIN, 128);
    }
}

void setManualSpeed(uint32_t speed)
{
    uint32_t actualSpeed = speed * 51;
    analogWrite(FAN_PWM_PIN, actualSpeed);
}