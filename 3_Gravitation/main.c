#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "sdl_stuff.h"
#include "decl.h"
#include "fpstimer.h"
#include "balle.h"

AttracteurList gAttractList;

void clicSouris(float x, float y)
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
    if(!sdl_startup())
        return -1;
    fpsInit();
    initAttracteurList(&gAttractList);
    Balle b = chargerBalle(argv[1]);
    float x, y;
    do
    {
        fpsStep();
        majPosition(&b, &gAttractList, fpsGetDeltaTime());
        x = b.position.x;
        y = b.position.y;
        sdl_setBallPosition(x,y);
    } while(sdl_loop());
    sdl_clean();
    return 0;
}
