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
    ;
}

void setManualSpeed(int speed)
{
  analogWrite(FAN_PWM_PIN, speed);
}