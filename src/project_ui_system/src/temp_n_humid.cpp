#include <sensors.h>

DHT dht(DHTPIN, DHTTYPE);

void setupHumidTempSensor()
{
    dht.begin();
}

void readTempAndHumid(float *humid, float *temp)
{
    *humid = dht.readHumidity();
    *temp = dht.readTemperature();
}