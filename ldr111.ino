#include <ThingSpeak.h>

#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#define TCP_MSS whatever
#define LWIP_IPV6 whatever
#define LWIP_FEATURES whatever
#define LWIP_OPEN_SRC whatever
const char* ssid = "JioFi3_421421"; //Your Network SSID
const char* password = "rkkt66cuvd"; //Your Network Password
int val1;  int val2;  int val3;  int val4;  int val5;
int LDRpin1 = D0;  int LDRpin2 = D1;   int LDRpin3 = D2;   int LDRpin4 = D3;      
WiFiClient client;
unsigned long myChannelNumber =662426; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "4SWGUISV2068I6FD"; //Your Write API Key
void setup()
{
Serial.begin(9600);
delay(10);
// Connect to WiFi network
WiFi.begin(ssid, password);
ThingSpeak.begin(client);
}
void loop()
{
val1 = analogRead(LDRpin1); //Read Analog values and Store in val variable
//delay(10000);
Serial.print("LDR1= "); //Print on Serial Monitor
Serial.print(val1     ); //Print on Serial Monitor
ThingSpeak.writeField(myChannelNumber, 1,val1, myWriteAPIKey); //Update in ThingSpeak


val2 = analogRead(LDRpin2); //Read Analog values and Store in val variable
Serial.print("   LDR2= "); //Print on Serial Monitor
Serial.print(val2     ); //Print on Serial Monitor
ThingSpeak.writeField(myChannelNumber, 2,val2, myWriteAPIKey); //Update in ThingSpeak


val3 = analogRead(LDRpin3); //Read Analog values and Store in val variable
Serial.print("   LDR3= "); //Print on Serial Monitor
Serial.print(val3    ); //Print on Serial Monitor
Serial.println();
ThingSpeak.writeField(myChannelNumber, 3,val3, myWriteAPIKey); //Update in ThingSpeak



}
