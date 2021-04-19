#include "Camera.h"

void cameraInit(Camera *c){
    c->position.x = 0;
    c->position.y = 5;
    c->position.z = 5;

    c->direction.x = 0;
    c->direction.y = 0;
    c->direction.z = -1;

    c->hitbox.p1.x = c->position.x - 1;
    c->hitbox.p1.y = c->position.y - 5;
    c->hitbox.p1.z = c->position.z - 1;

    c->hitbox.p2.x = c->position.x + 1;
    c->hitbox.p2.y = c->position.y + 1;
    c->hitbox.p2.z = c->position.z + 1;
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

void deplacerCameraHitbox(Camera *c){
    c->hitbox.p1.x = c->position.x - 1;
    c->hitbox.p1.y = c->position.y - 5;
    c->hitbox.p1.z = c->position.z - 1;

    c->hitbox.p2.x = c->position.x + 1;
    c->hitbox.p2.y = c->position.y + 1;
    c->hitbox.p2.z = c->position.z + 1;
}

void drawMur(Mur *m){
    glBegin(GL_QUADS);

    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(m->p1.x, m->p1.y, m->p1.z);
    glVertex3f(m->p1.x, m->p1.y, m->p2.z);
    glVertex3f(m->p1.x, m->p2.y, m->p2.z);
    glVertex3f(m->p1.x, m->p2.y, m->p1.z);
    
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(m->p1.x, m->p1.y, m->p1.z);
    glVertex3f(m->p1.x, m->p2.y, m->p1.z);
    glVertex3f(m->p2.x, m->p2.y, m->p1.z);
    glVertex3f(m->p2.x, m->p1.y, m->p1.z);


    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(m->p2.x, m->p1.y, m->p1.z);
    glVertex3f(m->p2.x, m->p1.y, m->p2.z);
    glVertex3f(m->p2.x, m->p2.y, m->p2.z);
    glVertex3f(m->p2.x, m->p2.y, m->p1.z);

    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(m->p1.x, m->p1.y, m->p2.z);
    glVertex3f(m->p1.x, m->p2.y, m->p2.z);
    glVertex3f(m->p2.x, m->p2.y, m->p2.z);
    glVertex3f(m->p2.x, m->p1.y, m->p2.z);
    
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(m->p1.x, m->p1.y, m->p1.z);
    glVertex3f(m->p2.x, m->p1.y, m->p1.z);
    glVertex3f(m->p2.x, m->p1.y, m->p2.z);
    glVertex3f(m->p1.x, m->p1.y, m->p2.z);

    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(m->p1.x, m->p2.y, m->p1.z);
    glVertex3f(m->p2.x, m->p2.y, m->p1.z);
    glVertex3f(m->p1.x, m->p2.y, m->p2.z);
    glVertex3f(m->p2.x, m->p2.y, m->p2.z);

    glEnd();
}

void murInit(Mur *m){
    m->p1.x = -5;
    m->p1.y = 0;
    m->p1.z = -1;
    m->p2.x = 5;
    m->p2.y = 10;
    m->p2.z = 1;
}

int collision(Hitbox h, Mur *m){
    //regarder la feuille des collisions
    return 1;
}