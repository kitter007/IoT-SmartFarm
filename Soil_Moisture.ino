#include <ESP8266WiFi.h>

int moisture;
void setup(){
  Serial.begin(9600);
}

void loop(){
  moisture = analogRead(A0);
  Serial.println(moisture);
  delay(500);
}
