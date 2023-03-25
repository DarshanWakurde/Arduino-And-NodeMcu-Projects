#include <Wire.h>
#include "Adafruit_MPR121.h"
Adafruit_MPR121 pin;

void setup() {
    pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
    pinMode(11,OUTPUT);
     pinMode(10,OUTPUT);    
      pinMode(9,OUTPUT);
       pinMode(8,OUTPUT);
        pinMode(7,OUTPUT);
         pinMode(6,OUTPUT);
          pinMode(5,OUTPUT);
     
     
  // put your setup code here, to run once:
   Serial.begin(9600);

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
   if (!pin.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");


}

void loop() {
  // put your main code here, to run repeatedly:
    int touchedpin = pin.touched();
    //Serial.print(touchedpin);
    
     if(touchedpin==0)
     {
     Serial.println("no pin is touched");
     digitalWrite(0,HIGH);
     delay(100);
      digitalWrite(0,LOW);
     
     }
     if(touchedpin==1)
     {
      Serial.println("1st pin is touched");
     digitalWrite(13,HIGH);
     delay(100);
      digitalWrite(13,LOW);
     }
     if(touchedpin==2){
     Serial.println("2st pin is touched");
     digitalWrite(12,HIGH);
     delay(100);
     digitalWrite(12,LOW);
     }
     if(touchedpin==4){
     Serial.println("3st pin is touched");
     digitalWrite(11,HIGH);
     delay(100);
     digitalWrite(11,LOW);
     }
      if(touchedpin==8){
     Serial.println("4st pin is touched");
     digitalWrite(10,HIGH);
     delay(100);
     digitalWrite(10,LOW);
      }

     if(touchedpin==16)
     {
     Serial.println("5st pin is touched");
     digitalWrite(9,HIGH);
      delay(100);
     digitalWrite(9,LOW);
     }

     if(touchedpin==32)
     {
     Serial.println("6st pin is touched");
      digitalWrite(8,HIGH);
       delay(100);
     digitalWrite(8,LOW);
     }
      if(touchedpin==64)
     {
     Serial.println("7st pin is touched");
      digitalWrite(7,HIGH);
       delay(100);
     digitalWrite(7,LOW);
     }
      if(touchedpin==128)
     {
     Serial.println("8st pin is touched");
      digitalWrite(6,HIGH);
       delay(100);
     digitalWrite(6,LOW);
     }
      if(touchedpin==256)
     {
     Serial.println("9st pin is touched");
      digitalWrite(5,HIGH);
       delay(100);
     digitalWrite(5,LOW);
     }
      if(touchedpin==512)
     {
     Serial.println("10st pin is touched");
      digitalWrite(4,HIGH);
       delay(100);
     digitalWrite(4,LOW);
     }
      
     
     
     
    }


    
   
