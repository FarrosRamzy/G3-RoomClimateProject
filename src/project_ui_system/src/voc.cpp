#include <sensors.h>

bool highConcentration = false;
bool danger = false;

unsigned long readInterval = 5000;
unsigned long resetTime = 0;

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

void readOrganicCompounds(float *voc)
{
    ;
}


