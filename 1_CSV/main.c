#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////////////////
typedef struct Vecteur_decl
{
	float x;
	float y;
}Vecteur;

typedef struct Balle_decl
{
	float masse;
	float coeffriction;
	Vecteur position;
	Vecteur vitesse;
	Vecteur acceleration;
}Balle;
////////////////////////////////////////////////////////////////////////////////////
Vecteur creerVect(float x, float y)
{
	Vecteur v;
	v.x = x;
	v.y = y;
	return v;
}

Vecteur multScalVect(float s, Vecteur v)
{
	v.x *= s;
	v.y *= s;
	return v;
}

Vecteur addVect(Vecteur v1, Vecteur v2)
{
	Vecteur v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return v;
}

void printVect(Vecteur v)
{
	printf("x: %f\n", v.x);
	printf("y: %f\n", v.y);
}
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
Balle chargerBalle(char * chemin)
{
	Balle b;
	float c;
	FILE* file = fopen(chemin, "r");
	fread(&c, sizeof(float), )
	fclose(file);
	return b;
}
///////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	Vecteur vect_1 = multScalVect(6, creerVect(3, 4)), vect_2 = creerVect(3, 2);
	printVect(vect_1);
	printVect(addVect(vect_1, vect_2));
}
