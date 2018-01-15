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
	b.acceleration.x = 0; b.acceleration.y = 0;
	fclose(file);
	return b;
}

void printBalle(Balle b)
{
	printf("masse: %f\n", b.masse);
	printf("fCoef: %f\n", b.coeffriction);
	printf("position: x:%f   y:%f\n", b.position.x, b.position.y);
	printf("vitesse: x:%f   y:%f\n", b.vitesse.x, b.vitesse.y);
	printf("acceleration: x:%f   y:%f\n", b.acceleration.x, b.acceleration.y);
}
