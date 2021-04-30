#ifndef CAMERA_H
#define CAMERA_H

#include "Config.h"

typedef struct {
    vecteur position;
    vecteur direction;
    vecteur velocite;
    float angleHorizontal;
    float angleVertical;
    int auSol;
    int collision;
} Camera;

void cameraInit(Camera *c);
void rotationCamera(Camera *c);
void deplacerCamera(Camera *c, int up, int down, int left, int right, int jump, float *pt);

#endif
