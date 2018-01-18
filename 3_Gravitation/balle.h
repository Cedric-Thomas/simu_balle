#ifndef _h_balle
#define _h_balle

#include "vecteur.h"
#include "decl.h"

typedef struct Balle_decl		// Structure qui va contenir les informations de la balle, vitesse, masse etc...
{
	float masse;
	float coeffriction;
	Vecteur position;
	Vecteur vitesse;
	Vecteur acceleration;
}Balle;

typedef struct AttracteurListePlanete		// Structure qui va contenir la position des Attracteurs dans un tableau
{
	Vecteur positionAttracteurs[NB_ATTRACTEURS];
	int utiliseMoi[NB_ATTRACTEURS];
}AttracteurList;

Balle chargerBalle(char * chemin);		// Prototypes des fonctions utilisées

int majPosition(Balle *balle, AttracteurList *pAttrList, float dt);

void initAttracteurList(AttracteurList * pAttrList);

void printBalle(Balle b);

#endif
