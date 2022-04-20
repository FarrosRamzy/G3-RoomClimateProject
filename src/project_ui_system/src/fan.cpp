#include <sensors.h>

void setupFanSystem()
{
    pinMode(FAN_PIN_A, OUTPUT);
    pinMode(FAN_PIN_B, OUTPUT);
    pinMode(FAN_PWM_PIN, OUTPUT);
    digitalWrite(FAN_PIN_A, HIGH);
    digitalWrite(FAN_PIN_B, LOW);
}

void processFanSpeed(float tempVal, float humidVal, char gasStatus[], int *fanSpeed)
{
    if (tempVal >= 25 && humidVal >= 58)
    {
        analogWrite(FAN_PWM_PIN, 255);
        delay(2000);
    }
    else if (tempVal < 25 || humidVal <= 55)
    {
        analogWrite(FAN_PWM_PIN, 128);
        delay(2000);
    }
}

void setManualSpeed(int speed)
{
    analogWrite(FAN_PWM_PIN, speed);
}