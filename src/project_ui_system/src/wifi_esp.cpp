#include <room_system.h>

AltSoftSerial ESPserial(8, 9);

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

void runWifi(char deviceID[], char payloadType[], char payloadState[], char payload[])
{
    String message;
    message += START_CHAR;
    message += systemID;
    message += SPLIT_CHAR;
    message += deviceID;
    message += SPLIT_CHAR;
    message += payloadType;
    message += SPLIT_CHAR;
    message += PAYLOAD_START_CHAR;
    message += payloadState;
    message += PAYLOAD_SEPARATOR;
    message += payload;
    message += PAYLOAD_END_CHAR;
    message += END_CHAR;

    String completeMessage = message;

    if (connectionEstablished)
    {
        if (!sendMessage(completeMessage))
        {
            // Assume that connection has lost, then reconnect it.
            connectionEstablished = false;
            while (!startConnection())
            {
                // keep restart until it reconnected.
            }
        }
    }
    else
    {
        while (!setupEspWifi())
        {
            /* code */
        }
    }
}

bool sendMessage(String messageLine)
{
    int nrOfChar = messageLine.length() + 2;
    String Command = SEND_MESSAGE;
    Command += nrOfChar;

    String sendCommand = Command;

    ESPserial.print(sendCommand + "\r\n");
    if (!checkATresponse("OK"))
    {
        return false;
    }
    else if (checkATresponse(">"))
    {
        ESPserial.print(messageLine + "\r\n");
        return true;
    }
    else
    {
        return false;
    }
}

bool readInputMessage(String *payloadType, String *payloadState, uint32_t *payload)
{
    static bool inputStartReceive = false;
    static String inputLine;

    bool inputReceived = false;

    if (ESPserial.available())
    {
        char inputChar = ESPserial.read();
        if (inputChar == START_CHAR)
        {
            inputLine.remove(0);
            inputStartReceive = true;
        }
        else if (inputChar == END_CHAR)
        {
            inputReceived = splitInputLine(inputLine, payloadType, payloadState, payload);
            inputStartReceive = false;
        }
        else if (inputStartReceive)
        {
            inputLine += inputChar;
        }
    }

    return inputReceived;
}

bool splitInputLine(String receivedInput, String *payloadType, String *payloadState, uint32_t *payload)
{
    String splittedInputLine[INPUT_SEGMENT_LIMIT];

    int separated = 0;
    int nextSeparation = 0;
    nextSeparation = receivedInput.indexOf(SPLIT_CHAR, separated + 1);
    splittedInputLine[0] = receivedInput.substring(separated, nextSeparation);
    separated = nextSeparation;

    for (uint8_t i = 0; i < INPUT_SEGMENT_LIMIT && separated != -1; i++)
    {
        nextSeparation = receivedInput.indexOf(SPLIT_CHAR, separated + 1);
        splittedInputLine[i] = receivedInput.substring(separated, nextSeparation);
        separated = nextSeparation;
    }

    return identifyInputID(splittedInputLine, payloadType, payloadState, payload);
}

bool identifyInputID(String inputLine[], String *payloadType, String *payloadState, uint32_t *payload)
{
    String inputID = inputLine[0];
    if (inputID == systemID)
    {
        return identifyDevice(inputLine, payloadType, payloadState, payload);
    }

    return false;
}

bool identifyDevice(String inputLine[], String *payloadType, String *payloadState, uint32_t *payload)
{
    String deviceID = inputLine[1];
    if (deviceID == APP_DEVICE)
    {
        return identifyPayload(inputLine, payloadType, payloadState, payload);
    }

    return false;
}

bool identifyPayload(String inputLine[], String *payloadType, String *payloadState, uint32_t *payload)
{
    *payloadType = inputLine[2];
    String payloadData = inputLine[3];
    int payloadParamStart = payloadData.indexOf(PAYLOAD_START_CHAR);
    int payloadParamSeparator = payloadData.indexOf(PAYLOAD_SEPARATOR);
    int payloadParamEnd = payloadData.indexOf(PAYLOAD_END_CHAR);

    if ((payloadParamStart > -1) && (payloadParamSeparator > -1) && (payloadParamEnd > -1))
    {
        String readPayloadState = readPayloadState.substring(payloadParamStart, payloadParamSeparator);
        String readPayloadVal = readPayloadVal.substring(payloadParamSeparator, payloadParamEnd);

        *payloadState = readPayloadState;

        return identifyPayloadType(payloadType, payloadState, readPayloadVal, payload);
    }

    return false;
}

bool identifyPayloadType(String *inputType, String *inputState, String inputValue, uint32_t *value)
{
    if (*inputType == TEMPERATURE_TYPE)
    {
        return identifyTemperaturePayload(inputState, inputValue, value);
    }
    else if (*inputType == FAN_TYPE)
    {
        return identifyFanPayload(inputState, inputValue, value);
    }

    return false;
}

bool identifyTemperaturePayload(String *inputState, String inputValue, uint32_t *value)
{
    if (*inputState == WRITE_DATA)
    {
        uint32_t retrievedValue = inputValue.toInt();
        *value = retrievedValue;
        return true;
    }

    return false;
}

bool identifyFanPayload(String *inputState, String inputValue, uint32_t *value)
{
    if (*inputState == WRITE_DATA)
    {
        uint32_t retrievedValue = inputValue.toInt();
        *value = retrievedValue;
        return true;
    }

    return false;
}