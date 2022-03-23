#include <Arduino.h>
#include <sensors.h>

float humid;
float temp;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  readTempAndHumid(&humid,&temp);
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