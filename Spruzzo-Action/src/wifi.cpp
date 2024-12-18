#include "wifi.h"
#include <WiFi.h>
#include <Arduino.h>

void connectToWiFi(const char* ssid, const char* password) {
    Serial.println("Connexion au réseau Wi-Fi...");
    WiFi.begin(ssid, password);  // Attempt to connect to Wi-Fi

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnecté au Wi-Fi !");
    Serial.print("Adresse IP : ");
    Serial.println(WiFi.localIP());  // Display assigned IP address
}
