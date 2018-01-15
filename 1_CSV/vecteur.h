#ifndef _h_vecteur
#define _h_vecteur

typedef struct Vecteur_decl
{
	float x;
	float y;
}Vecteur;

Vecteur creerVect(float x, float y);

Vecteur multScalVect(float s, Vecteur v);

Vecteur addVect(Vecteur v1, Vecteur v2);

void printVect(Vecteur v);

#endif
