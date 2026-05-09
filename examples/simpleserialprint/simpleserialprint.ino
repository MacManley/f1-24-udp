//File: simpleserialprint.ino

//#include "Wifi.h" // ESP32 WiFi include
#include <ESP8266WiFi.h> // ESP8266 WiFi include
#include <WiFiUdp.h>
#include <F1_24_UDP.h>

const char *SSID = "Your SSID";
const char *Password = "Your WiFi Password";

void startWiFi();
 
//The IP address that this ESP32 / ESP8266 has requested to be assigned to.
IPAddress ip();

F1_24_Parser* parser;

void setup() 
{ 
  parser = new F1_24_Parser();
  Serial.begin(115200);
  startWiFi();
  parser->begin();
}

void loop()
{
    parser->read();
    unsigned int playerCar = parser->packetCarTelemetryData()->m_playerCarIndex(); //Get the index of the players car in the array.
    unsigned int speed = parser->packetCarTelemetryData()->m_carTelemetryData(playerCar).m_speed; //Speed of the car, inputting "playerCar" for the speed of the players car.
    Serial.println(speed);
  }
void startWiFi()
{
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, Password);
  Serial.print("Attempting to connect to "); 
  Serial.println(SSID);
 
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(250);
 
    if ((++i % 16) == 0)
    {
      Serial.println(F(" still trying to connect"));
    }
  }
 
  Serial.print(F("Connection Successful | IP Address: "));
  Serial.println(WiFi.localIP());
}
