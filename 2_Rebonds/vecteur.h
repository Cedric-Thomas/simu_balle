#ifndef _h_vecteur
#define _h_vecteur

typedef struct Vecteur_decl		// Structure de type vecteur permettant d'utiliser des vecteurs avec des valeurs x et y
{
	float x;
	float y;
}Vecteur;

Vecteur creerVect(float x, float y);			// Prototypes des fonctions utilisées

Vecteur multScalVect(float s, Vecteur v);

Vecteur addVect(Vecteur v1, Vecteur v2);

void printVect(Vecteur v);

#endif
