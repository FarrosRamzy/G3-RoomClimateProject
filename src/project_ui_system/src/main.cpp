#include <Arduino.h>
#include <sensors.h>

float humid;
float temp;
float co;
float co2;
float voc;

int fanSpeed;
int dataReceived = 0;

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
  setupHumidTempSensor();
  setupCO2Sensor();
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
    readTempAndHumid(&humid, &temp);
    readCarbonMonoxide(&co);
    //readCarbonDioxide(&co2, startTime);
    readOrganicCompounds(&voc, &dataReceived);
    state = PROCESS;
    break;
  case PROCESS:
    processGasSensors(co, co2, voc, dataReceived,gasStatus);
    // processFanSpeed(temp, humid, gasStatus, &fanSpeed);
    state = SEND;
    break;
  case SEND:
    sendTempAndHumidData(humid, temp);
    sendGasSensorData(co, co2, voc, gasStatus);
    //
    //
    state = IDLE;
    break;
  default:
    break;
  }
}