#include <sensors.h>

int readVal;
float gasVal;
float readVoltage;
float ratio;

void readCarbonMonoxide(float *coVal)
{
    readVal = analogRead(A0);
    readVoltage = ((float)readVal / TEN_BIT_ANALOG_VAL) * CO_V;
    gasVal = (CO_V - readVoltage) / readVoltage;
    ratio = gasVal / CO_GAS_RATIO;

    if (ratio >= 0.7 && ratio < 2)
    {
        *coVal = gasVal;
    }
    else
    {
        *coVal = 0;
    }
}