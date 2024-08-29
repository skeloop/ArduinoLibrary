#include "BluetoothMessenger.h"
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

String receiveMessage() {
  if (SerialBT.available()) {
    return SerialBT.readString();
  }
  return "";
}

void sendMessage(const String& message) {
  SerialBT.print(message);
}

void begin(const String& name) {
  if (!SerialBT.begin(name.c_str())) {
    Serial.println("An error occurred initializing Bluetooth.");
  } else {
    Serial.print("Bluetooth device started: ");
    Serial.println(name);
  }
}