
#include <stdlib.h>
#include <stdio.h>
#include "sdl_stuff.h"
#include "fpstimer.h"
#include "vecteur.h"
#include "balle.h"

#define ERROR -1


int main ( int argc, char** argv )
{
	float x=0, y=0;
	
	if(argc < 2)		// Vérification qu'il y ai bien un fichier de config passé en argument à l'éxécution
	{
		printf("Il manque le fichier de config en argument \n");
		return EXIT_FAILURE;
	}
   
	if(!sdl_startup())
   	return -1;
   
	Balle b = chargerBalle(argv[1]);
	fpsInit();
    // boucle pour mettre a jour en continue la simulation
	do
	{
   	fpsStep();
      x = b.position.x;
      y = b.position.y;
      if (majPosition(&b, fpsGetDeltaTime()))
			printf("ERROR !!");
		
		if(b.position.y>1-BALL_RADIUS)// Rebonds du plafond
      {
			b.position.y=1-BALL_RADIUS; b.vitesse.y*=-0.4;
      }
   
		if(b.position.y<0+BALL_RADIUS)// Rebonds sur le sol
      {
      	b.position.y=0+BALL_RADIUS; b.vitesse.y*=-0.95;
      }
  
		if(b.position.x>1-BALL_RADIUS)// Rebonds sur le mur droit
      {
			b.position.x=1-BALL_RADIUS; b.vitesse.x*=-0.8;
      }
    
		if(b.position.x<0+BALL_RADIUS)//Rebonds sur le mur gauche
      {
      	b.position.x=0+BALL_RADIUS; b.vitesse.x*=-0.8;
      } 
   
		sdl_setBallPosition(x,y);

	}
   while(sdl_loop());

	sdl_clean();
   return 0;
}
