#include <ESP8266WiFi.h>
#define TRIG 16 //D0
#define ECHO 5 //D1
int cm;
void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.begin(9600); 
}

void loop() {
  cm = readDistance();
  Serial.print("cm :");
  Serial.println(cm);
  delay(100); 
}

int readDistance(void){
  digitalWrite(TRIG,0);
  delayMicroseconds(2);
  digitalWrite(TRIG,1);
  delayMicroseconds(10);
  digitalWrite(TRIG,0);
  int d = pulseIn(ECHO,HIGH);
  int s = 0.034*d/2;
  return s;
}
