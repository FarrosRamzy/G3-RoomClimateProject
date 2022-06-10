#include <room_system.h>

DHT dht(DHT_PIN, DHT_TYPE);

void setupHumidTempSensor()
{
    dht.begin();
}

void readTempAndHumid(float *humidity, float *temperature)
{
    float humidityRead = dht.readHumidity();
    float temperatureRead = dht.readTemperature();

    if (isnan(humidityRead) || isnan(temperatureRead))
    {
        return;
    }
    else
    {
        *humidity = humidityRead;
        Serial.print("Humidity:\t");
        Serial.print(humidityRead);
        *temperature = temperatureRead;
        Serial.print("Temperature:\t");
        Serial.print(temperatureRead);
    }
}