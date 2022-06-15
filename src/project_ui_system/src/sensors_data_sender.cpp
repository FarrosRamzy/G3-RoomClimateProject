#include <room_system.h>

// output:
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

String lastInputType = HUMIDITY_TYPE;
String lastInputState = READ_DATA;
uint32_t lastInputVal = 0;

/////////////////////////////////////////////////////////////

char Temp[15];
char Humid[15];

char CO[15];
char CO2[15];
char VOC[15];

char TmpUnit1[10];
char TmpUnit2[5];
char TmpUnitSymbol[5];

char HumUnit[5];
char VOCUnit[5];
char CO2Unit[5];
char COUnit[5];

/////////////////////////////////////////////////////////////

// Register the inputs:
NexTouch *nextion_listen_list[] = {&setTempSld, &setFanSpeedBtn, &setFanSpeedSld};

void setupTouchsreen()
{
  nexInit();
}

void readAutoManualState(bool *fanIsAuto, uint32_t *previousManualTempVal, uint32_t *manualTempVal, uint32_t *manualFanSpeed, String inputType, String inputState, uint32_t inputVal)
{
  *fanIsAuto = automaticFanSpeed;
  *manualTempVal = sldTemp;
  if (!automaticFanSpeed)
  {
    // strcpy(payloadDataState, WRITE_DATA);
    // strcpy(payloadID, UI_DEVICE);
    // strcpy(payloadDataType, FAN_TYPE);
    // sprintf(payloadData, "%lu", sldFan);

    // runWifi(payloadID, payloadDataType, payloadDataState, payloadData);

    *manualFanSpeed = sldFan;
  }

  *previousManualTempVal = *manualTempVal;

  // if (*previousManualTempVal != *manualTempVal)
  // {
  //   strcpy(payloadDataState, WRITE_DATA);
  //   strcpy(payloadID, UI_DEVICE);
  //   strcpy(payloadDataType, TEMPERATURE_TYPE);
  //   sprintf(payloadData, "%lu", *manualTempVal);

  //   // runWifi(payloadID, payloadDataType, payloadDataState, payloadData);
  // }

  // if (((lastInputType != inputType) && (lastInputState != inputState)) || (lastInputVal != inputVal))
  // {
  //   lastInputType = inputType;
  //   lastInputState = inputState;
  //   lastInputVal = inputVal;

  //   if (inputState == WRITE_DATA)
  //   {
  //     if (inputType == FAN_TYPE)
  //     {
  //       setFanSpeedSld.setValue(inputVal);
  //       *manualFanSpeed = inputVal;
  //     }
  //     else if (inputType == TEMPERATURE_TYPE)
  //     {
  //       setTempSld.setValue(inputVal);
  //       *previousManualTempVal = inputVal;
  //     }
  //   }
  // }
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

void sendTemperatureData(float temperature)
{
  char payloadID[10];
  char payloadDataType[10];
  char payloadDataState[10];
  char payloadData[15];

  if (isnan(temperature))
  {
    strcpy(Temp, "none");
    strcpy(TmpUnit1, "");
    strcpy(TmpUnit2, "");
    strcpy(TmpUnitSymbol, "");
  }
  else
  {
    dtostrf(temperature, 6, 1, Temp);
    strcpy(TmpUnit1, "Celsius");
    strcpy(TmpUnit2, "C");
    strcpy(TmpUnitSymbol, "o");
  }

  hTempVal.setText(Temp);
  hHumVal.setText(Humid);
  htempUnit.setText(TmpUnit1);
  hhumUnit.setText(HumUnit);

  strcpy(payloadID, SENSOR_DEVICE);
  strcpy(payloadDataType, TEMPERATURE_TYPE);
  strcpy(payloadDataState, READ_DATA);
  strcpy(payloadData, Temp);

  runWifi(payloadID, payloadDataType, payloadDataState, payloadData);
}

void sendHumidityData(float humidity)
{
  char payloadID[10];
  char payloadDataType[10];
  char payloadDataState[10];
  char payloadData[15];

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

  rTempVal.setText(Temp);
  rHumVal.setText(Humid);
  rtempUnitSymb.setText(TmpUnitSymbol);
  rtempUnit.setText(TmpUnit2);
  rhumUnit.setText(HumUnit);

  strcpy(payloadID, SENSOR_DEVICE);
  strcpy(payloadDataType, HUMIDITY_TYPE);
  strcpy(payloadDataState, READ_DATA);
  strcpy(payloadData, Humid);

  // runWifi(payloadID, payloadDataType, payloadDataState, payloadData);
}

void sendCOData(float co, int16_t status)
{
  char payloadID[10];
  char payloadDataType[10];
  char payloadDataState[10];
  char payloadData[15];

  if (status == 0)
  {
    strcpy(CO, "none");
    strcpy(COUnit, "");
  }
  else
  {
    dtostrf(co, 6, 2, CO);
    strcpy(COUnit, "ppm");
  }

  aCO.setText(CO);
  aCOUnit.setText(COUnit);

  strcpy(payloadID, SENSOR_DEVICE);
  strcpy(payloadDataType, CARBON_MONOXYDE_TYPE);
  strcpy(payloadDataState, READ_DATA);
  strcpy(payloadData, CO);

  // runWifi(payloadID, payloadDataType, payloadDataState, payloadData);
}

void sendCO2Data(float co2, int16_t status)
{
  char payloadID[10];
  char payloadDataType[10];
  char payloadDataState[10];
  char payloadData[15];

  if (status == 0)
  {
    strcpy(CO2, "none");
    strcpy(CO2Unit, "");
  }
  else // if (co2Data == 1)
  {
    dtostrf(co2, 6, 2, CO2);
    strcpy(CO2Unit, "ppm");
  }

  aCO2.setText(CO2);
  aCO2Unit.setText(CO2Unit);

  strcpy(payloadID, SENSOR_DEVICE);
  strcpy(payloadDataType, CARBON_DIOXYDE_TYPE);
  strcpy(payloadDataState, READ_DATA);
  strcpy(payloadData, CO2);

  // runWifi(payloadID, payloadDataType, payloadDataState, payloadData);
}

void sendVOCData(float voc, int16_t status)
{
  char payloadID[10];
  char payloadDataType[10];
  char payloadDataState[10];
  char payloadData[15];
  
  if (status == 0)
  {
    strcpy(VOC, "none");
    strcpy(VOCUnit, "");
  }
  else // if (vocData == 1)
  {
    dtostrf(voc, 6, 2, VOC);
    strcpy(VOCUnit, "ppm");
  }

  aVOC.setText(VOC);
  aVOCUnit.setText(VOCUnit);

  strcpy(payloadID, SENSOR_DEVICE);
  strcpy(payloadDataType, ORGANIC_TYPE);
  strcpy(payloadDataState, READ_DATA);
  strcpy(payloadData, VOC);

  // runWifi(payloadID, payloadDataType, payloadDataState, payloadData);
}

void sendGasStatus(char gasStatus[])
{
  if (strcmp("Danger", gasStatus) == 0)
  {
    setFanSpeedSld.setVisibility(false);
    setTempSld.setVisibility(false);

    setFanSpeedBtn.setValue(0);

    setFanSpeedBtn.setText("Denied");
  }

  hAirQ.setText(gasStatus);
  aAirQ.setText(gasStatus);
}

void sendFanSpeedValue(uint32_t fanSpeedValue)
{
  // if (automaticFanSpeed)
  // {
  //   strcpy(payloadDataState, READ_DATA);
  //   strcpy(payloadID, UI_DEVICE);
  //   strcpy(payloadDataType, FAN_TYPE);
  //   sprintf(payloadData, "%lu", fanSpeedValue);

  //   // runWifi(payloadID, payloadDataType, payloadDataState, payloadData);
  // }

  fanSpeedValue = fanSpeedValue * 20;
  fFanSpeed.setValue(fanSpeedValue);
}
