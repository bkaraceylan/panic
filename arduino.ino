#include <SoftwareSerial.h>

int rxPin = 10;
int txPin = 11;
String sdata="";
int inPin = 6;
int val = 0;

SoftwareSerial esp(rxPin, txPin);

void setup() {
  pinMode(inPin, INPUT_PULLUP);
  Serial.begin(115200);
  esp.begin(115200);
 
}

void loop() {
  val = digitalRead(inPin);

  if (val == LOW) {
    esp.println("on");
    delay(5000);
  }
  
}
