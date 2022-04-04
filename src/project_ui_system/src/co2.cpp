#include <sensors.h>

unsigned long int downTimer = 0;
float pwm_value = 0;
int lowValue = 0;

void setupCO2Sensor()
{
    pinMode(CO2PIN, INPUT);
}

void readCarbonDioxide(float *co2, unsigned long startTimer)
{
    int measurements = 0;
    while (measurements < 2)
    {
        Serial.print("before pwm ");
        Serial.println(pwm_value);
        pwm_value = pulseIn(CO2PIN, HIGH, 730000) / 1000;
        if (pwm_value > 0)
        {
            Serial.println("pwm is here");
            lowValue = (startTimer - downTimer) - pwm_value;
            downTimer = millis();
            measurements++;
        }
    }
    *co2 = (2000 * (pwm_value - 2) / (pwm_value + lowValue - 4));

    Serial.print("co2: ");
    Serial.println(*co2);
}