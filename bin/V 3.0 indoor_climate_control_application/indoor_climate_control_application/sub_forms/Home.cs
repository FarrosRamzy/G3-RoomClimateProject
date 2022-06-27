using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using indoor_climate_control_application.communication;

namespace indoor_climate_control_application.subForms
{
    public partial class Home : Form
    {
        Server CommunicationWay;

        public Home(Server CommunicationWay)
        {
            InitializeComponent();
            this.CommunicationWay = CommunicationWay;
        }

        private void Home_Load(object sender, EventArgs e)
        {
            try
            {
                CommunicationWay.run_server(ref lbCommunicationStatus);
            }
            catch (Exception)
            {
                lbCommunicationStatus.Text = "Communication Severed";
            }
        }

    }
}
