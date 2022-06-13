using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace indoor_climate_control_application.communication
{
    public class ProtocolDependencies
    {
        // Communication Protocol Separators/Organisers
        protected const string START_MESSAGE = "#";
        protected const string SEPARATE_MESSAGE_WORD = "&";
        protected const string END_MESSAGE = ";";

        // Communication Protocol Rooms System
        protected const string KITCHEN = "KITCHEN";
        protected const string BATHROOM = "BATHROOM";
        protected const string LIVING_ROOM = "LIVINGROOM";

        // Communication Protocol Devices
        protected const string SENSOR = "SENSOR";
        /* This message represents when a command is strictly meant for a 
            * sensor, and to momdify its properties*/
        protected const string MECHANICAL_COMPONENT = "MECH";
        protected const string MAIN_UI = "MAINUI";
        /* This message represents when a command is stricly meant for the 
            * user interface (UI) IN WHICH to modify a value of the
            * actual real life electrical component */

        // Communication Protocol Payload
        protected const string TEMPERATURE = "TEMP";
        protected const string HUMIDITY = "HUM";
        protected const string VOLATILE_COMPOUNDS = "VOC";
        protected const string CARBON_MONOXIDE = "CO";
        protected const string CARBON_DIOXIDE = "CO2";
        protected const string FAN = "FAN";

        // Communication Protocol Payloads States
        protected const string READ = "READ";
        protected const string WRITE = "WRITE";
        protected const string ACKNOWLEDGE = "ACK";
        protected const string NOT_ACKNOWLEDGE = "NACK";

    }
}
