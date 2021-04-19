#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GL/gl.h"
#include "GL/glut.h"

/* Inclusions de nos fichiers */




/* Variable */
/* Settings */
#define LARGEUR_ECRAN glutGet(GLUT_SCREEN_WIDTH)
#define HAUTEUR_ECRAN glutGet(GLUT_SCREEN_HEIGHT)

#define CENTRE_X LARGEUR_ECRAN/2
#define CENTRE_Y HAUTEUR_ECRAN/2
#define JUMP_LIMIT 8

#define LARGEUR_MUR 2

/* Pieces / Mur / Porte */
#define NB_MAX_MUR 5
#define NB_MAX_PORTE 5

#define TRAVERSABLE 1
#define NON_TRAVERSABLE 0

/* Structure */


typedef struct {
    float x;
    float y;
    float z;
} Point;

typedef struct{
    Point p1;
    Point p2;
    int traversable;
}Mur;

typedef struct{
    Point p1;
    Point p2;
}Porte;

typedef struct{
    Mur liste_mur[NB_MAX_MUR];
    Porte liste_porte[NB_MAX_PORTE];
}Piece;

typedef struct {
    Point p1;
    Point p2;
} Hitbox;

typedef struct{
    Point centre;
    Hitbox hitbox;
}Personnage;


typedef struct {
    Point position;
    Point direction;
    Hitbox hitbox;
} Camera;

typedef struct{
    GLuint identifiant;
}Texture;

#include "Texture.h"
#include "Map.h"
#include "Personnage.h"
#include "Camera.h"


#endif