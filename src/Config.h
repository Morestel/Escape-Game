#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GL/gl.h"
#include "GL/glut.h"
#include <inttypes.h>
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

#define LARGEUR_MUR 0.6

/* Pieces / Mur / Porte */
#define NB_MAX_MUR 5
#define NB_MAX_PORTE 5

#define TRAVERSABLE 1
#define NON_TRAVERSABLE 0
#define AVEC_PORTE 1
#define SANS_PORTE 0
#define LONGUEUR_PORTE 7
#define HAUTEUR_PORTE 10
#define LARGEUR_PORTE 0.15

/* Bâtiment */

#define TAILLE_IMMEUBLE 200
#define NOMBRE_MURS 5 
#define NOMBRE_ETAGE 2
#define HAUTEUR_MUR 20
#define HAUTEUR_SOL 3
#define NOMBRE_PORTES 30

#define DEVANT 0
#define GAUCHE 1
#define DROITE 2
#define DERRIERE 3

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
}Porte;

typedef struct{
    Point p1;
    Point p2;
    int avec_porte;
    int traversable;
    Porte porte;
}Mur;

typedef struct{
    Mur liste_mur[NB_MAX_MUR];
    Porte liste_porte[NB_MAX_PORTE];
}Piece;

typedef struct{
    Piece piece[NOMBRE_MURS][NOMBRE_MURS][NOMBRE_ETAGE];
    Mur sol[NOMBRE_ETAGE];
    Porte porte[NOMBRE_PORTES][NOMBRE_ETAGE];
}Maison;

#define VECTEUR_0 (vecteur){0, 0, 0}
#define VECTEUR_Y (vecteur){0, 1, 0}
#define GRAVITE (vecteur){0, -2, 0}

#include "Texture.h"
#include "Map.h"
#include "Camera.h"
#include "Vecteur.h"
#include "Physique.h"

#endif
