#include <Arduino.h>
#include <sensors.h>

float humidity;
float temperature;
float co;
float co2;
float voc;

uint32_t manualFanSpeed;
uint32_t autoFanSpeed;
int tvocDataReceived;
int co2DataReceived;
int coDataReceived;
int humidDataReceived;
int tempDataReceived;

bool autoFan;
bool autoTemp;
bool currentProcessPassed;

uint32_t setTempVal;
uint32_t setFanVal;

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

  manualFanSpeed = 0;
  autoFanSpeed = 0;

  autoFan = true;
  autoTemp = true;
  currentProcessPassed = false;

  setTempVal = 0;
  setFanVal = 0;

  Serial.begin(9600);

  setupTouchsreen();
  // setupEspWifi();

  setupHumidTempSensor();
  // setupCO2Sensor();
  // setupTVOCSensor(tvocSetupStatus);

  setupFanSystem();

  startTime = millis();
  Serial.println("SETUP");
}

void loop()
{
  // put your main code here, to run repeatedly:
  readTouchInput();
  readAutoManualState(&autoFan, &autoTemp, &setTempVal, &setFanVal);
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
    if (autoFan)
    {
      processFanSpeed(temperature, humidity, gasStatus, &autoFanSpeed);
    }
    else if (!autoFan)
    {
      setManualSpeed(setFanVal);
    }
    state = SEND;
    break;
  case SEND:
    sendTempAndHumidData(humidity, temperature);
    sendGasSensorData(co, co2, voc, gasStatus);
    if (autoFan)
    {
      sendFanSpeedValue(autoFanSpeed);
    }
    currentProcessPassed = false;
    state = IDLE;
    break;
  default:
    break;
  }
}