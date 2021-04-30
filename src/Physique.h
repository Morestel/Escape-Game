#ifndef PHYSIQUE_H
#define PHYSIQUE_H

#define GRAVITE (vecteur){0, -2, 0}

#include "Config.h"

typedef struct {
    Point p1;
    Point p2;
} Hitbox;

Hitbox getHitbox(Mur m);
Hitbox getCameraHitbox(vecteur pos);
int intersectionPRAA_PRAA(Hitbox h1, Hitbox h2);
void collision(vecteur Pos, vecteur *velocite, Hitbox objet);
void drawHitbox(Hitbox h);

#endif
