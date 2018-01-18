#ifndef _h_balle
#define _h_balle

#include "vecteur.h"

typedef struct Balle_decl		// Structure qui va contenir les informations de la balle, vitesse, masse etc...
{
	float masse;
	float coeffriction;
	Vecteur position;
	Vecteur vitesse;
	Vecteur acceleration;
}Balle;

Balle chargerBalle(char * chemin);		// Prototypes des fonctions utilisées

int majPosition(Balle * balle, float dt);

void printBalle(Balle b);

#endif
