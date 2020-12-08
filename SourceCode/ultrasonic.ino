//for more project visit www.blackkeyhole.com
#define BLYNK_PRINT Serial
#define ANALOG_PIN_0 36

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int sensorvalue=0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "xxxxxxxxxxxxxxxxxxxxx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "xxxxxxxx";
char pass[] = "xxxxxxxx";

/*
 * HC-SR04 example sketch
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 */

const int pingPin = 14; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 27; // Echo Pin of Ultrasonic Sensor
 
void setup()
{
Serial.begin(9600); // Starting Serial Terminal
Blynk.begin(auth, ssid, pass);
}
 
void loop()
{
long duration, inches, cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
Serial.print(inches);
Serial.print(" in, ");
Serial.print(cm);
Serial.print(" cm");
Serial.println();
delay(1000);
String outputvalue = String(inches)+" in, " + String(cm) + " cm";
  Blynk.virtualWrite(V3,outputvalue);
  Blynk.run();
}
 
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
