#include <sensors.h>

NexText hTempVal = NexText(0, 5, "tbTmpval");
NexText hHumVal = NexText(0, 6, "tbHmdval");
NexText hAirQ = NexText(0, 7, "tbAirQ");

NexText rTempVal = NexText(1, 6, "tbTmpval");
NexText rHumVal = NexText(1, 7, "tbHmdval");

NexText aVOC = NexText(3, 7, "tbVOC");
NexText aCO2 = NexText(3, 8, "tbCO2");
NexText aCO = NexText(3, 9, "tbCO");

void setupTouchsreen()
{
  nexInit();
}

void sendTempAndHumidData(float humid, float temp)
{
  if (isnan(humid) || isnan(temp))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
  }
  
}

void sendGasSensorData(float co, float co2, float voc, char gasStatus[])
{
  ;
}