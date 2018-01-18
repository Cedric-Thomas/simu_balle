#include <stdio.h>
#include <stdlib.h>
#include "balle.h"

Balle chargerBalle(char * chemin)		// Fonction pour récupérer les valeurs de masse vitesse etc... dans le fichier de config
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

int majPosition(Balle * balle, float dt)			// Fonction pour mettre a jour la position, vitesse, accélération de la balle en fonction de dt et des forces
{
	Vecteur forces = addVect(creerVect(0, balle->masse * -9.81), multScalVect(-balle->coeffriction, balle->vitesse));
	balle->acceleration = multScalVect(1/balle->masse, forces);
	balle->vitesse = addVect(balle->vitesse, multScalVect(dt, balle->acceleration));
	balle->position = addVect(balle->position, multScalVect(dt, balle->vitesse));
	if (balle->position.y < 0)
		balle->position.y = 0;
	return 0;
}
