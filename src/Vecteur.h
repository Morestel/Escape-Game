#ifndef VECTEUR_H
#define VECTEUR_H

#include "Config.h"

vecteur sommeVectorielle(vecteur v1, vecteur v2);
vecteur differenceVectorielle(vecteur v1, vecteur v2);
vecteur produitVectoriel(vecteur v1, vecteur v2);
vecteur produitScalaire(vecteur v, float k);
float normeVecteur(vecteur v);
void vecteurUnite(vecteur *v);

#endif
