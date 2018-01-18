#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "sdl_stuff.h"
#include "decl.h"
#include "fpstimer.h"
#include "vecteur.h"
#include "balle.h"

Balle gBalleTab[NB_BALLES];

void dragSouris(float x, float y)		// Fonction permettant de déplacer les balles avec la souris
{
   gBalleTab[NB_BALLES - 1].position.x = x;
   gBalleTab[NB_BALLES - 1].position.y = y;
   gBalleTab[NB_BALLES - 1].vitesse.x = 0;
   gBalleTab[NB_BALLES - 1].vitesse.y = 0;
}



int main ( int argc, char** argv )
{
	int i;
   Balle point;
   point.ballePrecedente = point.balleSuivante = NULL;		// Initialisation des balles à NULL

   if(!sdl_startup())
	   return -1;

	fpsInit();
	point = chargerBalle("balle.txt");		// Récupération des valeurs dans le fichier de config

   for (i = 0; i < NB_BALLES; i++)		// Gestion des position des balles précedente, suivante...
   {
      gBalleTab[i] = point;
      gBalleTab[0].ballePrecedente = NULL;
      gBalleTab[0].balleSuivante = &gBalleTab[1];
      gBalleTab[NB_BALLES - 1].ballePrecedente = &gBalleTab[NB_BALLES - 2];
      gBalleTab[NB_BALLES - 1].balleSuivante = NULL;
   }


   for (i = 1; i < NB_BALLES-1; i++)
   {
	  gBalleTab[i].ballePrecedente = &gBalleTab[i-1];
      gBalleTab[i].balleSuivante = &gBalleTab[i+1];
   }


   do
   {
   	int i;
      fpsStep();
		for(i=0; i<NB_BALLES; i++)
      {
      	if (majPosition(&gBalleTab[i], fpsGetDeltaTime())) //mise à jour de la position des balles
         	return 1;
         sdl_setBallPosition(i,gBalleTab[i].position.x,gBalleTab[i].position.y); //mise à jour de la position sur la SDL
      }
   }
	while(sdl_loop());
	sdl_clean();
   return 0;
}
