#include <sensors.h>

AltSoftSerial ESPserial(8,9);

void setupEspWifi()
{
    ESPserial.begin(9600);
}