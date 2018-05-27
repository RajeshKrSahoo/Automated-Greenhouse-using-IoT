# Automated-Greenhouse-using-IoT
Monitoring the internal parameters of greenhouse like temperature and humidity and controlling the devices remotely using IoT.

Propose contribution to the development of a prototype of an automated greenhouse monitoring and control system. This project presents the design and development of an electronic system based on a Wi-Fi embedded microcontroller that integrates remote sensing functions rooted in the cloud computing using internet of things (IoT). The system allows the acquisition of different climatic parameters in an agricultural greenhouse and in addition, this electronic system achieves the remote controlling of climatic parameters, by cloud computing solutions (internet of things). 


## Devices and Apps Used:
1.*NodeMCU*:NodeMcu is an open source IOT platform. It includes firmware which runs on the ESP8266 wi-fi soc, and hardware which is based on the ESP-12 module. Basically you can say it's a integrated platform of ESP8266 wifi module and Arduino platform, so that you need not worry about circuit connection of WiFi Module with Arduino individually with wires which creates a problem while connecting to the internet.

![image](https://user-images.githubusercontent.com/27301175/40587522-a297693c-61ed-11e8-88a3-5e7b2ce0ef5f.png)

2.*Blynk App*: BLYNK is not just "another iot cloud". It's an end-to-end solution which saves our time and resources when building applications for connected products and services.You can download its app from Google play store for your mobile device.
Which have a great GUI experience for the mobile device which in turns connects to the Blynk cloud by auth keys:
which is been produced at the time app installation and creating your account.
Below is the code to connect to the server from NodeMCu
```ruby
#define BLYNK_PRINT Serial   
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "2ffa1479e3f44670bb500821d3e8030b"; //Authentication Code from Blynk Server by which we will connect to the cloud server

void setup()
{
Serial.begin(115200);   //Setting the baud rate to display for PC and NodeMCU
Blynk.begin(auth, "SSID", "pwd");  //ssid-,pswd for to connect the WiFI
}
```

![image](https://user-images.githubusercontent.com/27301175/40587547-fea179ca-61ed-11e8-9702-33fb108dc4d8.png)


3. **Other components used**: DHT11 temperature and humidity sensor, 2 Channel relay, 12V DC Brushless motor, 3-6V Submersive water pump and 100 Watt incandescent light bulb.

### Workflow of the project::


