#include <Arduino.h>
#include "wifi.h"

// Informations du réseau Wi-Fi
const char* ssid = "NomDuRéseau";
const char* password = "MotDePasse";

void setup() {
  Serial.begin(115200); // Initialise la communication série

  // Connexion au Wi-Fi
  connectToWiFi(ssid, password);
}

void loop() {
  // Laisse vide pour tester la connexion
}
 