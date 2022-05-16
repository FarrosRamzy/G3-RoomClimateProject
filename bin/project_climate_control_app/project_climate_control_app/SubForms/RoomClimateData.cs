//using MongoDB.Driver;
using MongoDB.Bson;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace project_climate_control_app.SubForms
{
    public class RoomClimateData : CommunicationProtocol
    {
        private string data;
        private string id;
        private string payloadType;
        private string payload;

        private string temperatureValue;
        private string humidityValue;
        private string co2Value;
        private string tvocValue;
        private string manualFanSpeedInput;
        private string manualControl;

        public List<Room> listOfRooms = new List<Room>();

        public Room addDefaultRoom()
        {
            Room room = new Room("default");
            room.UpDateCo2(840);
            room.UpDateHumidity(37);
            room.UpDateTemperature(19);
            room.UpDateVoc(300);
            listOfRooms.Add(room);
            Room room1 = new Room("default1");
            room1.UpDateCo2(500);
            room1.UpDateHumidity(55);
            room1.UpDateVoc(650);
            room1.UpDateTemperature(20);
            listOfRooms.Add(room1);
            return room;
        }

        public void readInputMessage(string input)
        {
            this.data = input;
            string inputData = string.Empty;
            bool readData = false;

            foreach (char tempChar in data)
            {
                if (tempChar == startCharacter)
                {
                    readData = true;
                    inputData = string.Empty;
                }
                else if (tempChar == stopCharacter && readData == true)
                {
                    readData = false;
                    splitInputMessage(inputData);
                }
                else if (readData == true)
                {
                    inputData += tempChar;
                }
            }
        }

        private void splitInputMessage(string readMessage)
        {
            string tempString = readMessage;
            tempString = tempString.Trim(startCharacter, stopCharacter, '\r');
            string[] splittedString = tempString.Split(separateCharacter);
            defineMessage(splittedString);
        }

        private void defineMessage(string[] message)
        {
            this.id = message[0];
            this.payloadType = message[1];
            this.payload = message[2];
            defineId(id, payloadType, payload);
        }

        private void defineId(string roomId, string payloadType, string payload)
        {
            bool roomApplied = false;
            Room roomModule = null;
            foreach (Room room in listOfRooms)
            {
                if (room.roomId == roomId)
                {
                    roomApplied = true;
                    roomModule = room;
                }
            }

            if (!roomApplied)
            {
                Room newRoomModule = new Room(roomId);
                listOfRooms.Add(newRoomModule);
                definePayload(newRoomModule, payloadType, payload);
            }
            else
            {
                definePayload(roomModule, payloadType, payload);
            }
        }

        private void definePayload(Room roomModule, string payloadType, string payload)
        {
            foreach (Room room in listOfRooms)
            {
                if (roomModule.roomId == room.roomId)
                {
                    switch (payloadType)
                    {
                        case temperature:
                            temperatureValue = $"{payload:f2}";
                            float tempVal = float.Parse(temperatureValue);
                            room.UpDateTemperature(tempVal);
                            break;
                        case humidity:
                            humidityValue = $"{payload:f2}";
                            float humVal = float.Parse(humidityValue);
                            room.UpDateHumidity(humVal);
                            break;
                        case carbonDioxyde:
                            co2Value = payload;
                            int co2Val = int.Parse(co2Value);
                            room.UpDateCo2(co2Val);
                            break;
                        case volatileOrganicCompounds:
                            tvocValue = payload;
                            int vocVal = int.Parse(tvocValue);
                            room.UpDateVoc(vocVal);
                            break;
                        case fanSpeed:
                            manualFanSpeedInput = payload;
                            int speed = int.Parse(manualFanSpeedInput);
                            room.SetManualFanSpeedSpeed(speed);
                            break;
                        case control:
                            manualControl = payload;
                            if (manualControl == heating)
                            {
                                int stopFan = 0;
                                room.SetManualFanSpeedSpeed(stopFan);
                            }
                            else if (manualControl == cooling)
                            {
                                int fullSpeed = 100;
                                room.SetManualFanSpeedSpeed(fullSpeed);
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        public BsonDocument setData(Room room)
        {
            return room.GetInfo();
        }
    }
}
