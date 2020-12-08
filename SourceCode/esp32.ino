//for more project visit www.blackkeyhole.com
#define BLYNK_PRINT Serial
#define ANALOG_PIN_0 36

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int sensorvalue=0;
int outputvalue=0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "xxxxxxxxxxxxxxxxxxx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "xxxxxxxx";
char pass[] = "xxxxxxxx";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  sensorvalue=analogRead(ANALOG_PIN_0);
  outputvalue=constrain ( map(sensorvalue, 1000, 4095, 100, 0), 0, 100); //100,0 pottupaaru
  delay(1000);

  if(outputvalue>74)
  {
       Serial.println("soil is wet enough to water");
       Serial.print(outputvalue);
       Blynk.notify("soil is wet enough to water");
       delay(1000); 
  }
  else if(outputvalue<45)
  {
       Serial.println("water your plant");
       Serial.print(outputvalue);
       Blynk.notify("water your plant");
       delay(1000);
  }
  
  Blynk.virtualWrite(V5,outputvalue);
  Blynk.run();
}
