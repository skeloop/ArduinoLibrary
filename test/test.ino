#include <BluetoothMessenger.h>

int blau = 22;
int grun = 21;
int rot = 19;


void setup() {
  // put your setup code here, to run once:
  pinMode(17, INPUT_PULLDOWN);  //Bluetooth aktivieren
  pinMode(23, INPUT_PULLDOWN);  //Senden


  pinMode(blau, OUTPUT);  //Blau
  pinMode(grun, OUTPUT);  //Grün
  pinMode(rot, OUTPUT);   //Rot

  digitalWrite(blau, LOW);
  digitalWrite(grun, LOW);
  digitalWrite(rot, LOW);
}

void loop() {
  return;
  // Test UNIT
  digitalWrite(rot, HIGH);

  // Verbindungsaufbau aktivieren
  if (digitalRead(17) == HIGH) {
    // Aktiviere Bluetooth
    digitalWrite(rot, LOW);
    begin("ESP");
    digitalWrite(blau, HIGH);
    delay(1000);
    digitalWrite(blau, LOW);
    return;


    while (true) {
      // Nachricht senden um zu überprüfen ob eine Kommunikation stattfindet
      sendMessage("connect");
      delay(100);
      // Falls die Nachricht auf B angekommen ist wird eine Antwort gesendet.
      if (receiveMessage() == "done") {
        digitalWrite(grun, HIGH);
      }
      // Wenn eine Nachricht von A kommt sende eine Antwort
      else if (receiveMessage() == "hello") {
        sendMessage("done");
      }
    }
  }
}