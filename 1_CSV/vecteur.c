#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"

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
