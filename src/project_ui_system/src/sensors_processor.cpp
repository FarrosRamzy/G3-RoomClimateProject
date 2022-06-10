#include <room_system.h>

float highTVOC = 400;
float highCO2 = 1500;

float lowTVOC = 100;
float lowCO2 = 600;

void processGasSensors(float coVal, float co2Val, float vocVal, int16_t coData, int16_t co2Data, int16_t vocData, char gasStatus[])
{
    if (coData == 0 || co2Data == 0 || vocData == 0)
    {
        strcpy(gasStatus, "Error");
    }
    else
    {
        if (vocVal >= highTVOC)
        {
            highTVOC = vocVal;
        }
        if (co2Val >= highCO2)
        {
            highCO2 = co2Val;
        }

        if (coVal > 200)
        {
            strcpy(gasStatus, "Danger");
        }
        else if (highCO2 > 1500 || highTVOC > 400)
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
                highCO2 = 1500;
                highTVOC = 400;
                strcpy(gasStatus, "Clear");
            }
        }
        else
        {
            strcpy(gasStatus, "Clear");
        }
    }
}
