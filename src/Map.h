#ifndef _MAP_H
#define _MAP_H

#include "Config.h"

/* Génération de la carte */

Point creer_point(float x, float y, float z);
Mur creer_mur(Point p1, Point p2, int traversable, Texture t);
Mur creer_mur_porte(Point p1, Point p2, int traversable, Porte porte, Texture t);
Porte creer_porte(Point p1, Point p2, Texture t);
Piece creer_piece(Mur m1, Mur m2, Mur m3, Mur m4, Porte p1);
void creer_immeuble(Point depart, Texture t);


void test(Texture *t);
Mur murInit(Point p1, Point p2, int traversable); //plus tard mettre 2 points en paramètre
void drawMur(Mur *m);
Porte porteInit(Point p1, Point p2);
void drawPorte(Porte p, Texture t);

#endif
