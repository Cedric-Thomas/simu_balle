#include <stdio.h>
#include <stdlib.h>
#include "balle.h"
#include "vecteur.h"

int main(void)
{
	Vecteur vect_1 = multScalVect(6, creerVect(3, 4)), vect_2 = creerVect(3, 2);
	printVect(vect_1);
	printVect(addVect(vect_1, vect_2));
}
