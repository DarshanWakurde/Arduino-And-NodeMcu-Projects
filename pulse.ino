#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library
// nodemcu module connected here
 
const int PulseWire = 0;       // 'S' Signal pin connected to A0
const int LED13 = LED_BUILTIN;          // The on-board Arduino LED
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore
String myString;
String cmessage; // complete message
char buff[10];
 
PulseSensorPlayground pulseSensor;  // Creates an object
 
void setup()
{
  Serial.begin(9600);

 
  // Configure the PulseSensor object, by assigning our variables to it
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13);       // Blink on-board LED with heartbeat
  pulseSensor.setThreshold(Threshold);
 
  // Double-check the "pulseSensor" object was created and began seeing a signal
  if (pulseSensor.begin())
  {
    Serial.println("PulseSensor object created!");
  }
}
 
void loop()
{
  int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM
 
  if (pulseSensor.sawStartOfBeat()) // Constantly test to see if a beat happened
  {
    Serial.println("♥  A HeartBeat Happened ! "); // If true, print a message
    Serial.print("BPM: ");
    Serial.println(myBPM);                        // Print the BPM value
    myString = dtostrf(myBPM, 3, 0, buff);
    cmessage = cmessage + myString ;

    Serial.println(cmessage);
    cmessage = "";
    Serial.println();
  }
  delay(20);
}
