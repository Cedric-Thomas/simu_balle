
#include <stdlib.h>
#include "sdl_stuff.h"
#include "fpstimer.h"
#include <math.h>



int main ( int argc, char** argv )
{
    // sert juste à faire bouger la balle de test
    float alpha = 0.0f;

    if(!sdl_startup())
        return -1;
    
    fpsInit();
    // boucle pour mettre a jour en continue la simulation
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

    }
    while(sdl_loop());

    sdl_clean();
    return 0;
}
