#ifndef _h_balle
#define _h_balle

#include "vecteur.h"
#include "decl.h"

typedef struct Balle_decl
{
	float masse;
	float coeffriction;
	Vecteur position;
	Vecteur vitesse;
	Vecteur acceleration;
}Balle;

typedef struct
{
	Vecteur positionAttracteurs[NB_ATTRACTEURS];
	int utiliseMoi[NB_ATTRACTEURS];
} AttracteurList;

Balle chargerBalle(char * chemin);

int majPosition(Balle *balle, AttracteurList *pAttrList, float dt);

void initAttracteurList(AttracteurList * pAttrList);

void printBalle(Balle b);

#endif
