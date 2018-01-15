#include <stdio.h>
#include <stdlib.h>
#include "balle.h"
#include "vecteur.h"

#define FILENAME_IMPORT "balle.txt"
#define FILENAME_EXPORT "export.csv"

void gnrt_csv(int temps_sec, float pas_sec)
{
	Balle b = chargerBalle(FILENAME_IMPORT);
	
	FILE* csv = fopen(FILENAME_EXPORT, "w");
	
	float i;
	
	for(i = 0; i < temps_sec; i += pas_sec)
	{
		 fprintf(csv, "%f;%f;%f\n", i, b.position.x, b.position.y);
		 majPosition(&b, 0.01);
	}
	fclose(csv);
}

int main(void)
{
	gnrt_csv(3, 0.01);
}
