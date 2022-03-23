#include <Arduino.h>
#include <sensors.h>

float humid;
float temp;
float co;
float co2;
float voc;

int fanSpeed;

char gasStatus[MAX_CHAR_ARRAY];

STATE state;

unsigned long respondTime = 5000;
unsigned long startTime = millis();

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  state = IDLE;
  setupHumidTempSensor();
}

void loop()
{
  // put your main code here, to run repeatedly:
  switch (state)
  {
  case IDLE:
    /* code */
    break;
  case READ:
    readTempAndHumid(&humid, &temp);
    readCarbonMonoxide(&co);

    break;
  case PROCESS:
    processGasSensors(co, co2, voc, &gasStatus[0]);
    processTempAndHumid(temp, humid, gasStatus, &fanSpeed);

    break;
  case SEND:
    /* code */
    sendTempAndHumidData(humid, temp);
    break;
  default:
    break;
  }
}