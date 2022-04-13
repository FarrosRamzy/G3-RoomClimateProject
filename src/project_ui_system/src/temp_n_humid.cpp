#include <sensors.h>

DHT dht(DHTPIN, DHTTYPE);

void setupHumidTempSensor()
{
    dht.begin();
    Serial.println("DHT Setup Pass");
}

void readTempAndHumid(float *humid, float *temp)
{
    *humid = dht.readHumidity();
    *temp = dht.readTemperature();

    Serial.print("temp: ");
    Serial.println(*temp);
    Serial.print("hum: ");
    Serial.println(*humid);
}