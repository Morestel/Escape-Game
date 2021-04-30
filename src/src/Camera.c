#include "Camera.h"

void cameraInit(Camera *c){
    c->position = (vecteur){0, 6, 5};
    c->direction = (vecteur){0, 0, -1};
    c->velocite = VECTEUR_0;

    c->angleHorizontal = M_PI;
    c->angleVertical = 0;
    c->auSol = 0;
    c->collision = 0;
}

void rotationCamera(Camera *c){
    c->direction = (vecteur){
        sin(c->angleHorizontal) * cos(c->angleVertical),
        sin(c->angleVertical),
        cos(c->angleHorizontal) * cos(c->angleVertical)
    };
}

void deplacerCamera(Camera *c, int up, int down, int left, int right, int jump, float *pt){
    vecteur avant, droite, haut;
    vecteur deplacement = VECTEUR_0;

    //calcul des vecteurs de mouvements
    avant = (vecteur){sin(c->angleHorizontal), 0, cos(c->angleHorizontal)};
    droite = produitVectoriel(VECTEUR_Y, avant);
    haut = produitVectoriel(avant, droite);

    if(up)
        deplacement = sommeVectorielle(deplacement, avant);

    if(down)
        deplacement = differenceVectorielle(deplacement, avant);

    if(left)
        deplacement = sommeVectorielle(deplacement, droite);

    if(right)
        deplacement = differenceVectorielle(deplacement, droite);
    
    vecteurUnite(&deplacement);

    if(jump && c->auSol)
        deplacement = sommeVectorielle(deplacement, produitScalaire(haut, 3));

    c->velocite = sommeVectorielle(deplacement, GRAVITE);
}
