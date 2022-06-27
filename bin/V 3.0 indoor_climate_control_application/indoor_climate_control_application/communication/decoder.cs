using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace indoor_climate_control_application.communication
{
    class decoder : ProtocolDependencies
    {
        private string incomingMessage;

        public decoder ()
        {

        }

        public string message_to_decode
        {
            set
            {
                if (value != null || value != "")
                    incomingMessage = value;
                else
                    throw new ArgumentException();
            }
        }

        public string receivedToRaw ()
        {
            //#BEDROOM&SENSOR&TEMP&{READ|20};
            string rawMessage = "";
            try
            {
                int start = incomingMessage.IndexOf(START_MESSAGE);
                int end = incomingMessage.IndexOf(END_MESSAGE);
                if (start == -1 || end == -1)
                    throw new ArgumentException();
                // indexOf -> the first occurence of the char in the paranthesis
                rawMessage = incomingMessage.Substring(start, end);
                if (rawMessage == string.Empty || rawMessage == "")
                    throw new ArgumentException();
            }
            catch(ArgumentNullException ex)
            {
                throw ex;
            }
            catch(ArgumentOutOfRangeException ex)
            {
                throw ex;
            }
            catch(Exception ex)
            {
                throw ex;
            }
            // EndResult -> BEDROOM&SENSOR&TEMP&{READ|20}
            return rawMessage;
        }

        public static string messageExtract_Room (string message, ref string message_remainder)
        {
            // BEDROOM&SENSOR&TEMP&{READ|20}
            string result = "";
            try
            {
                int separator = message.IndexOf(SEPARATE_MESSAGE_WORD);
                result = message.Substring(0, separator);
                message_remainder = message.Substring(separator, message.Length);
                if (result == string.Empty || result == "" || message_remainder == string.Empty)
                    throw new ArgumentException();
                if (!checkMessage_Room(result))
                    throw new ArgumentException();
            }
            catch (ArgumentNullException ex)
            {
                throw ex;
            }
            catch (ArgumentOutOfRangeException ex)
            {
                throw ex;
            }
            catch (Exception ex)
            {
                throw ex;
            }
            // EndResult -> BEDROOM
            // EndResult -> SENSOR&TEMP&{READ|20}
            return result;
        }

        public static string messageExtract_Device(string message, ref string message_remainder)
        {
            // SENSOR&TEMP&{READ|20}
            string result = "";
            try
            {
                int separator = message.IndexOf(SEPARATE_MESSAGE_WORD);
                result = message.Substring(0, separator);
                message_remainder = message.Substring(separator, message.Length);
                if (result == string.Empty || result == "" || message_remainder == string.Empty)
                    throw new ArgumentException();
                if (!checkMessage_Device(result))
                    throw new ArgumentException();
            }
            catch (ArgumentNullException ex)
            {
                throw ex;
            }
            catch (ArgumentOutOfRangeException ex)
            {
                throw ex;
            }
            catch (Exception ex)
            {
                throw ex;
            }
            // EndResult -> SENSOR
            // EndResult -> TEMP&{READ|20}
            return result;
        }

        public static string messageExtract_Payload(string message, ref string message_remainder)
        {
            // TEMP&{READ|20}
            string result = "";
            try
            {
                int separator = message.IndexOf(SEPARATE_MESSAGE_WORD);
                result = message.Substring(0, separator);
                message_remainder = message.Substring(separator, message.Length);
                if (result == string.Empty || result == "" || message_remainder == string.Empty)
                    throw new ArgumentException();
                if (!checkMessage_Payload(result))
                    throw new ArgumentException();
            }
            catch (ArgumentNullException ex)
            {
                throw ex;
            }
            catch (ArgumentOutOfRangeException ex)
            {
                throw ex;
            }
            catch (Exception ex)
            {
                throw ex;
            }
            // EndResult -> TEMP
            // EndResult -> {READ|20}
            return result;
        }

        public static bool checkMessage_Room(string text)
        {
            if (text == KITCHEN)
                return true;
            if (text == BATHROOM)
                return true;
            if (text == LIVING_ROOM)
                return true;
            return false;
        }

        public static bool checkMessage_Device(string text)
        {
            if (text == SENSOR)
                return true;
            if (text == MECHANICAL_COMPONENT)
                return true;
            if (text == MAIN_UI)
                return true;
            return false;
        }

        public static bool checkMessage_Payload(string text)
        {
            if (text == TEMPERATURE)
                return true;
            if (text == HUMIDITY)
                return true;
            if (text == VOLATILE_COMPOUNDS)
                return true;
            if (text == CARBON_MONOXIDE)
                return true;
            if (text == CARBON_DIOXIDE)
                return true;
            if (text == FAN)
                return true;
            return false;
        }
    }
}
