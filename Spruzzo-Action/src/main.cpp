#include <Arduino.h>
#include "mouvement.h"

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
