#ifndef SENSORS_H
#define SENSORS_H

#include <DHT.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_CCS811.h>
#include <Wire.h>
#include <Nextion.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#include <ErriezMHZ19B.h>
#include <TimeLib.h>
#include <string.h>

#define DHTPIN 2

#define CO2_TX_PIN 4
#define CO2_RX_PIN 5

#define DHTTYPE DHT11

#define MAX_CHAR_ARRAY 255

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

void setupTouchsreen();
void setupTVOCSensor(char[]);
void setupCO2Sensor();
void setupHumidTempSensor();
void setupEspWifi();

void readTempAndHumid(float *, float *);
void readCarbonMonoxide(float *);
void readCarbonDioxide(float *, unsigned long);
void readOrganicCompounds(float *, int *);

void processGasSensors(float, float, float, int, char[]);
void processFanSpeed(float, float, char[], int *);

void sendTempAndHumidData(float, float);
void sendGasSensorData(float, float, float, char[]);
#endif