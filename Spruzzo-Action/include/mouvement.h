#ifndef MOUVEMENT_H
#define MOUVEMENT_H

// Initialise les broches pour les moteurs
void setupMouvement();

// Fonctions de contrôle des mouvements
void avancer(int vitesse);
void reculer(int vitesse);
void tournerGauche(int vitesse);
void tournerDroite(int vitesse);
void arreter();

#endif // MOUVEMENT_H
