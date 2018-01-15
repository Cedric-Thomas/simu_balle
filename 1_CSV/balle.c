#include <stdio.h>
#include <stdlib.h>
#include "balle.h"


Balle chargerBalle(char * chemin)
{
	Balle b;
	float c;
	FILE* file = fopen(chemin, "r");
	fclose(file);
	return b;
}
