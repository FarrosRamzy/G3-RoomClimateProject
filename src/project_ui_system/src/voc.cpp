#include <sensors.h>

Adafruit_CCS811 ccs;

void setupTVOCSensor(char sensorStatus[])
{
    if (!ccs.begin())
    {
        strcpy(sensorStatus, "Failed to start sensor! Please check your wiring.");
    }
    else
    {
        while (!ccs.available())
        {
            strcpy(sensorStatus, "No Data Available.");
        }
    }
}

void readOrganicCompounds(float *voc, int *dataReceived)
{
    if (ccs.available())
    {
        if (!ccs.readData())
        {
            *voc = ccs.getTVOC();
            *dataReceived = 1;
        }
    }
    else
    {
        *voc = 0;
        *dataReceived = 0;
    }
}
