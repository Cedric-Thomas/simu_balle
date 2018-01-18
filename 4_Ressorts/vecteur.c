#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vecteur.h"

Vecteur creerVect(float x, float y)		// Fonction permettant de créer un vecteur avec des valeurs fournies à l'appel de fonction
{
	Vecteur v;
   v.x = x;
   v.y = y;
   return v;
}


Vecteur multScalVect(float s, Vecteur v)		// fonction permettant de faire un produit scalaire entre un vecteur et un scalaire passés à l'appel de fonction
{
   v.x *= s;
   v.y *= s;
   return v;
}


Vecteur addVect(Vecteur v1, Vecteur v2)		// Fonction permettant de faire une addition entre deux vecteurs passés à l'appel de fonction
{
   Vecteur v;
   v.x = v1.x + v2.x;
   v.y = v1.y + v2.y;
   return v;
}


Vecteur normaliseVect(Vecteur v)		// Fonction permettant de normaliser un vecteur, de donner sa direction
{
	if (normVect(v) == 0)
		return v;
	float longueur = normVect(v);
   v.x /= longueur;
   v.y /= longueur;
   return v;
}


float normVect(Vecteur v)		// Fonction permettant de normer un vecteur, de donner sa longueur
{
	return sqrt((v.x * v.x) + (v.y * v.y));
}


Vecteur subVect(Vecteur v1, Vecteur v2)		// Fonction permettant de soustraire deux vecteurs passés à l'appel de fonction
{
	Vecteur v;
   v.x = v1.x - v2.x;
   v.y = v1.y - v2.y;
   return v;
}
