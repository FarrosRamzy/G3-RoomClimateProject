#include <room_system.h>

AltSoftSerial ESPserial(8,9);

bool connectionEstablished;
bool connectionStarted;
bool joinAP;
bool statusOK;

String systemID;

bool setupEspWifi()
{
    ESPserial.begin(9600);
    connectionEstablished = false;
    ESPserial.print(STOP_ECHO "\r\n");
    if (checkATresponse("\r\nOK"))
    {
        if (setConnectionMode())
        {
            if (!checkAccessPoint())
            {
                if (!joinAccessPoint())
                {
                    if (checkConnectionStatus())
                    {
                        return true;
                    }
                    else
                    {
                        if (startConnection())
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (checkConnectionStatus())
                {
                    return true;
                }
                else
                {
                    if (startConnection())
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool setConnectionMode()
{
    ESPserial.print(SET_WIFI_MODE "\r\n");
    bool modeChanged = checkATresponse("\r\nOK");
    return modeChanged;
}

bool checkAccessPoint()
{
    ESPserial.print(CHECK_ACC_POINT "\r\n");
    bool apStatus = false;
    bool noAP = checkATresponse("No AP");
    if (noAP)
    {
        if (checkATresponse("\r\nOK"))
        {
            apStatus = false;
        }
        else
        {
            apStatus = false;
        }
    }
    else if (!noAP)
    {
        if (checkATresponse("\r\nOK"))
        {
            apStatus = true;
        }
        else
        {
            apStatus = false;
        }
    }
    return apStatus;
}

bool joinAccessPoint()
{
    Serial.print(JOIN_ACC_POINT "\"" WIFI_ID "\",\"" WIFI_PASSWORD "\"\r\n");
    ESPserial.print(JOIN_ACC_POINT "\"" WIFI_ID "\",\"" WIFI_PASSWORD "\"\r\n");
    if (checkATresponse("WIFI CONNECTED"))
    {
        if (checkATresponse("WIFI GOT IP"))
        {
            if (checkATresponse("\r\nOK"))
            {
                joinAP = true;
            }
            else
            {
                joinAP = false;
            }
        }
        else
        {
            joinAP = false;
        }
    }
    else
    {
        joinAP = false;
    }
    return joinAP;
}

bool checkConnectionStatus()
{
    ESPserial.print(CHECK_STATUS "\r\n");
    bool correctStatus = checkATresponse("STATUS:3");
    if (correctStatus)
    {
        if (checkATresponse("\r\nOK"))
        {
            statusOK = true;
        }
        else
        {
            statusOK = false;
        }
    }
    else if (!correctStatus)
    {
        statusOK = false;
    }
    return statusOK;
}

bool startConnection()
{
    ESPserial.print(START_COMMUNICATION "\"" TCP "\",\"" SERVER_IP "\"," SERVER_PORT "\r\n");
    if (checkATresponse("CONNECT"))
    {
        if (checkATresponse("\r\nOK"))
        {
            getSystemID();
            connectionEstablished = true;
            connectionStarted = true;
        }
        else
        {
            connectionStarted = false;
            connectionEstablished = false;
        }
    }
    else
    {
        connectionStarted = false;
    }
    return connectionStarted;
}

void getSystemID()
{
    systemID = "";
    bool getMacAddress = false;
    ESPserial.print(GET_MAC_ADDRESS "\r\n");

    if (checkATresponse("+CIPSTAMAC:"))
    {
        while (!getMacAddress)
        {
            systemID = ESPserial.readStringUntil('\n');
            systemID.replace("\"", "");
            systemID.trim();
            getMacAddress = true;
        }
    }
}

bool checkATresponse(String message)
{
    unsigned long MessageStartTime = millis();
    int strlen = message.length() + 1;
    char espreply[strlen];

    message.toCharArray(espreply, strlen);
    int i = 0;

    while (true)
    {
        if (ESPserial.find(espreply[i]))
        {
            i++;
        }
        if (i == strlen - 1)
        {
            return true;
        }
        if (millis() - MessageStartTime > MAX_PROCESS_TIMER)
        {
            MessageStartTime = millis();
            return false;
        }
    }
}