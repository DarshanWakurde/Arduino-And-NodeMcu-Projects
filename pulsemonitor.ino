int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;   //  The on-board Arduion LED
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
char ssid[] = "DARSHAN"; //SSID
char pass[] = "12345678"; // Password
//-------------------------------------
int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 760;
unsigned long myChannelNumber = 1788702; // Channel ID here
const int FieldNumber = 1;
const char * myWriteAPIKey = "WLT2XAZ6F0128KLI";
WiFiClient  client;
void setup() {
Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
 Serial.println("Connecting to ");
       Serial.println(ssid); 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
   ThingSpeak.begin(client);


  
  // put your setup code here, to run once:
  pinMode(LED13,OUTPUT);         // pin that will blink to your heartbeat!
   Serial.begin(115200); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal = analogRead(PulseSensorPurplePin); 
  float bpm=Signal/10;// Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.

   Serial.println(bpm);                    // Send the Signal value to Serial Plotter.
delay(100);

   if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     digitalWrite(LED13,HIGH);
   } else {
     digitalWrite(LED13,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }

ThingSpeak.writeField(myChannelNumber, FieldNumber, bpm, myWriteAPIKey);
delay(10);
}
