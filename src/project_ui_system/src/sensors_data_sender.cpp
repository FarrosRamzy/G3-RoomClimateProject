#include <sensors.h>

NexText hTempVal = NexText(0, 5, "tbTmpval");
NexText hHumVal = NexText(0, 6, "tbHmdval");
NexText hAirQ = NexText(0, 7, "tbAirQ");

NexText rTempVal = NexText(1, 6, "tbTmpval");
NexText rHumVal = NexText(1, 7, "tbHmdval");

NexText aVOC = NexText(3, 7, "tbVOC");
NexText aCO2 = NexText(3, 8, "tbCO2");
NexText aCO = NexText(3, 9, "tbCO");

char Temp[10];
char Humid[10];
char CO[10];
char CO2[10];
char VOC[10];

void setupTouchsreen()
{
  nexInit();
}

void sendTempAndHumidData(float humid, float temp)
{
  if (isnan(temp))
  {
    strcpy(Temp,"unknown");
  }
  else
  {
    dtostrf(temp, 6, 2, Temp);
  }

  if (isnan(humid))
  {
    strcpy(Humid,"unknown");
  }
  else
  {
    dtostrf(humid, 1, 0, Humid);
  }
  hTempVal.setText(Temp);
  hHumVal.setText(Humid);
  rTempVal.setText(Temp);
  rHumVal.setText(Humid);
}

void sendGasSensorData(float co, float co2, float voc, char gasStatus[])
{
  dtostrf(co, 6, 2, CO);
  dtostrf(co2, 6, 2, CO2);
  dtostrf(voc, 6, 2, VOC);

  aCO.setText(Temp);
  aCO2.setText(Humid);
  aVOC.setText(Temp);

  hAirQ.setText(gasStatus);
}