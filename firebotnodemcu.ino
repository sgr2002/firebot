#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID   "TMPLM0XYaBp-"
#define BLYNK_DEVICE_NAME "Mini Project"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTTYPE DHT11
#define dht_dpin D6
DHT dht(dht_dpin, DHTTYPE);
const char auth[] = "m2P5CSvouQreK0zuGGfsN8IQExHGRmlE";
const char ssid[] = "vivo1901";
const char pass[] = "gothilla";
BLYNK_WRITE(V0) {
  if(param.asInt()==1)
  {
      digitalWrite(D1,HIGH);
  }
  else
  {
      digitalWrite(D1,LOW);
  }
}
BLYNK_WRITE(V1) {
  if(param.asInt()==1)
  {
      digitalWrite(D2,HIGH);
      digitalWrite(D3,LOW);
      digitalWrite(D4,LOW);
      digitalWrite(D5,LOW);
  }
  else
  {
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
  }
}
BLYNK_WRITE(V2) {
  if(param.asInt()==1)
  {
      digitalWrite(D2,LOW);
      digitalWrite(D3,HIGH);
      digitalWrite(D4,LOW);
      digitalWrite(D5,LOW);
  }
  else
  {
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
  }
}
BLYNK_WRITE(V3) {
  if(param.asInt()==1)
  {
      digitalWrite(D2,LOW);
      digitalWrite(D3,LOW);
      digitalWrite(D4,HIGH);
      digitalWrite(D5,LOW);
  }
  else
  {
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
  }
}
BLYNK_WRITE(V4) {
  if(param.asInt()==1)
  {
      digitalWrite(D2,LOW);
      digitalWrite(D3,LOW);
      digitalWrite(D4,LOW);
      digitalWrite(D5,HIGH);
  }
  else
  {
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
  }
}
BLYNK_WRITE(V7) {
  if(param.asInt()==1)
  {
      digitalWrite(D7,HIGH);
  }
  else
  {
      digitalWrite(D7,LOW);
  }
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D7,OUTPUT);
  dht.begin();
}
void loop()
{
  Blynk.run();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println(t);
  Serial.println(h);
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
}
