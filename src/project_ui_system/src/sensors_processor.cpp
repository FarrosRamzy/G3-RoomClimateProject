#include <sensors.h>

float highTVOC = 0;
float highCO2 = 0;

float lowTVOC = 40;
float lowCO2 = 40;

void processGasSensors(float coVal, float co2Val, float vocVal, char gasStatus[])
{
    if (vocVal >= 250)
    {
        highTVOC = vocVal;
    }
    if (co2Val >= 180)
    {
        highCO2 = co2Val;
    }
    
    if (coVal != 0)
    {
        strcpy(gasStatus, "Danger");
    }
    else if (highCO2 != 0 || highTVOC != 0)
    {
        if (vocVal >= highTVOC || co2Val >= highCO2)
        {
            strcpy(gasStatus, "Danger");
        }
        else if (vocVal < highTVOC || co2Val < highCO2)
        {
            strcpy(gasStatus, "Normal");
        }
        else if (vocVal < lowTVOC && co2Val < lowCO2)
        {
            highCO2 = 0;
            highTVOC = 0;
            strcpy(gasStatus, "Clear");
        }
        
    }
    else
    {
        strcpy(gasStatus, "Clear");
    }
    
}

void processFanSpeed(float tempVal, float humidVal, char gasStatus[], int *fanSpeed)
{
    ;
}
