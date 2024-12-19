#include <Arduino.h>
#include "mouvement.h"
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
 

void setup() {
  setupMouvement();
}

void loop() {
  avancer(125);
  delay(3000);

  tournerGauche(125);
  delay(2000);

  tournerDroite(125);
  delay(2000);

  reculer(125);
  delay(3000);

  arreter();
  delay(2000);
}
