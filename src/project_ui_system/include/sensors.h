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

#define DHT_PIN 2

#define CO_PIN A0

#define CO2_TX_PIN 4
#define CO2_RX_PIN 5

#define FAN_PIN_A 12
#define FAN_PIN_B 13
#define FAN_PWM_PIN 11

#define DHT_TYPE DHT11

#define MAX_PROCESS_TIMER 500

#define WIFI_ID "MSI_YZMAR"
#define WIFI_PASSWORD "Yzmar252887"

#define MAX_CHAR_ARRAY 255

#define CO_GAS_RATIO 0.99
#define CO_V 5

#define NORMAL_TEMPERTAURE 26

#define HIGHEST_HUMIDITY 68
#define NORMAL_HUMIDITY 50

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
void setupFanSystem();
void setupEspWifi();

void readTempAndHumid(float *, float *);
void readCarbonMonoxide(float *);
void readCarbonDioxide(float *, unsigned long);
void readOrganicCompounds(float *, int *);

void readTouchInput();
void processGasSensors(float, float, float, int, char[]);
// void processFanSpeed(float, float, char[], uint32_t *);
void setManualSpeed(uint32_t *, uint32_t *, char[], bool *); //, unsigned long *);
void adjustFanSpeed(uint32_t, uint32_t *, float, float, char[]); //, bool *);

void readAutoManualState(bool *, /*bool *,*/ uint32_t *, uint32_t *);
void setTempBtnChange(void *);

void setFanDirection();
void setFanBtnChange(void *);
void setTempSlide(void *);
void setFanSlide(void *);

void sendTempAndHumidData(float, float);
void sendFanSpeedValue(uint32_t);
void sendGasSensorData(float, float, float, char[]);
#endif