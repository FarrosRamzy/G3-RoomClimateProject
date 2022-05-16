using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Main_Panel_Controls
{
    public static class WeatherCity
    {
        private static string cityForWeather;
        private static string defaultCity = "Eindhoven";
        private static bool WeatherServerConnected = false;

        public static string GetDefaultCity { get => defaultCity; }
        public static string GetNewCity { get => cityForWeather; }
        public static string SetCity { set => cityForWeather = value; }
        public static bool SetServerInfo { set => WeatherServerConnected = value; }
        public static bool GetServerInfo { get => WeatherServerConnected; }
    }
}
