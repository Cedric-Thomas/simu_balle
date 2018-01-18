#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "balle.h"
#include "sdl_stuff.h"

Balle chargerBalle(char * chemin)		// Fonction pour récupérer les valeurs de masse vitesse etc... dans le fichier de config
{
	Balle b;
   FILE* file = fopen(chemin, "r");
   fscanf(file, "masse %f\n", &b.masse);
   fscanf(file, "fCoef %f\n", &b.coeffriction);
   fscanf(file, "position %f %f\n", &b.position.x, &b.position.y);
   fscanf(file, "vitesse %f %f\n", &b.vitesse.x, &b.vitesse.y);
   b.acceleration.x = 0;
   b.acceleration.y = 0;
   fclose(file);
   return b;
}

int majPosition (Balle *balle, float dt)		// Fonction pour mettre a jour la position, vitesse, accélération de la balle en fonction de dt et des forces 
{
	if(balle == NULL)
		return -1;

	Vecteur forces, a, g, frottement, F1, F2, vecteur_normal, diff_vecteur, vecteur_balle_precedente, vecteur_balle_suivante;
	float k, l, l0;

	F1 = creerVect(0,0);    //Vecteur entre la balle actuelle et la balle précédente
	F2 = creerVect(0,0);    //Vecteur entre la balle actuelle et la balle suivante

	k = 100;  // Coef de raideur
	l0 = 0.005; //Distance minimal entre deux balles

	if (balle->ballePrecedente != NULL)		// Calculs des positions des balles précédentes et suivantes pour avoir un mouvement des balles cohérents
	{
		vecteur_balle_precedente = balle->ballePrecedente->position;
		diff_vecteur = subVect(balle->position, vecteur_balle_precedente);
		l = normVect(diff_vecteur);
		vecteur_normal = normaliseVect(diff_vecteur);
		F1 = multScalVect(-k * (l - l0), vecteur_normal);
	}

	if (balle->balleSuivante != NULL)
	{
		vecteur_balle_suivante = balle->balleSuivante->position;
		diff_vecteur = subVect(balle->position, vecteur_balle_suivante);
		l = normVect(diff_vecteur);
		vecteur_normal = normaliseVect(diff_vecteur);
		F2 = multScalVect(-k * (l - l0), vecteur_normal);
	}

	g = creerVect(0, -9.81);		// Calcul des forces
	forces = multScalVect(balle->masse, g);
	frottement = multScalVect(-balle->coeffriction, balle->vitesse);
	forces = addVect(forces, frottement);
	forces = addVect(forces, addVect(F1, F2));

	a = multScalVect(1 / balle->masse, forces);

	balle->vitesse = addVect(balle->vitesse, multScalVect(dt, a));
	balle->position = addVect(balle->position, multScalVect(dt, balle->vitesse));


	if(balle->position.y>1-BALL_RADIUS)// Rebonds sur le plafond
   {
   	balle->position.y=1-BALL_RADIUS;
      balle->vitesse.y*=-0.6;
   }

   if(balle->position.y<0+BALL_RADIUS)// Rebonds sur le sol
   {
      balle->position.y=0+BALL_RADIUS;
      balle->vitesse.y*=-0.6;
   }

   if(balle->position.x>1-BALL_RADIUS)// Rebonds sur le mur droit
   {
      balle->position.x=1-BALL_RADIUS;
      balle->vitesse.x*=-0.6;
   }

	if(balle->position.x<0+BALL_RADIUS)// Rebonds sur le mur gauche
   {
   	balle->position.x=0+BALL_RADIUS;
      balle->vitesse.x*=-0.6;
   }
   return 0;
}


