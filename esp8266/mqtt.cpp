#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
 
// Connect to the WiFi
const char* ssid = "your_wifi_name";
const char* password = "your_wifi_password";
const char* mqtt_server = "your_mqtt_server";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
const byte ledPin = D4; // Pin with LED on Adafruit Huzzah
 
void callback(char* topic, byte* payload, unsigned int length) {
 Serial.print("Message arrived [");
 Serial.print(topic);
 Serial.print("] ");
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '1')
  // ESP8266 Huzzah outputs are "reversed"
  digitalWrite(ledPin, HIGH);
  if (receivedChar == '0')
   digitalWrite(ledPin, LOW);
  }
  Serial.println();
}
 
 
void reconnect() {
 // Loop until we're reconnected
 while (!client.connected()) {
 Serial.print("Attempting MQTT connection...");
 // Attempt to connect
 if (client.connect("ESP8266 Client")) {
  Serial.println("connected");
  // ... and subscribe to topic
  client.subscribe("ledStatus");
 } else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
  }
 }
}
 
void setup()
{
 Serial.begin(9600);
 
 client.setServer(mqtt_server, 1883);
 client.setCallback(callback);
 
 pinMode(ledPin, OUTPUT);
}
 
void loop()
{
 if (!client.connected()) {
  reconnect();
 }
 client.loop();
}
