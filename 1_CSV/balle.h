#ifndef _h_balle
#define _h_balle

#include "vecteur.h"

typedef struct Balle_decl
{
	float masse;
	float coeffriction;
	Vecteur position;
	Vecteur vitesse;
	Vecteur acceleration;
}Balle;

Balle chargerBalle(char * chemin);

int majPosition(Balle * balle, float dt);

void printBalle(Balle b);

#endif
