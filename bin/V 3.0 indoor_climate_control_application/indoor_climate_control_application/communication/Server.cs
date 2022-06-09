using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace indoor_climate_control_application.communication
{
    enum ServerConditions
    {
        IDLE,
        WELCOME,
        DATA_INQURY,
        STOP
    };

    class Server : ProtocolDependencies
    {

        public Server ()
        {

        }

        public void Inisialise ()
        {
            
        }
    }
}
