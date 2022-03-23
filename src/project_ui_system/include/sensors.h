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
void readCarbonMonoxide();
void processGasSensors(float,float,float,char*);
void processTempAndHumid(float,float);

#endif