// #include "Communication.h"

#define UCAST "AT+UCAST:"
#define BCAST "AT+BCAST:00,"

#define START_CHAR '@'
#define SEPERATE_CHAR '&'
#define STOP_CHAR '$'

#define REGISTERMODULE "REG"
#define SENDSENSORDATA "SENDDATA"
#define SENDSPIKEDATA "SPIKE"
#define REQUESTALLDATA "GETALLDATA"
#define REQUESTDATA "GETDATA"

#define ERRORMODREG "ERRORMODREG"
#define ERRORNOSENSOR "ERRORNOSENSOR"
#define ERRORMODNOTREG "ERRORMODNOTREG"
#define ERRORSENSNOTREG "ERRORSENSNOTREG"

#define MESSAGE_SEGMENT_LIMIT 20

String serverId = "000D6F00108E4577"; //depends on how changing persistent data works
String moduleId = "000D6F00108DCC47"; //depends on how changing persistent data works
Sensor *sensors[MAXNUMBEROFSENSORS];
int sensorCount = 4;

///Temporary code for testing the system
void regSensors(Sensor *temp, Sensor *humidity, Sensor *co2, Sensor *voc)
{
    temp->id = 1;
    temp->type = TEMP_TYPE;
    humidity->id = 2;
    humidity->type = HUMIDITY_TYPE;
    co2->id = 3;
    co2->type = CO2_TYPE;
    voc->id = 4;
    voc->type = VOC_TYPE;
    sensors[0] = temp;
    sensors[1] = humidity;
    sensors[2] = co2;
    sensors[3] = voc;

}

///Temp send all sensor data for testing
void testSendAllData()
{
    sendAllSensorData(sensors, sensorCount);
}

void readZigbeePort()
{
    static bool messageStarted = false;
    static String message;
    if (Serial.available())
    {
        char tempChar = Serial.read();
        if (tempChar == START_CHAR)
        {
            message.remove(0);
            messageStarted = true;
        }
        else if (tempChar == STOP_CHAR && messageStarted)
        {
            splitMessage(message);
            messageStarted = false;
        }
        else if (messageStarted)
        {
            message += tempChar;
        }
    }
}

///Split the massage on the seperation character
void splitMessage(String message)
{
    String splitMessage[MESSAGE_SEGMENT_LIMIT];

    int seperator = 0;
    int nextSeperator = 0;
    nextSeperator = message.indexOf(SEPERATE_CHAR, seperator + 1);
    splitMessage[0] = message.substring(seperator, nextSeperator);
    seperator = nextSeperator;

    for (int i = 1; i < MESSAGE_SEGMENT_LIMIT && seperator != -1; i++)
    {
        nextSeperator = message.indexOf(SEPERATE_CHAR, seperator + 1);
        splitMessage[i] = message.substring(seperator + 1, nextSeperator);
        seperator = nextSeperator;
    }
    identifyMessage(splitMessage);
}


///Identify which kind of command is received
void identifyMessage(String message[])
{
    String identifier = message[0];
    if (identifier == REQUESTALLDATA)
    {
        sendAllSensorData(sensors, sensorCount);
    }
    else if (identifier == REQUESTDATA)
    {
        identifySensor(message, sensors, sensorCount);
    }
    else if (identifier == ERRORMODREG)
    {
    }
    else if (identifier == ERRORMODNOTREG)
    {
        moduleNotRegistered();
    }
    else if (identifier == ERRORSENSNOTREG)
    {
        sensorNotRegistered(message, sensors, sensorCount);
    }
}

///Identify of which sensor the data is requested
void identifySensor(String message[], Sensor *sensorArray[], int numberOfSensors)
{
    String sensorId = message[1];
    for (int i = 0; i < numberOfSensors; i++)
    {
        if (sensorId == sensorArray[i]->id)
        {
            sendSensorData(*(sensorArray[i]));
            return;
        }
    }
    sendErrorSensorNotAvailable(sensorId);
}

///Calls sendSensorData for each sensor connected
void sendAllSensorData(Sensor *sensorArray[], int numberOfSensors)
{
    for (int i = 0; i < numberOfSensors; i++)
    {
        sendSensorData(*(sensorArray[i]));
    }
}

///Send sensor data to ventilation box
void sendSensorData(Sensor sensor)
{
    if (!serverIdModuleIdSet())
        return;
    Serial.print(UCAST);
    Serial.print(serverId);
    Serial.print('=');
    Serial.print(START_CHAR);
    Serial.print(SENDSENSORDATA);
    Serial.print(SEPERATE_CHAR);
    Serial.print(moduleId);
    Serial.print(SEPERATE_CHAR);
    Serial.print(sensor.id);
    Serial.print(SEPERATE_CHAR);
    Serial.print(sensor.value);
    Serial.println(STOP_CHAR);
}

///Register all sensors on module with the ventilation box
void registerModule(Sensor *sensorArray[], int numberOfSensors)
{
    if (!serverIdModuleIdSet())
        return;
    Serial.print(UCAST);
    Serial.print(serverId);
    Serial.print('=');
    Serial.print(START_CHAR);
    Serial.print(moduleId);
    for (int i = 0; i < numberOfSensors; i++)
    {
        Serial.print(SEPERATE_CHAR);
        Serial.print(sensorArray[i]->id);
        Serial.print(sensorArray[i]->type);
    }
    Serial.println(STOP_CHAR);
}

///Send sensor data, should be used when spike is detected
void sendSpikeData(Sensor sensor)
{
    if (!serverIdModuleIdSet())
        return;
    Serial.print(UCAST);
    Serial.print(serverId);
    Serial.print('=');
    Serial.print(START_CHAR);
    Serial.print(SENDSPIKEDATA);
    Serial.print(SEPERATE_CHAR);
    Serial.print(moduleId);
    Serial.print(SEPERATE_CHAR);
    Serial.print(sensor.id);
    Serial.print(SEPERATE_CHAR);
    Serial.print(sensor.value);
    Serial.println(STOP_CHAR);
}

///Module is not registered with the ventilation box, try registering module
void moduleNotRegistered()
{
    registerModule(sensors, sensorCount);
}

///Sensor is not registered with the ventilation box but the module is, if sensorId on module try registering module again
void sensorNotRegistered(String message[], Sensor *sensorArray[], int numberOfSensors)
{
    String sensorId = message[1];
    bool sensorFound = false;
    for (int i = 0; i < numberOfSensors; i++)
    {
        if (sensorId == sensorArray[i]->id)
        {
            sensorFound = true;
        }
    }
    if (sensorFound)
    {
        registerModule(sensors, sensorCount);
    }
    else
    {
        //sensor not found on module
    }
}

///Sends sensorId to ventilation box of the sensor whichs data was requested
void sendErrorSensorNotAvailable(String sensorId)
{
    if (!serverIdModuleIdSet())
        return;
    Serial.print(UCAST);
    Serial.print(serverId);
    Serial.print('=');
    Serial.print(START_CHAR);
    Serial.print(ERRORNOSENSOR);
    Serial.print(SEPERATE_CHAR);
    Serial.print(sensorId);
    Serial.println(STOP_CHAR);
}

///Check if server and module id are set
bool serverIdModuleIdSet()
{
    if (serverId == EMPTY && moduleId == EMPTY)
    {
        //server and module id not set
        return false;
    }
    if (serverId == EMPTY)
    {
        //server id not set
        return false;
    }
    if (moduleId == EMPTY)
    {
        //module id not set
        return false;
    }
    return true;
}