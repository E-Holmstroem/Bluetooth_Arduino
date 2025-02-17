#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX
char oldCom;

void setup() {
    Serial.begin(9600);
    BT.begin(9600);
    pinMode(7, OUTPUT);
    Serial.println("Servo Bluetooth Ready");
}

void loop() {
  if (BT.available()) {
    char command = BT.read();
    Serial.print("Received: ");
    Serial.println(command);

    if (oldCom == command){
      
    }
    else if (command == 'F') {
      digitalWrite(7, HIGH);
      Serial.println("ON");
    } 
    else if (command == 'B') {
      digitalWrite(7, LOW);
      Serial.println("OFF");
    }
  oldCom = command;
  }
}
