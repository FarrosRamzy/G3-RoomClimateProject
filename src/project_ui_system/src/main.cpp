#include <Arduino.h>
#include <sensors.h>

float humid;
float temp;
float co;
float co2;
float voc;

STATE state;

unsigned long respondTime = 5000;
unsigned long startTime = millis();

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  state = IDLE;
  void setupHumidTempSensor();
}

void loop()
{
  // put your main code here, to run repeatedly:
  switch (state)
  {
  case IDLE:
    /* code */
    break;
  case READ:
    readTempAndHumid(&humid,&temp);
    readCarbonMonoxide(&co);
    break;
  case PROCESS:
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
    break;
  case SEND:
    /* code */
    break;  
  default:
    break;
  }
}