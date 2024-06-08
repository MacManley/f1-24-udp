//File: drsLight.ino

//#include "Wifi.h" // ESP32 WiFi include
#include <ESP8266WiFi.h> // ESP8266 WiFi include
#include <WiFiUdp.h>
#include <F1_24_UDP.h>

const char *SSID = "Your SSID";
const char *Password = "Your WiFi Password";

void startWiFi();

F1_24_Parser* parser;

void setup() 
{ 
  parser = new F1_24_Parser();
  Serial.begin(115200);
  startWiFi();
  parser->begin();
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
      parser->read();
      unsigned int playerCar = parser->packetCarTelemetryData()->m_playerCarIndex(); // Get the index of the players car in the array.
      uint8_t drs = parser->packetCarTelemetryData()->m_carTelemetryData(playerCar).m_drs; // DRS assigned as a uint8_t, 0 - OFF, 1 - ON
      if (drs) {
        digitalWrite(LED_BUILTIN, LOW); 
        Serial.println("DRS Enabled");
      } else {
        digitalWrite(LED_BUILTIN, HIGH);
      } // Some boards turn on LED when pulled LOW, others HIGH, invert if there are issues.
      delay(250);
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