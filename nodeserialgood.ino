#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
const int LM35 = A0;
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "DARSHAN"; //SSID
char pass[] = "12345678"; // Password
//-------------------------------------------//
WiFiClient  client;
unsigned long myChannelNumber = 1788702; // Channel ID here
const int FieldNumber = 1;
const int FieldNumber2 = 2;
const char * myWriteAPIKey = "WLT2XAZ6F0128KLI"; // Your Write API Key here
int puls;
int temp;
void setup() {
// Open serial communications and wait for port to open:
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
}
void loop() { // run over and over
if (Serial.available()) {
puls=Serial.read();
Serial.write(puls);
ThingSpeak.writeField(myChannelNumber, FieldNumber, puls, myWriteAPIKey);
}
 int ADC;
  float temp;
  ADC = analogRead(LM35);  /* Read Temperature */
  temp = (ADC * 3); /* Convert adc value to equivalent voltage */
  temp = (temp / 10); /* LM35 gives output of 10mv/°C */
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, FieldNumber2, temp, myWriteAPIKey);
}
