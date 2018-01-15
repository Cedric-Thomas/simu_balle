#include <stdio.h>
#include <stdlib.h>
#include "balle.h"
#include "vecteur.h"

int main(void)
{
	Balle b = chargerBalle("config.txt");
	float i;
	FILE* csv = fopen("export.csv", "w");
	for(i = 0; i < 3; i += 0.01)
	{
		 fprintf(csv, "%f;%f;%f\n", i, b.position.x, b.position.y);
		 majPosition(&b, 0.01);
	}
	fclose(csv);
}
