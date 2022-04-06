#include <sensors.h>

// NexText hDateTime = NexText(0,1,"tbTimer");
NexText hTempVal = NexText(0, 5, "tbTmpval");
NexText hHumVal = NexText(0, 6, "tbHmdval");
NexText hAirQ = NexText(0, 7, "tbAirQ");

NexText rTempVal = NexText(1, 6, "tbTmpval");
NexText rHumVal = NexText(1, 7, "tbHmdval");

NexText aVOC = NexText(3, 7, "tbVOC");
NexText aCO2 = NexText(3, 8, "tbCO2");
NexText aCO = NexText(3, 9, "tbCO");

NexTimer hTimer = NexTimer(0,11,"tm0");
NexTimer rTimer = NexTimer(1,8,"tm0");
NexTimer aTimer = NexTimer(3,4,"tm0");

char Temp[15];
char Humid[15];
char CO[15];
char CO2[15];
char VOC[15];

void setupTouchsreen()
{
  if (nexInit())
  {
    Serial.println("Touchscreen Setup Pass");
  }
  else
  {
    Serial.println("Touchscreen Setup Fail");
  }
}

void sendTempAndHumidData(float humid, float temp)
{
  if (isnan(temp))
  {
    strcpy(Temp,"unavailable");
  }
  else
  {
    dtostrf(temp, 6, 2, Temp);
  }

  if (isnan(humid))
  {
    strcpy(Humid,"unavailable");
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

  aCO.setText(CO);
  aCO2.setText(CO2);
  aVOC.setText(VOC);

  hAirQ.setText(gasStatus);
}