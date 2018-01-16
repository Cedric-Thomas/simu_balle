
#include <stdlib.h>
#include <stdio.h>
#include "sdl_stuff.h"
#include "fpstimer.h"
#include "vecteur.h"
#include "balle.h"

#define ERROR -1


int main ( int argc, char** argv )
{
    // sert juste à faire bouger la balle de test
    float alpha = 0.0f;

    if(!sdl_startup())
        return -1;
    if(argc != 2)
		return ERROR;
	
    Balle b = chargerBalle(argv[1]);
    
    float x=0, y=0;
    fpsInit();
    // boucle pour mettre a jour en continue la simulation
    do
    {
        fpsStep();

        // ----------------- TODO: remplacer par votre code --------------
        // On fait tourner la balle a raison de PI/2 rad / sec
        x = b.position.x;
        y = b.position.y;
        if (majPosition(&b, fpsGetDeltaTime()))
			printf("ERROR !!");
		
		if(b.position.y>1-BALL_RADIUS)// plafond
        {
            b.position.y=1-BALL_RADIUS; b.vitesse.y*=-0.4;
        }
   
		if(b.position.y<0+BALL_RADIUS)// sol
        {
            b.position.y=0+BALL_RADIUS; b.vitesse.y*=-0.95;
        }
  
		if(b.position.x>1-BALL_RADIUS)// mur droite
        {
			b.position.x=1-BALL_RADIUS; b.vitesse.x*=-0.8;
        }
    
		if(b.position.x<0+BALL_RADIUS)//mur gauche
        {
            b.position.x=0+BALL_RADIUS; b.vitesse.x*=-0.8;
        } 
        // ---------------------------------------------------------------

        // TODO appeler cette fonction avec la position calculée pour la balle
        sdl_setBallPosition(x,y);

    }
    while(sdl_loop());

    sdl_clean();
    return 0;
}
