#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "sdl_stuff.h"
#include "decl.h"
#include "fpstimer.h"
#include "balle.h"

AttracteurList gAttractList;

void clicSouris(float x, float y)		// Fonction permettant lors d'un clic de faire apparaître un attracteur
{
   static int attracteurCurrent = 0 ;
   gAttractList.positionAttracteurs[attracteurCurrent].x = x;
   gAttractList.positionAttracteurs[attracteurCurrent].y = y;
	gAttractList.utiliseMoi[attracteurCurrent] = 1;
   sdl_setAttracteurPosition(attracteurCurrent,x,y);
   attracteurCurrent ++;
   attracteurCurrent %=NB_ATTRACTEURS;
	 
}

int main ( int argc, char** argv )
{
	float x, y;
  
  	if (argc <2)		// Vérification qu'il y ai bien un fichier de config passé en argument à l'éxécution
  	{
  		printf("Il manque le fichier de config en argument\n");
  	 	return EXIT_FAILURE;
  	}
  
   if(!sdl_startup())
   	return -1;
  
   fpsInit();
   initAttracteurList(&gAttractList);
   Balle b = chargerBalle(argv[1]);
     
   do
   {
		fpsStep();
      majPosition(&b, &gAttractList, fpsGetDeltaTime());		// Mise à jour de la position et des attracteurs et de la balle
      x = b.position.x;
      y = b.position.y;
      sdl_setBallPosition(x,y);
	} while(sdl_loop());
   sdl_clean();
   return 0;
}
