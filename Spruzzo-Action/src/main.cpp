#include <Arduino.h>       // Nécessaire pour PlatformIO
#include "mouvement.h"     // Inclut les déclarations des fonctions de mouvement

void setup() {
  setupMouvement();        // Initialise les broches pour les moteurs
}

void loop() {
  // Exemple : Appelle les fonctions de mouvement depuis mouvement.cpp
  avancer(125);    // Le robot avance
  delay(3000);

  tournerGauche(125); // Tourne à gauche
  delay(2000);

  tournerDroite(125); // Tourne à droite
  delay(2000);

  reculer(125);    // Le robot recule
  delay(3000);

  arreter();       // Arrête les moteurs
  delay(2000);
}
