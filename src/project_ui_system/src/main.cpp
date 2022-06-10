#include <Arduino.h>
#include <room_system.h>

float humidity;
float temperature;
float co;
float co2;
float voc;

uint32_t autoFanValue;
int16_t tvocDataReceived;
int16_t co2DataReceived;
int16_t coDataReceived;

bool autoFan;
bool currentProcessPassed;

uint32_t setTempVal;
uint32_t setFanValue;
uint32_t previousSetFanVal;
uint32_t previousSetTempVal;

char gasStatus[MAX_CHAR_ARRAY];

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

  autoFanValue = 0;

  autoFan = true;
  currentProcessPassed = false;

  setTempVal = 0;
  setFanValue = 0;
  previousSetFanVal = 0;
  previousSetTempVal = setTempVal;

  Serial.begin(9600);

  setupTouchsreen();  

  setupHumidTempSensor();
  setupCO2Sensor();
  setupTVOCSensor(&tvocDataReceived);

  setupFanSystem();

  startTime = millis();
}

void loop()
{
  // put your main code here, to run repeatedly:
  readTouchInput();
  readAutoManualState(&autoFan, &previousSetTempVal, &setTempVal, &setFanValue);
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
    readCarbonMonoxide(&co, &coDataReceived);
    readCarbonDioxide(&co2, &co2DataReceived);
    readOrganicCompounds(&voc, &tvocDataReceived);

    state = PROCESS;
    break;
  case PROCESS:
    processGasSensors(co, co2, voc, coDataReceived, co2DataReceived, tvocDataReceived, gasStatus);
    if (!autoFan)
    {
      setManualSpeed(&setFanValue, &previousSetFanVal, gasStatus, &autoFan);
    }
    else
    {
      adjustFanSpeed(setTempVal, &autoFanValue, temperature, humidity, gasStatus);
    }    
    state = SEND;
    break;
  case SEND:
    sendTempAndHumidData(humidity, temperature);
    sendGasSensorData(coDataReceived, co2DataReceived, tvocDataReceived, co, co2, voc, gasStatus);
    if (autoFan)
    {
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