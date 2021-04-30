#include "Config.h"

//touches zqsd
int up = 0;
int down = 0;
int right = 0;
int left = 0;
int jump = 0;

void Affichage();
void Update();

//rotation camera
void mouseMove(int x, int y);
//deplacements
void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);

Camera c;
Mur m;
Porte p;
Texture t;
Texture porte;
Mur sol;
//temps precedent
float pt = 0;

void ChargerToutesTextures(){
    t = Charger_Texture("../Ressources/Textures/mur.bmp", 300, 300);
    porte = Charger_Texture("../Ressources/Textures/door.bmp", 557, 1242); 
}

int main(int argc, char** argv){
    
    //fenetre
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(LARGEUR_ECRAN, HAUTEUR_ECRAN);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Project Alcatraz");
    if(glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))//fullscreen
        glutEnterGameMode();
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    
    //initialisations
    cameraInit(&c);
    p = porteInit(creer_point(-10, 0, 0), creer_point(-5, 10, 0.15));
    m = murInit(creer_point(-5, 0, -4), creer_point(5, 10, -3.75), NON_TRAVERSABLE);
    sol = (Mur){(Point){-100, -2, -100}, (Point){100, 0, 100}};
    
    // Chargement des textures
    ChargerToutesTextures();
    
    //affichage
    glutDisplayFunc(Affichage);
    glutIdleFunc(Update);

    //gestion souris
    glutMotionFunc(mouseMove);
    glutPassiveMotionFunc(mouseMove);

    //gestion clavier
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

    glFrustum(-0.5, 0.5, -0.28125, 0.28125, 0.8, 200);
    gluLookAt(c.position.x,
              c.position.y, 
              c.position.z,
              c.position.x + c.direction.x,
              c.position.y + c.direction.y,
              c.position.z + c.direction.z,
              0, 1, 0);
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    

    drawHitbox(getCameraHitbox(c.position));
    drawMur(&sol);
    drawMur(&m);
    drawPorte(p, porte);
    //creer_immeuble(creer_point(0, 0, 0), t);
    //test(&t);
    
    glutSwapBuffers();
}

void Update(){

    deplacerCamera(&c, up, down, left, right, jump, &pt);

    collision(c.position, &c.velocite, getHitbox(sol));
    collision(c.position, &c.velocite, getHitbox(m));

    c.position = sommeVectorielle(c.position, produitScalaire(c.velocite, SPEED));

    glutPostRedisplay();
}

void mouseMove(int x, int y){

    if(x != CENTRE_X || y != CENTRE_Y){
        float dx = CENTRE_X - x;
        float dy = CENTRE_Y - y;

        c.angleHorizontal += dx * MOUSE_SPEED;
        c.angleVertical += dy * MOUSE_SPEED;

        if(c.angleVertical < -M_PI_2 + 0.01)
            c.angleVertical = -M_PI_2 + 0.01;
        if(c.angleVertical > M_PI_2 - 0.01 )
            c.angleVertical = M_PI_2 - 0.01;
    
        glutWarpPointer(CENTRE_X, CENTRE_Y);
    }

    rotationCamera(&c);

    glutPostRedisplay();
}

void keyDown(unsigned char key, int x, int y){
    //test collision (if(collision(c.hitbox, &m)))
    switch (key){
    case 'Z':
    case 'z':
            up = 1;
        break;
    case 'S':
    case 's':
            down = 1;
        break;
    case 'Q':
    case 'q':
            left = 1;
        break;
    case 'D':
    case 'd':
            right = 1;
        break;
    case ' ':
            jump = 1;
        break;
    case 'p':
            exit(0);
        break;

    default:
        break;
    }

    glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y){

    switch (key){
    case 'Z':
    case 'z':
        up = 0;
        break;
    case 'S':
    case 's':
        down = 0;
        break;
    case 'Q':
    case 'q':
        left = 0;
        break;
    case 'D':
    case 'd':
        right = 0;
        break;
    case ' ':
        jump = 0;
        break; 
    default:
        break;
    }
}
