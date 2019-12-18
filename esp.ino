#include "CTBot.h"
CTBot myBot;

String ssid  = "freewifi"; 
String pass  = "freewifi";
String token = "yourbottoken";
uint8_t led = 2; 
int chatid = 11111111; //change for specific chat
String sdata = "";
void setup() {
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

  myBot.wifiConnect(ssid, pass);

  myBot.setTelegramToken(token);

  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");
}

void loop() {
  TBMessage msg;
  byte ch;
  
  if (Serial.available()) {
    ch = Serial.read();
    sdata += (char)ch;

    if(ch == 10) {
      sdata.trim();
      Serial.println(sdata);
      if (sdata == "on") {
        myBot.sendMessage(chatid, "Alarm!");
      }
      sdata = "";
    }
    
  }

  delay(500);
}
