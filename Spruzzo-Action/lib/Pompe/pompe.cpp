#include "pompe.h"
#include <Arduino.h>

#define PIN_POMPE 5 // Exemple : la pompe est connectée à la broche 5

void activerPompe() {
    digitalWrite(PIN_POMPE, HIGH);
    Serial.println("Pompe activée");
}

void desactiverPompe() {
    digitalWrite(PIN_POMPE, LOW);
    Serial.println("Pompe désactivée");
}
