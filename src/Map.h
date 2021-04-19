#ifndef _MAP_H
#define _MAP_H

#include "Config.h"

/* Génération de la carte */

Point creer_point(float x, float y, float z);
Mur creer_mur(Point p1, Point p2, int traversable);
Mur creer_mur_porte(Point p1, Point p2, int traversable, Porte porte);
Porte creer_porte(Point p1, Point p2);
Piece creer_piece(Mur m1, Mur m2, Mur m3, Mur m4, Porte p1);

#endif