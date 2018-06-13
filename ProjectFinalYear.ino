//Working Code Final Year Project Tested Use
#define BLYNK_PRINT Serial    //
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include "DHT.h"           //Library for DHT11 Sensor
#define DHTPIN D4         // The pin we connect to get the input from DHt 
#define DHTTYPE DHT11     // DHT 11 -->>if DHT 22 then write it DHT22
DHT dht(DHTPIN, DHTTYPE, 16); 
SimpleTimer timer;        
float tem;
float hum;
char auth[] = "2ffa1479e3f44670bb500821d3e8030b"; //Authentication Code from Blynk Server by which we will connect to the cloud server
void setup()
{
  
  //pinMode(D7,OUTPUT);
  //pinMode(D6,OUTPUT);
  digitalWrite(D7,LOW);   //for light D7
  digitalWrite(D6,LOW);   //for fan   D6
  digitalWrite(D5,LOW);   //For Automatic Mode D5 we used 
  Serial.begin(115200);   //Setting the baud rate to display for PC and NodeMCU
  Blynk.begin(auth, "xxxxxxx", "xxxxxxxxxxx");  //ssid-raja,pswd-static80 for to connect the WiFI
  timer.setInterval(2000, sendDHT);    //Every 2sec it will send the data from DHT to the Internet Blynk server and NodeMCU will blink
}

void sendDHT()
{
  //Read the Temp and Humidity from DHT
  hum = dht.readHumidity();
  tem = dht.readTemperature();   //reading temp data from DHT11
  //int hum = (int) h;
  //tem = (int) t;
  //Write values to V04 and V05
  Blynk.virtualWrite(4, hum);  //Humidity-->V04
  Blynk.virtualWrite(5, tem);  //temp-->    V05
}
void loop()
{
  //Algo For to activate Automative mode 
  int vir8 = digitalRead(D5);
  if(vir8>=1)
  {
    //Serial.println("loop working");
  if (tem>=33)
  {
    digitalWrite(D7,HIGH);
    digitalWrite(D6,LOW);
    //delay(200);
  }
  else if(tem<33)
  {     
    digitalWrite(D7,LOW);    
    digitalWrite(D6,HIGH);
    //delay(200);
  }
  }
  //Serial.println(t);
  //Serial.println(vir8);
  Blynk.run();  //to connect and run the scripts in the Blynk Server
  timer.run();  //To run and send the DHT data 
}

