#include <sensors.h>

float highTVOC = 400;
float highCO2 = 2000;

float lowTVOC = 100;
float lowCO2 = 500;

void processGasSensors(float coVal, float co2Val, float vocVal, int vocData, char gasStatus[])
{
    if (vocData == 1)
    {
        if (vocVal >= highTVOC)
        {
            highTVOC = vocVal;
        }
        if (co2Val >= highCO2)
        {
            highCO2 = co2Val;
        }

        // if (coVal != 0)
        // {
        //     strcpy(gasStatus, "Normal");

        // }
        if (coVal > 200)
        {
            strcpy(gasStatus, "Danger");
        }
        else if (highCO2 != 0 || highTVOC != 0)
        {
            if (vocVal >= highTVOC || co2Val >= highCO2)
            {
                strcpy(gasStatus, "Danger");
            }
            else if (vocVal < highTVOC && co2Val < highCO2)
            {
                strcpy(gasStatus, "Normal");
            }
            else if (vocVal < lowTVOC && co2Val < lowCO2)
            {
                highCO2 = 400;
                highTVOC = 800;
                strcpy(gasStatus, "Clear");
            }
        }
        else
        {
            strcpy(gasStatus, "Clear");
        }
    }
    else
    {
        strcpy(gasStatus, "Error");
    }
}
