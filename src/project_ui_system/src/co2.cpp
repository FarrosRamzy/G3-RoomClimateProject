#include <sensors.h>

SoftwareSerial mhzSerial(CO2_TX_PIN,CO2_RX_PIN);
ErriezMHZ19B co2mhz19b(&mhzSerial);

void setupCO2Sensor()
{
    mhzSerial.begin(9600);
    co2mhz19b.setRange5000ppm();
    co2mhz19b.setAutoCalibration(true);
    while (!co2mhz19b.detect())
    {
        Serial.println(F("CO2 Loading ..."));
    }
}

void readCarbonDioxide(float *co2, unsigned long startTimer)
{
    float temporary = *co2;
    if (co2mhz19b.isReady())
    {
        if (co2mhz19b.readCO2() >= 0)
        {
            *co2 = co2mhz19b.readCO2();
        }
    }
    else
    {
        *co2 = temporary;
    }
}