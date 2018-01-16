#include <stdio.h>
#include <stdlib.h>
#include "balle.h"
#include "decl.h"

Balle chargerBalle(char * chemin)
{
	Balle b;
	FILE* file = fopen(chemin, "r");
	fscanf(file, "masse %f\n", &b.masse);
	fscanf(file, "fCoef %f\n", &b.coeffriction);
	fscanf(file, "position %f %f\n", &b.position.x, &b.position.y);
	fscanf(file, "vitesse %f %f\n", &b.vitesse.x, &b.vitesse.y);
	b.acceleration.x = 0; b.acceleration.y = 0;
	fclose(file);
	return b;
}

int majPosition(Balle * balle, float dt)
{

	//Vecteur forces = -0.1 / normVect()
	Vecteur forces = addVect(creerVect(0, balle->masse * -9.81), multScalVect(-balle->coeffriction, balle->vitesse));
	balle->acceleration = multScalVect(1/balle->masse, forces);
	balle->vitesse = addVect(balle->vitesse, multScalVect(dt, balle->acceleration));
	balle->position = addVect(balle->position, multScalVect(dt, balle->vitesse));
	if (balle->position.y < 0)
		balle->position.y = 0;
	return 0;
}

void initAttracteurList(AttracteurList * pAttrList)
{
	int i;
	for(i=0; i<NB_ATTRACTEURS; i++)
	{
		pAttrList->positionAttracteurs[i] = creerVect(0, 0);
		pAttrList->utiliseMoi[i] = 0;
	}
}

void printBalle(Balle b)
{
	printf("masse: %f\n", b.masse);
	printf("fCoef: %f\n", b.coeffriction);
	printf("position: x:%f   y:%f\n", b.position.x, b.position.y);
	printf("vitesse: x:%f   y:%f\n", b.vitesse.x, b.vitesse.y);
	printf("acceleration: x:%f   y:%f\n", b.acceleration.x, b.acceleration.y);
}
