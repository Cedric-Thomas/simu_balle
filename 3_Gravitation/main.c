
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "sdl_stuff.h"

#include "decl.h"
#include "fpstimer.h"



// fonction appellée lorsque l'on appuie avec le bouton gauche de la souris
void clicSouris(float x, float y)
{
    // NB : une variable locale declaree static ne perd pas sa valeur entre deux appels a la fonction
    // son initialisation est effectué au tout premier appel de la fonction
    // on s'en sert ici pour savoir quel attracteur on est en train de positioner
    static int attracteurCurrent = 0 ;

    // TODO gerer les position de la liste des attracteurs ici


    sdl_setAttracteurPosition(attracteurCurrent,x,y);
    attracteurCurrent ++;
    attracteurCurrent %=NB_ATTRACTEURS;
}



int main ( int argc, char** argv )
{
  // sert just à faire bouger la balle de test
    float alpha = 0.0f;

    if(!sdl_startup())
        return -1;

    fpsInit();
    // program main loop
    do
    {
        fpsStep();

        // ----------------- TODO: remplacer par votre code --------------
        float x ,y;
        // On fait tourner la balle a raison de PI/2 rad / sec
        alpha+=3.14f / 2 * fpsGetDeltaTime();
        x = 0.5+0.3f*cosf(alpha);
        y = 0.5+0.3f*sinf(alpha);
        // ---------------------------------------------------------------

        // TODO appeler cette fonction avec la position calculée pour la balle
        sdl_setBallPosition(x,y);

    } while(sdl_loop());
    // end main loop

    sdl_clean();
    return 0;
}
