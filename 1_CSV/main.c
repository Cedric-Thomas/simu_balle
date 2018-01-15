#include <stdio.h>
#include <stdlib.h>
#include "balle.h"
#include "vecteur.h"

int main(void)
{
	Balle b = chargerBalle("config.txt");
	printBalle(b);
}
