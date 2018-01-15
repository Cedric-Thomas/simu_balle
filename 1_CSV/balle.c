#include <stdio.h>
#include <stdlib.h>
#include "balle.h"


Balle chargerBalle(char * chemin)
{
	Balle b;
	FILE* file = fopen(chemin, "r");
	fscanf(file, "masse %f\n", &b.masse);
	fscanf(file, "fCoef %f\n", &b.coeffriction);
	fscanf(file, "position %f %f\n", &b.position.x, &b.position.y);
	fscanf(file, "vitesse %f %f\n", &b.vitesse.x, &b.vitesse.y);
	fclose(file);
	return b;
}
