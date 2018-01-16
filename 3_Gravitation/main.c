
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "sdl_stuff.h"

#include "decl.h"
#include "fpstimer.h"

#include "balle.h"
#include <stdio.h>

AttracteurList gAttractList;

// fonction appellée lorsque l'on appuie avec le bouton gauche de la souris
void clicSouris(float x, float y)
{
    // NB : une variable locale declaree static ne perd pas sa valeur entre deux appels a la fonction
    // son initialisation est effectué au tout premier appel de la fonction
    // on s'en sert ici pour savoir quel attracteur on est en train de positioner
    static int attracteurCurrent = 0 ;

    // TODO gerer les position de la liste des attracteurs ici
    
    gAttractList.positionAttracteurs[attracteurCurrent].x = x;
    gAttractList.positionAttracteurs[attracteurCurrent].y = y;
    sdl_setAttracteurPosition(attracteurCurrent,x,y);
    attracteurCurrent ++;
    attracteurCurrent %=NB_ATTRACTEURS;
}



int main ( int argc, char** argv )
{
  // sert just à faire bouger la balle de test
    //float alpha = 0.0f;

    if(!sdl_startup())
        return -1;

    fpsInit();
 
    initAttracteurList(&gAttractList);
    // program main loop
    float x, y;
    do
    {
        fpsStep();

        // ----------------- TODO: remplacer par votre code --------------
    
        // On fait tourner la balle a raison de PI/2 rad / sec
 

        // ---------------------------------------------------------------

        // TODO appeler cette fonction avec la position calculée pour la balle
        sdl_setBallPosition(x,y);

    } while(sdl_loop());
    // end main loop

    sdl_clean();
    return 0;
}
