#include <sensors.h>

void setupFanSystem()
{
    pinMode(FAN_PIN_A, OUTPUT);
    pinMode(FAN_PIN_B, OUTPUT);
    pinMode(FAN_PWM_PIN, OUTPUT);
    setFanDirection();
}

void setFanDirection()
{
    digitalWrite(FAN_PIN_A, LOW);
    digitalWrite(FAN_PIN_B, HIGH);
}

void processFanSpeed(float tempVal, float humidVal, char gasStatus[], uint32_t *fanSpeed)
{
    if (tempVal >= NORMAL_TEMPERTAURE || humidVal >= HIGHEST_HUMIDITY || gasStatus == "Danger")
    {
        *fanSpeed = 255;
        analogWrite(FAN_PWM_PIN, *fanSpeed);
    }
    else if (tempVal < NORMAL_TEMPERTAURE && humidVal < NORMAL_HUMIDITY && (gasStatus == "Clear" || gasStatus == "Normal"))
    {
        *fanSpeed = 128;
        analogWrite(FAN_PWM_PIN, *fanSpeed);
    }
}

void setManualSpeed(uint32_t speed)
{
    uint32_t actualSpeed = speed * 51;
    if (actualSpeed == 0)
    {
        analogWrite(FAN_PWM_PIN, 0);
    }
    else
    {
        analogWrite(FAN_PWM_PIN, actualSpeed);
    }
}