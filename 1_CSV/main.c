#include <stdio.h>
#include <stdlib.h>
#include "balle.h"
#include "vecteur.h"

int main(void)
{
	Vecteur vect_1 = multScalVect(6, creerVect(3, 4)), vect_2 = creerVect(3, 2);
	printVect(vect_1);
	printVect(addVect(vect_1, vect_2));
	Balle myballs = chargerBalle("config.txt");
	printf("masse: %f\n", myballs.masse);
	printf("Fcoef: %f\n", myballs.coeffriction);
	printf("Position\nx: %f\ny: %f\n\n", myballs.position.x, myballs.position.y);
	printf("Vitesse\nx: %f\ny: %f\n", myballs.vitesse.x, myballs.vitesse.y);
}
