#include <stdio.h>
#include <stdlib.h>
#include "balle.h"
#include "vecteur.h"

#define FILENAME_IMPORT "balle.txt"		// Définition du nom de fichier a utiliser ( absolu, à modifier si le nom du fichier de config change)
#define FILENAME_EXPORT "export.csv"

void gnrt_csv(int temps_sec, float pas_sec)		// fonction premettant de générer le fichier csv de sortie
{
	Balle b = chargerBalle(FILENAME_IMPORT);
	FILE* csv = fopen(FILENAME_EXPORT, "w");
	
	float i;
	for(i = 0; i < temps_sec; i += pas_sec)		// Boucle for permettant d'écrire la position de la balle en x et en y dans le fichier csv toutes les 0.01 secondes'
	{
		fprintf(csv, "%f;%f;%f\n", i, b.position.x, b.position.y);
		majPosition(&b, 0.01);		// Configuration de la simulation pour une durée de 3 secondes et une mise à jour toutes les 0.01 secondes
	}
	fclose(csv);
}

int main(void)
{
	gnrt_csv(3, 0.01);
}
