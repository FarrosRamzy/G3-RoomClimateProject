#include <sensors.h>

DHT dht(DHTPIN, DHTTYPE);

void setupHumidTempSensor()
{
    dht.begin();
    Serial.println(F("DHTxx test!"));
}

void readTempAndHumid(float *humid, float *temp)
{
    *humid = dht.readHumidity();
    *temp = dht.readTemperature();
}