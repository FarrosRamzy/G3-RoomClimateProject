#include <sensors.h>

void readTempAndHumid(float *humid, float *temp)
{
    *humid = dht.readHumidity();
    *temp = dht.readTemperature();
}