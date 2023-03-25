
#include <SimpleDHT.h>                 



int pinDHT11 = 13;
SimpleDHT11 dht11(pinDHT11);
byte hum = 0;  //Stores humidity value
byte temp = 0; //Stores temperature value
void setup() {
  Serial.begin(9600);
  pinMode(0,INPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  
  }

void loop() {
 
  
  dht11.read(&temp, &hum, NULL);
  Serial.print((int)temp); Serial.print(" *C, "); 
  Serial.print((int)hum); Serial.println(" H");
  delay(100);
  if(temp>"35")
  {
    digitalWrite(1,HIGH);
  }
  else
  {
    digitalWrite(1,LOW);
  }
  }
  
