#include <room_system.h>

Adafruit_CCS811 ccs;

void setupTVOCSensor(int16_t *dataStatus)
{
    if (!ccs.begin())
    {
        *dataStatus = 0;
    }
    else
    {
        while (!ccs.available())
        {
            *dataStatus = 0;
        }
    }
}

void readOrganicCompounds(float *voc, int16_t *dataReceived)
{
    if (ccs.available())
    {
        if (!ccs.readData())
        {
            *voc = ccs.getTVOC();
            *dataReceived = 1;
        }
        else
        {
            *voc = 0;
            *dataReceived = 0;
        }
    }
}
