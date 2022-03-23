#ifndef SENSORS_H
#define SENSORS_H

#include <DHT.h>
#include <Nextion.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void readTempAndHumid(float*, float*);
void setupSensors();

#endif