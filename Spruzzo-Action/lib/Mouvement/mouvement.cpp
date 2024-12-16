#include <Arduino.h>        // Nécessaire pour PlatformIO pour utiliser pinMode, digitalWrite, etc.
#include "driver/ledc.h"    // Pour gérer le PWM sur ESP32

// Broches pour la carte moteur avant
const int frontIN1 = 16; // Moteur avant gauche (sens 1)
const int frontIN2 = 17; // Moteur avant gauche (sens 2)
const int frontIN3 = 5;  // Moteur avant droit (sens 1)
const int frontIN4 = 18; // Moteur avant droit (sens 2)
const int frontENA = 4;  // ENA pour PWM des moteurs avant gauche
const int frontENB = 19; // ENB pour PWM des moteurs avant droit

// Broches pour la carte moteur arrière
const int backIN1 = 25;  // Moteur arrière gauche (sens 1)
const int backIN2 = 26;  // Moteur arrière gauche (sens 2)
const int backIN3 = 27;  // Moteur arrière droit (sens 1)
const int backIN4 = 14;  // Moteur arrière droit (sens 2)
const int backENA = 33;  // ENA pour PWM des moteurs arrière gauche
const int backENB = 12;  // ENB pour PWM des moteurs arrière droit

// Configuration PWM
const int pwmFrequency = 5000; // Fréquence en Hz
const int pwmResolution = 8;   // Résolution en bits (valeurs de 0 à 255)

// Canaux PWM
const int pwmChannelFrontENA = 0; // Canal PWM pour ENA avant
const int pwmChannelFrontENB = 1; // Canal PWM pour ENB avant
const int pwmChannelBackENA = 2;  // Canal PWM pour ENA arrière
const int pwmChannelBackENB = 3;  // Canal PWM pour ENB arrière

void setup() {
  // Initialisation des broches pour la carte moteur avant
  pinMode(frontIN1, OUTPUT);
  pinMode(frontIN2, OUTPUT);
  pinMode(frontIN3, OUTPUT);
  pinMode(frontIN4, OUTPUT);

  // Initialisation des broches pour la carte moteur arrière
  pinMode(backIN1, OUTPUT);
  pinMode(backIN2, OUTPUT);
  pinMode(backIN3, OUTPUT);
  pinMode(backIN4, OUTPUT);

  // Configuration des canaux PWM pour la carte moteur avant
  ledcSetup(pwmChannelFrontENA, pwmFrequency, pwmResolution);
  ledcAttachPin(frontENA, pwmChannelFrontENA);

  ledcSetup(pwmChannelFrontENB, pwmFrequency, pwmResolution);
  ledcAttachPin(frontENB, pwmChannelFrontENB);

  // Configuration des canaux PWM pour la carte moteur arrière
  ledcSetup(pwmChannelBackENA, pwmFrequency, pwmResolution);
  ledcAttachPin(backENA, pwmChannelBackENA);

  ledcSetup(pwmChannelBackENB, pwmFrequency, pwmResolution);
  ledcAttachPin(backENB, pwmChannelBackENB);
}

void loop() {
  // Exemple de séquence : avancer, tourner à gauche, reculer
  avancer(200); // Avancer avec 80% de la vitesse maximale (200/255)
  delay(3000);

  tournerGauche(150); // Tourner à gauche à 60% de la vitesse
  delay(2000);

  reculer(255); // Reculer à pleine vitesse
  delay(3000);

  arreter(); // Arrêter le robot
  delay(2000);
}

// Fonction pour avancer
void avancer(int vitesse) {
  digitalWrite(frontIN1, HIGH);
  digitalWrite(frontIN2, LOW);
  digitalWrite(frontIN3, HIGH);
  digitalWrite(frontIN4, LOW);

  digitalWrite(backIN1, HIGH);
  digitalWrite(backIN2, LOW);
  digitalWrite(backIN3, HIGH);
  digitalWrite(backIN4, LOW);

  ledcWrite(pwmChannelFrontENA, vitesse);
  ledcWrite(pwmChannelFrontENB, vitesse);
  ledcWrite(pwmChannelBackENA, vitesse);
  ledcWrite(pwmChannelBackENB, vitesse);
}

// Fonction pour reculer
void reculer(int vitesse) {
  digitalWrite(frontIN1, LOW);
  digitalWrite(frontIN2, HIGH);
  digitalWrite(frontIN3, LOW);
  digitalWrite(frontIN4, HIGH);

  digitalWrite(backIN1, LOW);
  digitalWrite(backIN2, HIGH);
  digitalWrite(backIN3, LOW);
  digitalWrite(backIN4, HIGH);

  ledcWrite(pwmChannelFrontENA, vitesse);
  ledcWrite(pwmChannelFrontENB, vitesse);
  ledcWrite(pwmChannelBackENA, vitesse);
  ledcWrite(pwmChannelBackENB, vitesse);
}

// Fonction pour tourner à gauche
void tournerGauche(int vitesse) {
  digitalWrite(frontIN1, LOW);
  digitalWrite(frontIN2, LOW);
  digitalWrite(frontIN3, HIGH);
  digitalWrite(frontIN4, LOW);

  digitalWrite(backIN1, LOW);
  digitalWrite(backIN2, LOW);
  digitalWrite(backIN3, HIGH);
  digitalWrite(backIN4, LOW);

  ledcWrite(pwmChannelFrontENA, 0); // Arrêter le moteur avant gauche
  ledcWrite(pwmChannelFrontENB, vitesse); // Activer le moteur avant droit
  ledcWrite(pwmChannelBackENA, 0); // Arrêter le moteur arrière gauche
  ledcWrite(pwmChannelBackENB, vitesse); // Activer le moteur arrière droit
}

// Fonction pour arrêter tous les moteurs
void arreter() {
  digitalWrite(frontIN1, LOW);
  digitalWrite(frontIN2, LOW);
  digitalWrite(frontIN3, LOW);
  digitalWrite(frontIN4, LOW);

  digitalWrite(backIN1, LOW);
  digitalWrite(backIN2, LOW);
  digitalWrite(backIN3, LOW);
  digitalWrite(backIN4, LOW);

  ledcWrite(pwmChannelFrontENA, 0);
  ledcWrite(pwmChannelFrontENB, 0);
  ledcWrite(pwmChannelBackENA, 0);
  ledcWrite(pwmChannelBackENB, 0);
}
