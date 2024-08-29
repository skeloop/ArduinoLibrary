#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Sender"); // Name des Bluetooth-Geräts
  Serial.println("Bluetooth-Gerät bereit zur Verbindung.");
}

void loop() {
  String message = "Hallo vom ESP!";
  SerialBT.println(message); // Senden der Nachricht
  Serial.println("Nachricht gesendet: " + message);
  delay(2000); // Sende alle 2 Sekunden
}
