#include <sensors.h>

// output:
NexText hDateTime = NexText(0, 1, "tbTimer");
NexText hTempVal = NexText(0, 4, "tbTmpval");
NexText hHumVal = NexText(0, 5, "tbHmdval");
NexText hAirQ = NexText(0, 6, "tbAirQ");
NexText htempUnit = NexText(0, 11, "t3");
NexText hhumUnit = NexText(0, 12, "t4");

NexText rTempVal = NexText(2, 5, "tbTmpval");
NexText rHumVal = NexText(2, 6, "tbHmdval");
NexText rtempUnit = NexText(2, 9, "t3");
NexText rhumUnit = NexText(2, 8, "t4");

NexNumber fFanSpeed = NexNumber(3, 4, "tbFanSpeed");

NexText aVOC = NexText(4, 6, "tbVOC");
NexText aCO2 = NexText(4, 7, "tbCO2");
NexText aCO = NexText(4, 8, "tbCO");
NexText aAirQ = NexText(4, 13, "tbAirQ");
NexText aVOCUnit = NexText(4, 10, "t3");
NexText aCO2Unit = NexText(4, 11, "t4");
NexText aCOUnit = NexText(4, 12, "t3");

// input:
bool autoFanSpeed = true;
bool autoTemperature = true;
uint32_t dsTempBtn = 0;
uint32_t dsFanBtn = 0;
uint32_t sldTemp = 0;
uint32_t sldFan = 0;

NexDSButton setTempBtn = NexDSButton(2, 10, "btTempSet");
NexSlider setTemp = NexSlider(2, 4, "hSetTmp");

NexDSButton setFanSpeedBtn = NexDSButton(3, 5, "hSetFanSpeed");
NexSlider setFanSpeed = NexSlider(3, 2, "btFanSet");

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
  if (nexInit())
  {
    Serial.println("Touchscreen Setup Pass");
  }
  else
  {
    Serial.println("Touchscreen Setup Fail");
  }
  // setTempBtn.attachPop(setTempBtnChange, &setTempBtn);
  // setFanSpeedBtn.attachPop(setFanBtnChange, &setFanSpeedBtn);
  // setTemp.attachPop(setTempSlide);
  // setFanSpeed.attachPop(setFanSlide);
}

void readAutoManualState(bool *fanIsAuto, bool *tempIsAuto, uint32_t *manualTempVal, uint32_t *manualFanSpeed)
{
  *fanIsAuto = autoFanSpeed;
  *tempIsAuto = autoTemperature;
  if (autoFanSpeed)
  {
    *manualFanSpeed = sldFan;
  }

  if (autoTemperature)
  {
    *manualTempVal = sldTemp;
  }
}

void setTempBtnChange(void *ptr)
{
  setTempBtn.getValue(&dsTempBtn);
  if (dsTempBtn == 0)
  {
    autoTemperature = true;
  }
  else if (dsTempBtn == 1)
  {
    autoTemperature = false;
  }
}

void setFanBtnChange(void *ptr)
{
  setFanSpeedBtn.getValue(&dsFanBtn);
  if (dsFanBtn == 0)
  {
    autoFanSpeed = true;
  }
  else if (dsFanBtn == 1)
  {
    autoFanSpeed = false;
  }
}

void setTempSlide(void *ptr)
{
  if (!autoTemperature)
  {
    setTemp.getValue(&sldTemp);
  }
}

void setFanSlide(void *ptr)
{
  if (!autoFanSpeed)
  {
    setFanSpeed.getValue(&sldFan);
  }
}

void readTouchInput()
{
  nexLoop(nextion_listen_list);
}

void sendTempAndHumidData(float humid, float temp)
{
  if (isnan(temp))
  {
    strcpy(Temp, "unavailable");
    strcpy(TmpUnit, "");
  }
  else
  {
    dtostrf(temp, 6, 2, Temp);
    strcpy(TmpUnit, "C");
  }

  if (isnan(humid))
  {
    strcpy(Humid, "unavailable");
    strcpy(HumUnit, "");
  }
  else
  {
    dtostrf(humid, 6, 2, Humid);
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