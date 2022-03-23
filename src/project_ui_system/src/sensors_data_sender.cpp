#include <sensors.h>

void sendTempAndHumidData(float humid, float temp)
{
    if (isnan(humid) || isnan(temp))
    {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
    Serial.print(F(" Humidity: "));
    Serial.print(humid);
    Serial.print(F("%  Temperature: "));
    Serial.print(temp);
    Serial.println(F("C "));
}

void sendGasSensorData(float co, float co2, float voc, char gasStatus[])
{
    ;
}