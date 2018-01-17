#include <stdio.h>
#include <stdlib.h>
#include "balle.h"
#include "decl.h"
#include "sdl_stuff.h"

Balle chargerBalle(char * chemin)
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

int majPosition(Balle * balle, AttracteurList * pAttrList, float dt)
{
    balle->position = addVect( balle->position, multScalVect(dt, balle->vitesse));
    Vecteur force, direction, normalise;
    float norme, magnitude;
    force = creerVect(0,0);
    int i;
    for (i = 0; i < NB_ATTRACTEURS; i++)
    {
        if (pAttrList->utiliseMoi[i] == 1)
        {
            direction = subVect(balle->position, pAttrList->positionAttracteurs[i]);
            norme = normVect(direction);
            normalise = normaliseVect(direction);
            magnitude = -0.1/(norme*norme);
            if (magnitude < -8)
            {
                magnitude = -8;
            }
            if (magnitude > 8)
            {
                magnitude = 8;
            }
            force = addVect(force, multScalVect(magnitude, normalise));
        }
    }

    balle->acceleration = multScalVect(1/balle->masse, force);
    balle->vitesse = addVect(balle->vitesse, multScalVect(dt, balle->acceleration));
    balle->position = addVect(balle->position, multScalVect(dt, balle->vitesse));

    if(balle->position.y>1-BALL_RADIUS)// plafond
    {
        balle->position.y=1-BALL_RADIUS;
        balle->vitesse.y*=-0.6;
    }

    if(balle->position.y<0+BALL_RADIUS)// sol
    {
        balle->position.y=0+BALL_RADIUS;
        balle->vitesse.y*=-0.6;
    }

    if(balle->position.x>1-BALL_RADIUS)// mur droite
    {
        balle->position.x=1-BALL_RADIUS;
        balle->vitesse.x*=-0.6;
    }

    if(balle->position.x<0+BALL_RADIUS)//mur gauche
    {
        balle->position.x=0+BALL_RADIUS;
        balle->vitesse.x*=-0.6;
    }
    return 0;
}

void initAttracteurList(AttracteurList * pAttrList)
{
    int i;
    for(i=0; i<NB_ATTRACTEURS; i++)
    {
        pAttrList->positionAttracteurs[i] = creerVect(0, 0);
        pAttrList->utiliseMoi[i] = 0;
    }
}

void printBalle(Balle b)
{
    printf("masse: %f\n", b.masse);
    printf("fCoef: %f\n", b.coeffriction);
    printf("position: x:%f   y:%f\n", b.position.x, b.position.y);
    printf("vitesse: x:%f   y:%f\n", b.vitesse.x, b.vitesse.y);
    printf("acceleration: x:%f   y:%f\n", b.acceleration.x, b.acceleration.y);
}
