#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GL/gl.h"
#include "GL/glut.h"

/* Variable */
/* Settings */
#define LARGEUR_ECRAN glutGet(GLUT_SCREEN_WIDTH)
#define HAUTEUR_ECRAN glutGet(GLUT_SCREEN_HEIGHT)
#define CENTRE_X LARGEUR_ECRAN/2
#define CENTRE_Y HAUTEUR_ECRAN/2
#define MOUSE_SPEED 0.001

/* Camera */
#define SPEED 0.02

#define CENTRE_X LARGEUR_ECRAN/2
#define CENTRE_Y HAUTEUR_ECRAN/2
#define JUMP_LIMIT 8

#define LARGEUR_MUR 2

/* Pieces / Mur / Porte */
#define NB_MAX_MUR 5
#define NB_MAX_PORTE 5

#define TRAVERSABLE 1
#define NON_TRAVERSABLE 0


/* Bâtiment */

#define TAILLE_IMMEUBLE 100
#define NOMBRE_MURS 5 

/* Structure */

typedef struct {
    float x;
    float y;
    float z;
} Point;


typedef struct {
    float x;
    float y;
    float z;
}vecteur;

typedef struct{
    GLuint identifiant;
}Texture;

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


#define VECTEUR_0 (vecteur){0, 0, 0}
#define VECTEUR_Y (vecteur){0, 1, 0}
#define GRAVITE (vecteur){0, -2, 0}

#include "Texture.h"
#include "Map.h"
#include "Camera.h"
#include "Vecteur.h"
#include "Physique.h"

#endif
