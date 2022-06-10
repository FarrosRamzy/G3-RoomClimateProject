#include <room_system.h>

SoftwareSerial mhzSerial(CO2_RX_PIN,CO2_TX_PIN);
ErriezMHZ19B co2mhz19b(&mhzSerial);

void setupCO2Sensor()
{
    mhzSerial.begin(9600);
    co2mhz19b.setRange5000ppm();
    co2mhz19b.setAutoCalibration(true);
}

void readCarbonDioxide(float *co2, int16_t *dataReceived)
{
    if (co2mhz19b.isReady())
    {
        if (co2mhz19b.readCO2() < 0)
        {
            *dataReceived = 0;
        }
        else
        {
            *co2 = co2mhz19b.readCO2();
            *dataReceived = 1;
        }
        
    }
    else
    {
        *dataReceived = 0;
    }
}