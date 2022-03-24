#include <sensors.h>

bool highConcentration = false;
bool danger = false;

unsigned long readInterval = 5000;
unsigned long resetTime = 0;

void processGasSensors(float coVal, float co2Val, float vocVal, char* gasStatus)
{
    ;
}

void processTempAndHumid(float tempVal, float humidVal, char gasStatus[], int *fanSpeed)
{
    ;
}
