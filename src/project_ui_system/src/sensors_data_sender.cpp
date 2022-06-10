#include <room_system.h>

// output:
NexText hDateTime = NexText(0, 1, "tbTimer");
NexText hTempVal = NexText(0, 4, "tbTmpval");
NexText hHumVal = NexText(0, 5, "tbHmdval");

NexText hAirQ = NexText(0, 6, "tbAirQ");

NexText htempUnit = NexText(0, 11, "htuTmp");
NexText hhumUnit = NexText(0, 12, "tuHmd");

NexText rTempVal = NexText(2, 5, "tbTmpval");
NexText rHumVal = NexText(2, 6, "tbHmdval");
NexText rtempUnit = NexText(2, 9, "rtuTmp");
NexText rtempUnitSymb = NexText(2, 12, "tuTmpSym");
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
uint32_t dsFanBtn = 0;
uint32_t sldTemp = 0;
uint32_t sldFan = 0;

NexSlider setTempSld = NexSlider(2, 4, "hSetTmp");
NexObject tempSldVis = NexObject(2, 4, "hSetTmp");

NexDSButton setFanSpeedBtn = NexDSButton(3, 5, "btFanSet");
NexSlider setFanSpeedSld = NexSlider(3, 2, "hSetFanspeed");

/////////////////////////////////////////////////////////////

char Temp[15];
char Humid[15];

char CO[15];
char CO2[15];
char VOC[15];

char Time[10];

char TmpUnit1[10];
char TmpUnit2[5];
char TmpUnitSymbol[5];
char HumUnit[5];
char VOCUnit[5];
char CO2Unit[5];
char COUnit[5];

char deviceID[5];
char deviceType[5];
char payloadType[10];
char payload[15];

/////////////////////////////////////////////////////////////

// Register the inputs:
NexTouch *nextion_listen_list[] = {&setTempSld, &setFanSpeedBtn, &setFanSpeedSld};

void setupTouchsreen()
{
  nexInit();
}

void readAutoManualState(bool *fanIsAuto, uint32_t *previousManualTempVal, uint32_t *manualTempVal, uint32_t *manualFanSpeed)
{
  *fanIsAuto = automaticFanSpeed;
  *manualTempVal = sldTemp;
  if (!automaticFanSpeed)
  {
    strcpy(payloadType, WRITE_DATA);
    strcpy(deviceID, UI_DEVICE);
    strcpy(deviceType, FAN_TYPE);
    sprintf(payload, "&#37;u", sldFan);

    *manualFanSpeed = sldFan;
  }

  if (*previousManualTempVal != *manualTempVal)
  {
    strcpy(payloadType, WRITE_DATA);
    strcpy(deviceID, UI_DEVICE);
    strcpy(deviceType, TEMPERATURE_TYPE);
    sprintf(payload, "&#37;u", *manualTempVal);
    
    *previousManualTempVal = *manualTempVal;
  }
}

void readTouchInput()
{
  nexLoop(nextion_listen_list);

  setFanSpeedBtn.getValue(&dsFanBtn);
  setFanSpeedSld.getValue(&sldFan);
  setTempSld.getValue(&sldTemp);

  if (dsFanBtn != 0)
  {
    automaticFanSpeed = false;
  }
  else
  {
    automaticFanSpeed = true;
  }
}

void sendTempAndHumidData(float humidity, float temperature)
{
  strcpy(payloadType, READ_DATA);

  if (isnan(temperature))
  {
    strcpy(Temp, "none");
    strcpy(TmpUnit1, "");
    strcpy(TmpUnit2, "");
    strcpy(TmpUnitSymbol, "");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, TEMPERATURE_TYPE);
    strcpy(payload, Temp);
  }
  else
  {
    dtostrf(temperature, 6, 1, Temp);
    strcpy(TmpUnit1, "Celsius");
    strcpy(TmpUnit2, "C");
    strcpy(TmpUnitSymbol, "o");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, TEMPERATURE_TYPE);
    strcpy(payload, Temp);
  }

  if (isnan(humidity))
  {
    strcpy(Humid, "none");
    strcpy(HumUnit, "");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, HUMIDITY_TYPE);
    strcpy(payload, Humid);
  }
  else
  {
    dtostrf(humidity, 6, 1, Humid);
    strcpy(HumUnit, "%");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, HUMIDITY_TYPE);
    strcpy(payload, Humid);
  }

  hTempVal.setText(Temp);
  hHumVal.setText(Humid);
  htempUnit.setText(TmpUnit1);
  hhumUnit.setText(HumUnit);

  rTempVal.setText(Temp);
  rHumVal.setText(Humid);
  rtempUnitSymb.setText(TmpUnitSymbol);
  rtempUnit.setText(TmpUnit2);
  rhumUnit.setText(HumUnit);
}

void sendGasSensorData(int16_t coData, int16_t co2Data, int16_t vocData, float co, float co2, float voc, char gasStatus[])
{
  strcpy(payloadType, READ_DATA);

  if (coData == 0)
  {
    strcpy(CO, "none");
    strcpy(COUnit, "");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, CARBON_MONOXYDE_TYPE);
    strcpy(payload, CO);
  }
  else
  {
    dtostrf(co, 6, 2, CO);
    strcpy(COUnit, "ppm");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, CARBON_MONOXYDE_TYPE);
    strcpy(payload, CO);
  }

  if (co2Data == 0)
  {
    strcpy(CO2, "none");
    strcpy(CO2Unit, "");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, CARBON_DIOXYDE_TYPE);
    strcpy(payload, CO2);
  }
  else
  {
    dtostrf(co2, 6, 2, CO2);
    strcpy(CO2Unit, "ppm");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, CARBON_DIOXYDE_TYPE);
    strcpy(payload, CO2);
  }

  if (vocData == 0)
  {
    strcpy(VOC, "none");
    strcpy(VOCUnit, "");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, ORGANIC_TYPE);
    strcpy(payload, VOC);
  }
  else
  {
    dtostrf(voc, 6, 2, VOC);
    strcpy(VOCUnit, "ppm");

    strcpy(deviceID, SENSOR_DEVICE);
    strcpy(deviceType, ORGANIC_TYPE);
    strcpy(payload, VOC);
  }

  if (strcmp("Danger", gasStatus) == 0)
  {
    setFanSpeedSld.setVisibility(false);
    setTempSld.setVisibility(false);

    setFanSpeedBtn.setValue(0);

    setFanSpeedBtn.setText("Denied");
  }

  aCO.setText(CO);
  aCO2.setText(CO2);
  aVOC.setText(VOC);
  aVOCUnit.setText(VOCUnit);
  aCO2Unit.setText(CO2Unit);
  aCOUnit.setText(COUnit);

  hAirQ.setText(gasStatus);
  aAirQ.setText(gasStatus);
}

void sendFanSpeedValue(uint32_t fanSpeedValue)
{
  if (automaticFanSpeed)
  {
    strcpy(payloadType, READ_DATA);
    strcpy(deviceID, UI_DEVICE);
    strcpy(deviceType, FAN_TYPE);
    sprintf(payload, "&#37;u", fanSpeedValue);
  }

  fanSpeedValue = fanSpeedValue * 20;
  fFanSpeed.setValue(fanSpeedValue);  
}