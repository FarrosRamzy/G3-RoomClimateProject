#include <sensors.h>

// output:
NexText hDateTime = NexText(0, 1, "tbTimer");
NexText hTempVal = NexText(0, 4, "tbTmpval");
NexText hHumVal = NexText(0, 5, "tbHmdval");

NexText hAirQ = NexText(0, 6, "tbAirQ");

NexText htempUnit = NexText(0, 11, "tuTmp");
NexText hhumUnit = NexText(0, 12, "tuHmd");

NexText rTempVal = NexText(2, 5, "tbTmpval");
NexText rHumVal = NexText(2, 6, "tbHmdval");
NexText rtempUnit = NexText(2, 9, "tuTmp");
NexText rhumUnit = NexText(2, 8, "tuHmd");

NexNumber fFanSpeed = NexNumber(3, 4, "tbFanSpeed");

NexText aVOC = NexText(4, 5, "tbVOC");
NexText aCO2 = NexText(4, 6, "tbCO2");
NexText aCO = NexText(4, 7, "tbCO");

NexText aAirQ = NexText(4, 12, "tbAirQ");

NexText aVOCUnit = NexText(4, 9, "tuVOC");
NexText aCO2Unit = NexText(4, 10, "tuCO2");
NexText aCOUnit = NexText(4, 11, "tuCO");

// input:
bool automaticFanSpeed = true;
bool autoTemperature = true;
uint32_t dsTempBtn = 0;
uint32_t dsFanBtn = 0;
uint32_t sldTemp = 0;
uint32_t sldFan = 0;

NexDSButton setTempBtn = NexDSButton(2, 10, "btTempSet");
NexSlider setTemp = NexSlider(2, 4, "hSetTmp");

NexDSButton setFanSpeedBtn = NexDSButton(3, 5, "btFanSet");
NexSlider setFanSpeed = NexSlider(3, 2, "hSetFanSpeed");

/////////////////////////////////////////////////////////////

char Temp[15];
char Humid[15];

char CO[15];
char CO2[15];
char VOC[15];

char Time[10];

char TmpUnit[5];
char HumUnit[5];
char VOCUnit[5];
char CO2Unit[5];
char COUnit[5];

/////////////////////////////////////////////////////////////

// Register the inputs:
NexTouch *nextion_listen_list[] = {&setTempBtn, &setTemp, &setFanSpeedBtn, &setFanSpeed};

void setupTouchsreen()
{
  // Serial.println("Touchscreen Setup Pass");
  nexInit();
  setTempBtn.attachPop(setTempBtnChange, &setTempBtn);
  setFanSpeedBtn.attachPop(setFanBtnChange, &setFanSpeedBtn);
  setTemp.attachPop(setTempSlide);
  setFanSpeed.attachPop(setFanSlide);
}

void readAutoManualState(bool *fanIsAuto, bool *tempIsAuto, uint32_t *manualTempVal, uint32_t *manualFanSpeed)
{
  *fanIsAuto = automaticFanSpeed;
  *tempIsAuto = autoTemperature;
  if (!automaticFanSpeed)
  {
    *manualFanSpeed = sldFan;
  }

  if (!autoTemperature)
  {
    *manualTempVal = sldTemp;
  }
}

void setTempBtnChange(void *ptr)
{
  if (setTempBtn.getValue(&dsTempBtn) != 0)
  {
    autoTemperature = false;
  }
  else
  {
    autoTemperature = true;
  }
}

void setFanBtnChange(void *ptr)
{
  if (setFanSpeedBtn.getValue(&dsFanBtn) != 0)
  {
    automaticFanSpeed = false;
  }
  else
  {
    automaticFanSpeed = true;
  }
}

void setTempSlide(void *ptr)
{
  if (!autoTemperature)
  {
    uint32_t temperature = sldTemp;
    if (!setTemp.getValue(&temperature))
    {
      sldTemp = temperature;
    }
    sldTemp = temperature;
  }
}

void setFanSlide(void *ptr)
{
  if (!automaticFanSpeed)
  {
    uint32_t fanSpeed = sldFan;
    if (!setFanSpeed.getValue(&fanSpeed))
    {
      sldFan = fanSpeed;
    }
    sldFan = fanSpeed;
  }
}

void readTouchInput()
{
  nexLoop(nextion_listen_list);
}

void sendTempAndHumidData(float humidity, float temperature)
{
  if (isnan(temperature))
  {
    strcpy(Temp, "none");
    strcpy(TmpUnit, "");
  }
  else
  {
    dtostrf(temperature, 6, 1, Temp);
    strcpy(TmpUnit, "C");
  }

  if (isnan(humidity))
  {
    strcpy(Humid, "none");
    strcpy(HumUnit, "");
  }
  else
  {
    dtostrf(humidity, 6, 1, Humid);
    strcpy(HumUnit, "%");
  }

  hTempVal.setText(Temp);
  hHumVal.setText(Humid);
  htempUnit.setText(TmpUnit);
  hhumUnit.setText(HumUnit);

  rTempVal.setText(Temp);
  rHumVal.setText(Humid);
  rtempUnit.setText(TmpUnit);
  rhumUnit.setText(HumUnit);
}

void sendGasSensorData(float co, float co2, float voc, char gasStatus[])
{
  dtostrf(co, 6, 2, CO);
  dtostrf(co2, 6, 2, CO2);
  dtostrf(voc, 6, 2, VOC);
  strcpy(VOCUnit, "ppm");
  strcpy(COUnit, "ppm");
  strcpy(CO2Unit, "ppm");

  aCO.setText(CO);
  aCO2.setText(CO2);
  aVOC.setText(VOC);
  aVOCUnit.setText(VOCUnit);
  aCO2Unit.setText(CO2Unit);
  aCOUnit.setText(COUnit);

  hAirQ.setText(gasStatus);
  aAirQ.setText(gasStatus);
}

void sendFanSpeedValue(uint32_t autoFanSpeedValue)
{
  autoFanSpeedValue = (autoFanSpeedValue / 51) * 20;
  fFanSpeed.setValue(autoFanSpeedValue);
}