 #ifndef _CAMERA_H_
#define _CAMERA_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GL/gl.h"
#include "GL/glut.h"

#include "Config.h" 

void cameraInit(Camera *c);
void deplacerCameraHitbox(Camera *c);



void drawHitbox(Hitbox h);
void murInit(Mur *m); //plus tard mettre 2 points en paramètre
void drawMur(Mur *m);
int collision(Hitbox h, Mur *m);

#endif
