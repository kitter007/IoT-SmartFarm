//   https://meyerweb.com/eric/tools/dencoder/
//   https://notify-bot.line.me/my/

#include <ESP8266WiFi.h>

#define WIFI_SSID ""
#define WIFI_PASSWORD ""
#define LINE_TOKEN ""
#define ledPin 16

String message = "";
void Line_Notify(String message) ;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.println("HIGH");
  digitalWrite(ledPin,HIGH);
  delay(5000);
    
  Serial.println("LOW");
  digitalWrite(ledPin,LOW);
  delay(5000);
    
  if(ledPin != HIGH) {
    Line_Notify(message);
  }
}
void Line_Notify(String message) {
  WiFiClientSecure client;
  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;   
  }
  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Connection: close\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  client.print(req);
  delay(20);
}
