#ifndef _h_balle
#define _h_balle

#include "vecteur.h"

typedef  struct Balle_decl		// Structure qui va contenir les informations de la balle, vitesse, masse etc...
{
	float masse;				
   float coeffriction;			
   Vecteur position;		
   Vecteur vitesse;			
   Vecteur acceleration;  		
   struct Balle_decl * ballePrecedente;
   struct Balle_decl * balleSuivante;
}Balle;

int majPosition(Balle *balle, float dt);		// Prototypes des fonctions utilisées

Balle chargerBalle(char* chemin);

#endif
