#include "Personnage.h"

Personnage creer_personnage(Point p){
    Personnage vPersonnage;
    vPersonnage.centre.x = p.x;
    vPersonnage.centre.y = p.y;
    vPersonnage.centre.z = p.z;

    return vPersonnage;
}