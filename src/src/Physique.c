#include "Physique.h"

Hitbox getHitbox(Mur m){
    return (Hitbox){m.p1, m.p2};
}

Hitbox getCameraHitbox(vecteur pos){
    Point p1 = (Point){pos.x - 1, pos.y - 5, pos.z - 1};
    Point p2 = (Point){pos.x + 1, pos.y + 1, pos.z + 1};
    return (Hitbox){p1, p2};
}

int intersectionPRAA_PRAA(Hitbox h1, Hitbox h2){
    return (h1.p1.x <= h2.p2.x && h1.p2.x >= h2.p1.x) &&
           (h1.p1.y <= h2.p2.y && h1.p2.y >= h2.p1.y) &&
           (h1.p1.z <= h2.p2.z && h1.p2.z >= h2.p1.z);
}

void collision(vecteur Pos, vecteur *velocite, Hitbox objet){
    vecteur nextPos = sommeVectorielle(Pos, produitScalaire(*velocite, SPEED));
    Hitbox posH = getCameraHitbox(Pos);
    Hitbox nextH = getCameraHitbox(nextPos);
    if(intersectionPRAA_PRAA(nextH, objet)){

        if((nextH.p1.x <= objet.p2.x && nextH.p2.x > objet.p2.x && posH.p1.x >= objet.p2.x) ||
           (nextH.p2.x >= objet.p1.x && nextH.p1.x < objet.p1.x && posH.p2.x <= objet.p1.x))
            velocite->x = 0;
        
        if((nextH.p1.y <= objet.p2.y && nextH.p2.y > objet.p2.y && posH.p1.y >= objet.p2.y) ||
           (nextH.p2.y >= objet.p1.y && nextH.p1.y < objet.p1.y && posH.p2.y <= objet.p1.y))
            velocite->y = 0;

        if((nextH.p1.z <= objet.p2.z && nextH.p2.z > objet.p2.z && posH.p1.z >= objet.p2.z) ||
           (nextH.p2.z >= objet.p1.z && nextH.p1.z < objet.p1.z && posH.p2.z <= objet.p1.z))
            velocite->z = 0;
    } 
}

void drawHitbox(Hitbox h){
    glBegin(GL_LINES);

    glColor3f(1, 1, 1);
    glVertex3f(h.p1.x, h.p1.y, h.p1.z);
    glVertex3f(h.p1.x, h.p1.y, h.p2.z);

    glVertex3f(h.p1.x, h.p2.y, h.p1.z);
    glVertex3f(h.p1.x, h.p2.y, h.p2.z);

    glVertex3f(h.p1.x, h.p1.y, h.p1.z);
    glVertex3f(h.p1.x, h.p2.y, h.p1.z);

    glVertex3f(h.p1.x, h.p1.y, h.p2.z);
    glVertex3f(h.p1.x, h.p2.y, h.p2.z);
    //droite
    glVertex3f(h.p2.x, h.p1.y, h.p1.z);
    glVertex3f(h.p2.x, h.p1.y, h.p2.z);

    glVertex3f(h.p2.x, h.p2.y, h.p1.z);
    glVertex3f(h.p2.x, h.p2.y, h.p2.z);

    glVertex3f(h.p2.x, h.p1.y, h.p1.z);
    glVertex3f(h.p2.x, h.p2.y, h.p1.z);

    glVertex3f(h.p2.x, h.p1.y, h.p2.z);
    glVertex3f(h.p2.x, h.p2.y, h.p2.z);

    //relie
    glVertex3f(h.p1.x, h.p1.y, h.p1.z);
    glVertex3f(h.p2.x, h.p1.y, h.p1.z);

    glVertex3f(h.p1.x, h.p2.y, h.p1.z);
    glVertex3f(h.p2.x, h.p2.y, h.p1.z);

    glVertex3f(h.p1.x, h.p1.y, h.p2.z);
    glVertex3f(h.p2.x, h.p1.y, h.p2.z);

    glVertex3f(h.p1.x, h.p2.y, h.p2.z);
    glVertex3f(h.p2.x, h.p2.y, h.p2.z);


    glEnd();
}
