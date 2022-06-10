#include <Arduino.h>
#include <room_system.h>

float humidity;
float temperature;
float co;
float co2;
float voc;

uint32_t autoFanValue;
int tvocDataReceived;
int co2DataReceived;
int coDataReceived;
int humidDataReceived;
int tempDataReceived;

bool autoFan;
// bool autoTemp;
bool currentProcessPassed;

uint32_t setTempVal;
uint32_t setFanValue;
uint32_t previousSetFanVal;

char gasStatus[MAX_CHAR_ARRAY];
char tvocSetupStatus[MAX_CHAR_ARRAY];

STATE state;

static unsigned long startTime;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  state = IDLE;
  humidity = 0;
  temperature = 0;

  co = 0;
  co2 = 0;
  voc = 0;

  tvocDataReceived = 0;
  coDataReceived = 0;
  co2DataReceived = 0;
  humidDataReceived = 0;
  tempDataReceived = 0;

  autoFanValue = 0;

  autoFan = true;
  // autoTemp = true;
  currentProcessPassed = false;

  setTempVal = 0;
  setFanValue = 0;
  previousSetFanVal = 0;

  Serial.begin(9600);

  setupTouchsreen();
  // setupEspWifi();

  setupHumidTempSensor();
  // setupCO2Sensor();
  // setupTVOCSensor(tvocSetupStatus);

  setupFanSystem();

  startTime = millis();
}

void loop()
{
  // put your main code here, to run repeatedly:
  readTouchInput();
  readAutoManualState(&autoFan, /*&autoTemp,*/ &setTempVal, &setFanValue);
  switch (state)
  {
  case IDLE:
    if (!currentProcessPassed)
    {
      if (millis() - startTime > MAX_PROCESS_TIMER)
      {
        currentProcessPassed = true;
        startTime = millis();
        Serial.println("IDLE");
      }
    }
    else
    {
      state = READ;
    }
    break;
  case READ:
    readTempAndHumid(&humidity, &temperature);
    readCarbonMonoxide(&co);
    // readCarbonDioxide(&co2, startTime);
    // readOrganicCompounds(&voc, &tvocDataReceived);
    state = PROCESS;
    break;
  case PROCESS:
    processGasSensors(co, co2, voc, tvocDataReceived, gasStatus);
    // if (autoFan /*&& autoTemp*/)
    // {
    //   // processFanSpeed(temperature, humidity, gasStatus, &autoFanSpeed);
    //   adjustFanSpeed(setTempVal, &setFanVal, temperature, humidity, gasStatus, &autoTemp);
    // }
    if (!autoFan)
    {
      setManualSpeed(&setFanValue, &previousSetFanVal, gasStatus, &autoFan); //, &startTime);
    }
    else
    {
      adjustFanSpeed(setTempVal, &autoFanValue, temperature, humidity, gasStatus);//, &autoTemp);
    }
    
    // else if (!autoTemp)
    // {
    //   adjustFanSpeed(setTempVal, &setFanVal, temperature, humidity, gasStatus, &autoTemp);
    // }
    
    state = SEND;
    break;
  case SEND:
    sendTempAndHumidData(humidity, temperature);
    sendGasSensorData(co, co2, voc, gasStatus);
    if (autoFan /*&& autoTemp*/)
    {
      // autoFanValue = autoFanValue / 51;
      sendFanSpeedValue(autoFanValue);
    }
    else
    {
      sendFanSpeedValue(setFanValue);
    }
    currentProcessPassed = false;
    state = IDLE;
    break;
  default:
    break;
  }
}