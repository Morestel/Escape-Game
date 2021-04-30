#include "Vecteur.h"

vecteur sommeVectorielle(vecteur v1, vecteur v2){
    return (vecteur){
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    };
}

vecteur differenceVectorielle(vecteur v1, vecteur v2){
    return (vecteur){
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };
}

vecteur produitVectoriel(vecteur v1, vecteur v2){
    return (vecteur){
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
}

vecteur produitScalaire(vecteur v, float k){
    return (vecteur){
        v.x * k,
        v.y * k,
        v.z * k
    };
}

float normeVecteur(vecteur v){
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

void vecteurUnite(vecteur *v){
    if(normeVecteur(*v)){
        v->x /= normeVecteur(*v);
        v->y /= normeVecteur(*v);
        v->z /= normeVecteur(*v);
    }
}