#ifndef BLUETOOTHMESSENGER_H
#define BLUETOOTHMESSENGER_H

#include <Arduino.h> // Include this to ensure String is recognized

void sendMessage(const String& message);
String receiveMessage();
void begin(const String& name);

#endif // BLUETOOTHMESSENGER_H