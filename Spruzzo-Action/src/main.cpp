#include <Arduino.h>
#include "wifi.h"

// Informations du réseau Wi-Fi
const char* ssid = "ESP-WROOM-32";
const char* password = "2AC7Z-ESP32WROOM32";

void setup() {
  Serial.begin(115200); // Initialise la communication série

  // Connexion au Wi-Fi
  connectToWiFi(ssid, password);
}

void loop() {
  // Laisse vide pour tester la connexion
}
 