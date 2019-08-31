#include <ESP8266WiFi.h>
int ldr_value = 0;
void setup(){
  Serial.begin(9600);
}

void loop(){
  ldr_value = analogRead(A0); 
  Serial.println(ldr_value);
  delay(100);
}
