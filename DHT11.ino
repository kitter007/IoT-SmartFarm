#include <ESP8266WiFi.h>
#include "DHT.h"

#define DHT11PIN 16  //D0
DHT dht;

int humidity;
int temperature;

void setup(){
  Serial.begin(9600);
  dht.setup(DHT11PIN);
}

void loop(){
  humidity = dht.getHumidity();/* Get humidity value */
  temperature = dht.getTemperature();/* Get temperature value */
  if (!isnan(humidity) || !isnan(temperature)) {
      Serial.print("Hum : ");
      Serial.println(humidity, 1);
      Serial.print("Temp : ");
      Serial.println(temperature, 1); 
    }
    delay(1000);
}
