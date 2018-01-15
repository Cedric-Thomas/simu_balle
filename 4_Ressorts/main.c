
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include"sdl_stuff.h"

#include "decl.h"
#include "fpstimer.h"



// juste pour le basecode, a remplacer par le tableau de balles
float gX=0.0f,gY=0.0f;


// fonction appellée lorsque le bouton de la souris est maintenu
void dragSouris(float x, float y)
{
    gX=x;
    gY=y;
}



int main ( int argc, char** argv )
{
    float alpha = 0.0f;

    if(!sdl_startup())
        return -1;

    fpsInit();

    // TODO :
    // creer les balles
    // ....

    // relier les balles entre elles
    // ....


    // program main loop
    do
    {
        int i;
        fpsStep();

        // TODO : mettre a jour les balle

        // la balle nb 0 est manipulée a la souris a titre d'exemple
        sdl_setBallPosition(0,gX,gY);

        // les autres sont mises a jour differement
        alpha+=3.14f / 2 * fpsGetDeltaTime();
        for(i=1; i<NB_BALLES; i++)
        {
            //TODO : maj de la balle
            float x ,y;

            x = 0.5+0.3f*cosf(alpha+0.1f*i);
            y = 0.5+0.3f*sinf(alpha+0.4f*i);
            sdl_setBallPosition(i,x,y);
        }
    }
    while(sdl_loop());
    // end main loop

    sdl_clean();
    return 0;
}
