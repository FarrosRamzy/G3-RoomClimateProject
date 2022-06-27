using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace indoor_climate_control_application.communication
{
    class Client
    {
        // This CLENT class is called like this, due to it representing an object
        // and not an action. The HANDLER for the client OR the CLENT in itslef would be
        // in this class and this class.

        TcpClient clientSocket;
        string clNo;

        public Client(TcpClient inClientSocket, string clineNo)
        {
            this.clientSocket = inClientSocket;
            this.clNo = clineNo;
        }

        public void StartClient ()
        {
            Thread ctThread = new Thread(Communicate);
            ctThread.Start();
        }

        private void Communicate ()
        {
            int requestCount = 0;
            byte[] bytesFrom = new byte[10025];
            string dataFromClient = null;
            Byte[] sendBytes = null;
            string serverResponse = null;
            string rCount = null;
            requestCount = 0;
            int i;

            while ((true))
            {
                try
                {
                    NetworkStream networkStream = clientSocket.GetStream();
                    if((i = networkStream.Read(bytesFrom, 0, bytesFrom.Length)) != 0)
                    {
                        requestCount = requestCount + 1;
                        dataFromClient = System.Text.Encoding.ASCII.GetString(bytesFrom);
                        try
                        {
                            // here we decode the received data
                        }
                        catch (ArgumentOutOfRangeException)
                        {
                            dataFromClient = string.Empty;
                        }   
                        
                        if(dataFromClient != string.Empty)
                        {
                            //Console.WriteLine(" >> " + " From client- " + clNo + " " + dataFromClient);

                            rCount = Convert.ToString(requestCount);
                            //Console.Write(" >> " + "Input response for client -> ");
                            
                            //Here we make the reply to the system


                            serverResponse += "\n";
                            sendBytes = Encoding.ASCII.GetBytes(serverResponse);
                            networkStream.Write(sendBytes, 0, sendBytes.Length);
                            networkStream.Flush();
                            //Console.WriteLine(" >> " + serverResponse);
                        }
                    }
                }
                catch (Exception ex)
                {
                    throw ex;
                }
            }
        }
        
    }
}
