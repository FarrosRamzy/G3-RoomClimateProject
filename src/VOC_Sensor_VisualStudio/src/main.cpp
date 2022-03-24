/***************************************************************************
  This is a library for the CCS811 air

  This sketch reads the sensor

  Designed specifically to work with the Adafruit CCS811 breakout
  ----> http://www.adafruit.com/products/3566

  These sensors use I2C to communicate. The device's I2C address is 0x5A

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Arduino.h>
#include <wire.h> //I2C
#include <spi.h>
#include "Adafruit_CCS811.h" //Sensor library

bool highTvoc = false;
bool danger = false;
bool ventilation = false;

unsigned long ventilationOnTime = 1000;
unsigned long previousHighTvocTime = 0;

unsigned long sensorInterval = 1000;
unsigned long previousLowTvocTime = 0;



Adafruit_CCS811 ccs;

void setup()
{
  Serial.begin(9600);

  Serial.println("CCS811 test");

  if (!ccs.begin())
  {
    Serial.println("Failed to start sensor! Please check your wiring.");
    //     while (1);
  }

  // Wait for the sensor to be ready
  while (!ccs.available());
}

void loop()
{
  if (ccs.available())
  {
    if (!ccs.readData())
    {
      if (ccs.getTVOC() > 250)
      {
        Serial.print("TVOC (ppb): ");
        Serial.println(ccs.getTVOC());
        {
          if (highTvoc == false)
          {
            highTvoc = true;

            unsigned long highVocTime = millis();

            if (highVocTime - previousHighTvocTime >= ventilationOnTime)
            {
              previousHighTvocTime = highVocTime;

              if (ventilation == false)
              {
                ventilation = true;
                Serial.println("High TVOC, Ventilation turned ON");
              }
            }
          }
        }
      }
      else if (ccs.getTVOC() < 250)
      {
        unsigned long lowVocTime = millis();

        if (lowVocTime - previousLowTvocTime >= sensorInterval)
        {
          previousLowTvocTime = lowVocTime;
          Serial.print("TVOC (ppb): ");
          Serial.println(ccs.getTVOC());
          {
            if (highTvoc == true)
            {
              highTvoc = false;
              {
                if (ventilation == true)
                {
                  ventilation = false;
                  Serial.println("Low TVOC, Ventilation turned OFF");
                }
              }
            }
          }
        }
      }
    }
    else
    {
      Serial.println("ERROR!");
      // while (1);
    }
  }
}
