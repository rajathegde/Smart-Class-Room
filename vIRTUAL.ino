/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "984a6841bff34f2290d8c96c11661975";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "CCPLAB-WiFi";
char pass[] = "";
WidgetLCD lcd(V127);
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);
    pinMode(D1,OUTPUT);
      pinMode(D2,OUTPUT);
        pinMode(D3,OUTPUT);
          pinMode(D5,OUTPUT);
            pinMode(D6,OUTPUT);
              pinMode(D7,OUTPUT);
                pinMode(D8,OUTPUT);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
}
BLYNK_WRITE(V0)
{
  int pinValue=param.asInt();
  digitalWrite(D0,pinValue);
  lcd.print(0,0,pinValue);
}
BLYNK_WRITE(V1)
{
  int pinValue=param.asInt();
  digitalWrite(D1,pinValue);
}
BLYNK_WRITE(V2)
{
  int pinValue=param.asInt();
  digitalWrite(D2,pinValue);
}
BLYNK_WRITE(V3)
{
  int pinValue=param.asInt();
  digitalWrite(D3,pinValue);
}
BLYNK_WRITE(V4)
{
  int pinValue=param.asInt();
  digitalWrite(D5,pinValue);
}
BLYNK_WRITE(V5)
{
  int pinValue=param.asInt();
  digitalWrite(D6,pinValue);
}
BLYNK_WRITE(V6)
{
  int pinValue=param.asInt();
  digitalWrite(D7,pinValue);
}
BLYNK_WRITE(V7)
{
  int pinValue=param.asInt();
  digitalWrite(D8,pinValue);
}
void loop()
{
  Blynk.run();
}

