#ifndef ROOM_SYSTEM_H
#define ROOM_SYSTEM_H

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

#define MAX_CHAR_ARRAY 255

#define CO_GAS_RATIO 0.99
#define CO_V 5

#define NORMAL_TEMPERTAURE 26

#define HIGHEST_HUMIDITY 68
#define NORMAL_HUMIDITY 50

#define TEN_BIT_ANALOG_VAL 1024

#define WIFI_ID "MSI_YZMAR"
#define WIFI_PASSWORD "Yzmar252887"

#define SERVER_IP "192.168.137.1"
#define SERVER_PORT "8888"

#define SET_WIFI_MODE "AT+CWMODE=3"
#define CHECK_ACC_POINT "AT+CWJAP?"
#define GET_MAC_ADDRESS "AT+CIPSTAMAC?"
#define JOIN_ACC_POINT "AT+CWJAP="
#define CHECK_STATUS "AT+CIPSTATUS"
#define START_COMMUNICATION "AT+CIPSTART="
#define SEND_MESSAGE "AT+CIPSEND="
#define STOP_ECHO "ATE0"

#define TCP "TCP"

#define START_CHAR "#"
#define SPLIT_CHAR "&"
#define PAYLOAD_START_CHAR "{"
#define PAYLOAD_SEPARATOR "|"
#define PAYLOAD_END_CHAR "}"
#define END_CHAR ";"

#define SENSOR_DEVICE "SENSOR"
#define UI_DEVICE "UI"
#define APP_DEVICE "APP"

#define TEMPERATURE_TYPE "TMP"
#define HUMIDITY_TYPE "HUM"
#define CARBON_MONOXYDE_TYPE "CO"
#define CARBON_DIOXYDE_TYPE "CO2"
#define ORGANIC_TYPE "VOC"
#define FAN_TYPE "FAN"

#define READ_DATA "READ"
#define WRITE_DATA "WRITE"

enum STATE
{
    IDLE,
    READ,
    PROCESS,
    SEND
};

void setupTouchsreen();
void setupTVOCSensor(int16_t *);
void setupCO2Sensor();
void setupHumidTempSensor();
void setupFanSystem();

bool setupEspWifi();

void getSystemID();
void runWifi(String);

bool checkATresponse(String);

bool setConnectionMode();
bool checkAccessPoint();
bool joinAccessPoint();
bool checkConnectionStatus();
bool startConnection();
bool sendMessage();

void readInputMessage();
void splitInputLine(String);

void readTempAndHumid(float *, float *);
void readCarbonMonoxide(float *, int16_t *);
void readCarbonDioxide(float *, int16_t *);
void readOrganicCompounds(float *, int16_t *);

void readTouchInput();
void processGasSensors(float, float, float, int16_t, int16_t, int16_t, char[]);
void setManualSpeed(uint32_t *, uint32_t *, char[], bool *);
void adjustFanSpeed(uint32_t, uint32_t *, float, float, char[]);

void readAutoManualState(bool *, uint32_t *, uint32_t *, uint32_t *);
void setTempBtnChange(void *);

void setFanDirection();
void setFanBtnChange(void *);
void setTempSlide(void *);
void setFanSlide(void *);

void sendTempAndHumidData(float, float);
void sendFanSpeedValue(uint32_t);
void sendGasSensorData(int16_t, int16_t, int16_t, float, float, float, char[]);
#endif