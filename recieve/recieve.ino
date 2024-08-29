#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Receiver"); // Name des Bluetooth-Geräts
  Serial.println("Bluetooth-Gerät bereit zur Verbindung.");
}

void loop() {
  if (SerialBT.available()) {
    String receivedMessage = SerialBT.readString(); // Nachricht empfangen
    Serial.println("Nachricht empfangen: " + receivedMessage);
  }
}
