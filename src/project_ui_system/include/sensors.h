#ifndef SENSORS_H
#define SENSORS_H

#include <DHT.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_CCS811.h>
#include <Wire.h>
#include <Nextion.h>
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define CO_GAS_RATIO 0.99
#define CO_V 5
#define TEN_BIT_ANALOG_VAL 1024

enum STATE
{
    IDLE,
    READ,
    PROCESS,
    SEND
};

void setupSensors();
void setupHumidTempSensor();
void readTempAndHumid(float*, float*);
void readCarbonMonoxide(float*);
void processGasSensors(float,float,float,char*);
void processTempAndHumid(float,float);

#endif