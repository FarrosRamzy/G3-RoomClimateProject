using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;

namespace indoor_climate_control_application.communication
{
    enum ServerConditions
    {
        IDLE,
        WELCOME,
        DATA_INQURY,
        STOP
            // MAYBE RESTRUCTURE ON THIS, BUT IT MIGHT NOT HAPPEN
    };

    public class Server : ProtocolDependencies
    {
        private string ip_address;
        private int port;

        public Server (string ip, int port)
        {
            this.ip_address = ip;
            this.port = port;
        }

        public void run_server(ref Label status)
        {
            //Console.Clear();
            IPAddress ipInstance = IPAddress.Parse(ip_address);
            TcpListener serverSocket = new TcpListener(ipInstance, port);
            TcpClient clientSocket = default(TcpClient);
            int counter = 0;
            status.Text = "Communication online";

            serverSocket.Start();
            //Console.WriteLine(" >> " + "Server Started");

            counter = 0;
            while (true)
            {
                counter += 1;
                clientSocket = serverSocket.AcceptTcpClient();
                //Console.WriteLine(" >> " + "Client No:" + Convert.ToString(counter) + " started!");
                Client handleClient = new Client(clientSocket, Convert.ToString(counter));
                handleClient.StartClient();
            }

            clientSocket.Close();
            serverSocket.Stop();
            //Console.WriteLine(" >> " + "exit");
            //Console.ReadLine();

        }
    }
}
