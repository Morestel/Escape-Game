#include "Config.h"

float horizontal = 3.14;
float vertical=0;

float mouseSpeed = 0.001;

void Affichage();
void test();

//rotation camera
void mouseMove(int x, int y);
//deplacements
void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);

Camera c;
Mur m;

Texture t;

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(LARGEUR_ECRAN, HAUTEUR_ECRAN);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Project Alcatraz");
    glEnable(GL_DEPTH_TEST);
    glutSetCursor(GLUT_CURSOR_NONE);

    cameraInit(&c);
    murInit(&m);
    t = Charger_Texture("mur.bmp", 300, 300);
    glutDisplayFunc(Affichage);
    glutIdleFunc(Affichage);

    glutMotionFunc(mouseMove);
    glutPassiveMotionFunc(mouseMove);
    glutKeyboardFunc(keyDown);
    glutIgnoreKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutKeyboardUpFunc(keyUp);
    
    glutMainLoop();

    return 0;
}

void Affichage(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-1, 1, -0.5625, 0.5625, 1, 300);
    gluLookAt(c.position.x,
                c.position.y, 
                c.position.z,
                c.position.x + c.direction.x,
                c.position.y + c.direction.y,
                c.position.z + c.direction.z,
                0, 1, 0);
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    test();
    //drawMur(&m);
    drawHitbox(c.hitbox);
    

    glutSwapBuffers();
}

void test(){
    glBegin(GL_QUADS);
    //sol
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-100, -1, -100);
    glVertex3f(100, -1, -100);
    glVertex3f(100, -1, 100);
    glVertex3f(-100, -1, 100);
    /*
    //mur rouge
    glColor3f(0.6, 0.3, 0.3);
    glVertex3f(-5, -1, -10);
    glVertex3f(5, -1, -10);
    glVertex3f(5, 9, -10);
    glVertex3f(-5, 9, -10);
    //mur vert
    glColor3f(0.3, 0.6, 0.3);
    glVertex3f(-5, -1, 10);
    glVertex3f(5, -1, 10);
    glVertex3f(5, 9, 10);
    glVertex3f(-5, 9, 10);
    //mur bleu
    glColor3f(0.3, 0.3, 0.6);
    glVertex3f(-5, 10, -10);
    glVertex3f(5, 10, -10);
    glVertex3f(5, 10, 10);
    glVertex3f(-5, 10, 10);*/

    glEnd();
    Point p1 = creer_point(0, 0, 0); Point p2 = creer_point(10, 10, 0+LARGEUR_MUR);
    Point porte_p1 = creer_point(4, 0, 0); Point porte_p2 = creer_point(7, 8, 1);
    glColor3f(0.0, 0.0, 1.0);
    Porte porte = creer_porte(porte_p1, porte_p2, t);

    creer_mur_porte(p1, p2, NON_TRAVERSABLE, porte, t);

    Point p3 = creer_point(-10, 0, -10); Point p4 = creer_point(-50, 15, -10 + LARGEUR_MUR);
    Point porte_p3 = creer_point(-15, 0, -10); Point porte_p4 = creer_point(-20, 9, -9);
    glColor3f(0.0, 0.0, 1.0);

    Porte porte_2 = creer_porte(porte_p3, porte_p4, t);

    creer_mur_porte(p3, p4, NON_TRAVERSABLE, porte_2, t);
}

void mouseMove(int x, int y){
    float dx, dy;

    if(x != CENTRE_X || y != CENTRE_Y){
        dx = CENTRE_X - x;
        dy = CENTRE_Y - y;

        horizontal += dx * mouseSpeed;
        vertical += dy * mouseSpeed;

        if(vertical < -M_PI_2 + 0.01)
            vertical = -M_PI_2 + 0.01;
        if(vertical > M_PI_2 - 0.01 )
            vertical = M_PI_2 - 0.01;

        c.direction.x = sin(horizontal) * cos(vertical);
        c.direction.y = sin(vertical);
        c.direction.z = cos(horizontal) * cos(vertical);
    
        glutWarpPointer(CENTRE_X, CENTRE_Y);
    }
    
}

void keyDown(unsigned char key, int x, int y){
    //test collision (if(collision(c.hitbox, &m)))
    switch (key){
    case 'z':
            c.position.x += c.direction.x * 2;
            c.position.z += c.direction.z * 2;
        break;
    case 's':
            c.position.x -= c.direction.x * 2;
            c.position.z -= c.direction.z * 2;
        break;
    case 'q':
            c.position.x -= -c.direction.z * 2;
            c.position.z -= c.direction.x * 2;
        break;
    case 'd':
            c.position.x += -c.direction.z * 2;
            c.position.z += c.direction.x * 2;
        break;

    case 'p':
            exit(0);
        break;

    default:
        break;
    }
    deplacerCameraHitbox(&c);
}

void keyUp(unsigned char key, int x , int y){
    switch (key){
    case 'z':
        
        break;
    case 's':
        
        break;
    case 'q':
        
        break;
    case 'd':
        
        break;
    
    default:
        break;
    }
}