#include "wifi.h"
#include <WiFi.h> // Bibliothèque pour gérer le Wi-Fi sur ESP32
#include <Arduino.h>

// Fonction pour se connecter au réseau Wi-Fi
void connectToWiFi(const char* ssid, const char* password) {
  Serial.println("Connexion au réseau Wi-Fi...");
  WiFi.begin(ssid, password); // Connexion au réseau Wi-Fi

  while (WiFi.status() != WL_CONNECTED) { // Tant que la connexion n'est pas établie
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnecté au Wi-Fi !");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP()); // Afficher l'adresse IP attribuée
}
 