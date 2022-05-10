#include <Arduino.h>
#include <sensors.h>

float humid;
float temp;
float co;
float co2;
float voc;

int fanSpeed;
int tvocDataReceived = 0;
int co2DataReceived = 0;
int coDataReceived = 0;
int humidDataReceived = 0;
int tempDataReceived = 0;

bool autoFan = true;
bool autoTemp = true;

uint32_t setTempVal;
uint32_t setFanVal;

char gasStatus[MAX_CHAR_ARRAY];
char tvocSetupStatus[MAX_CHAR_ARRAY];

STATE state;

static unsigned long respondTime = 5000;
static unsigned long startTime = millis();
bool timePassed = false;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  state = IDLE;
  setupTouchsreen();
  //setupEspWifi();
  setupHumidTempSensor();
  //setupCO2Sensor();
  //setupFanSystem();
  setupTVOCSensor(tvocSetupStatus);
}

void loop()
{
  // put your main code here, to run repeatedly:
  switch (state)
  {
  case IDLE:
    static unsigned long passTime = millis();
    if (!timePassed)
    {
      if (startTime - passTime > respondTime)
      {
        timePassed = true;
      }
    }
    else
    {
      state = READ;
    }
    break;
  case READ:
    //readTouchInput();
    //readAutoManualState(&autoFan, &autoTemp, &setTempVal, &setFanVal);
    readTempAndHumid(&humid, &temp);
    readCarbonMonoxide(&co);
    //readCarbonDioxide(&co2, startTime);
    readOrganicCompounds(&voc, &tvocDataReceived);
    state = PROCESS;
    break;
  case PROCESS:
    processGasSensors(co, co2, voc, tvocDataReceived, gasStatus);
    // if (autoFan)
    // {
    //   setManualSpeed(setFanVal);
    // }
    // else if (!autoFan)
    // {
    //   processFanSpeed(temp, humid, gasStatus);
    // }
    state = SEND;
    break;
  case SEND:
    sendTempAndHumidData(humid, temp);
    sendGasSensorData(co, co2, voc, gasStatus);
    state = IDLE;
    break;
  default:
    break;
  }
}