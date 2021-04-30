#include "Map.h"

Point creer_point(float x, float y, float z){
    Point p;
    p.x = x;
    p.y = y;
    p.z = z;

    return p;
}

Mur creer_mur(Point p1, Point p2, int traversable, Texture t){
    Mur m;
    m.traversable = traversable;
    m.p1 = p1;
    m.p2 = p2;

    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, t.identifiant);
    glBegin(GL_QUADS);
    

    // Premiere face
    glTexCoord2d(0.0,0.0);
    glVertex3i(p1.x, p1.y, p1.z);
    glTexCoord2d(1.0,0.0);
    glVertex3i(p2.x, p1.y, p1.z);
    glTexCoord2d(1.0,1.0);
    glVertex3i(p2.x, p2.y, p1.z);
    glTexCoord2d(0.0,1.0);
    glVertex3i(p1.x, p2.y, p1.z);
    
    // Seconde face
    glTexCoord2d(0.0,0.0);
    glVertex3i(p2.x, p2.y, p2.z);
    glTexCoord2d(1.0,0.0);
    glVertex3i(p1.x, p2.y, p2.z);
    glTexCoord2d(1.0,1.0);
    glVertex3i(p1.x, p1.y, p2.z);
    glTexCoord2d(0.0,1.0);
    glVertex3i(p2.x, p1.y, p2.z);
    
    // Premiere jointure
    glTexCoord2d(0.0,1.0);
    glVertex3i(p2.x, p2.y, p2.z);
    glTexCoord2d(0.0,0.0);
    glVertex3i(p2.x, p2.y, p1.z);
    glTexCoord2d(1.0,0.0);
    glVertex3i(p2.x, p1.y, p1.z);
    glTexCoord2d(1.0,1.0);
    glVertex3i(p2.x, p1.y, p2.z);
    
    // Seconde jointure
    glTexCoord2d(0.0,1.0);
    glVertex3i(p1.x, p1.y, p1.z);
    glTexCoord2d(0.0,0.0);
    glVertex3i(p1.x, p2.y, p1.z);
    glTexCoord2d(1.0,0.0);
    glVertex3i(p1.x, p2.y, p2.z);
    glTexCoord2d(1.0,1.0);
    glVertex3i(p1.x, p1.y, p2.z);
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
    return m;
}

Mur creer_mur_porte(Point p1, Point p2, int traversable, Porte porte, Texture t){
    Mur m;
    m.p1 = p1; m.p2 = p2; m.traversable = traversable;

    Point premiere_partie = creer_point(porte.p1.x, p2.y, p2.z);
    //glColor3f(1.0, 0.0, 0.0);
    
    creer_mur(p1, premiere_partie, traversable, t);
    
    Point seconde_partie = creer_point(porte.p2.x, p1.y, p1.z);
    //glColor3f(1.0,1.0,1.0);
    creer_mur(seconde_partie, p2, traversable, t);
      
    //glColor3f(0.8, 0.1, 0.2);
    Point jointure_1 = creer_point(porte.p1.x, porte.p2.y, porte.p1.z);
    Point jointure_2 = creer_point(porte.p2.x, p2.y, p2.z);
    creer_mur(jointure_1, jointure_2, NON_TRAVERSABLE, t);
    
    return m;
}

Porte creer_porte(Point p1, Point p2, Texture t){
    Porte p;
    p.p1 = p1;
    p.p2 = p2;
    
    //creer_mur(p1, p2, NON_TRAVERSABLE, t);
    glBegin(GL_QUADS);
    
    // Première face
    glVertex3i(p1.x, p1.y, p1.z);
    glVertex3i(p2.x, p1.y, p1.z);
    glVertex3i(p2.x, p2.y, p1.z);
    glVertex3i(p1.x, p2.y, p1.z);

    // Seconde face
    glVertex3i(p2.x, p2.y, p2.z);
    glVertex3i(p1.x, p2.y, p2.z);
    glVertex3i(p1.x, p1.y, p2.z);
    glVertex3i(p2.x, p1.y, p2.z);

    // Jointures latérales
    glVertex3i(p2.x, p1.y, p1.z);
    glVertex3i(p2.x, p1.y, p2.z);
    glVertex3i(p2.x, p2.y, p2.z);
    glVertex3i(p2.x, p2.y, p1.z);

    glVertex3i(p1.x, p1.y, p1.z);
    glVertex3i(p1.x, p1.y, p2.z);
    glVertex3i(p1.x, p2.y, p2.z);
    glVertex3i(p1.x, p2.y, p1.z);

    // Jointure du haut
    glVertex3i(p1.x, p2.y, p1.z);
    glVertex3i(p2.x, p2.y, p1.z);
    glVertex3i(p2.x, p2.y, p2.z);
    glVertex3i(p1.x, p2.y, p2.z);

    glEnd();

    return p;
}

Piece creer_piece(Mur m1, Mur m2, Mur m3, Mur m4, Porte p1) {
    Piece piece;
    piece.liste_mur[0] = m1;
    piece.liste_mur[1] = m2;
    piece.liste_mur[2] = m3;
    piece.liste_mur[3] = m4;
    piece.liste_porte[0] = p1;
    
    return piece;
}


void creer_immeuble(Point depart, Texture t){

    float taille_mur = (float)TAILLE_IMMEUBLE / NOMBRE_MURS;
    float decalage = 0;

    // Premier mur
    for (int i = 0, decalage = 0; i < NOMBRE_MURS; i++, decalage += taille_mur){
        Point p1 = creer_point(depart.x + decalage, depart.y, depart.z);
        Point p2 = creer_point(depart.x + decalage + taille_mur, depart.y + 20, depart.z + LARGEUR_MUR);
        creer_mur(p1, p2, NON_TRAVERSABLE, t);
    }

    // Second mur
    for (int i = 0, decalage = 0; i < NOMBRE_MURS; i++, decalage += taille_mur){
            Point p1 = creer_point(depart.x + decalage, depart.y, depart.z + TAILLE_IMMEUBLE);
            Point p2 = creer_point(depart.x + decalage + taille_mur, depart.y + 20, depart.z + TAILLE_IMMEUBLE + LARGEUR_MUR);
            creer_mur(p1, p2, NON_TRAVERSABLE, t);
    }

    // Troisième mur
    for (int i = 0, decalage = 0; i < NOMBRE_MURS; i++, decalage += taille_mur){
        Point p1 = creer_point(depart.x - LARGEUR_MUR, depart.y, depart.z + decalage);
        Point p2 = creer_point(depart.x, depart.y + 20, depart.z + decalage + taille_mur);
        creer_mur(p1, p2, NON_TRAVERSABLE, t);
    }

    // Quatrième mur
    for (int i = 0, decalage = 0; i < NOMBRE_MURS; i++, decalage += taille_mur){
        Point p1 = creer_point(depart.x + TAILLE_IMMEUBLE - LARGEUR_MUR, depart.y, depart.z + decalage);
        Point p2 = creer_point(depart.x + TAILLE_IMMEUBLE, depart.y + 20, depart.z + decalage + taille_mur);
        creer_mur(p1, p2, NON_TRAVERSABLE, t);
    }
}

void test(Texture *t){


    Point p1 = creer_point(0, 0, 0); Point p2 = creer_point(10, 10, 0+LARGEUR_MUR);
    Point porte_p1 = creer_point(4, 0, 0); Point porte_p2 = creer_point(7, 8, 1);
    //glColor3f(0.0, 0.0, 1.0);
    Porte porte = creer_porte(porte_p1, porte_p2, *t);

    creer_mur_porte(p1, p2, NON_TRAVERSABLE, porte, *t);

    Point p3 = creer_point(-10, 0, -10); Point p4 = creer_point(-50, 15, -10 + LARGEUR_MUR);
    Point porte_p3 = creer_point(-15, 0, -10); Point porte_p4 = creer_point(-20, 9, -9);
    //glColor3f(0.0, 0.0, 1.0);

    Porte porte_2 = creer_porte(porte_p3, porte_p4, *t);

    creer_mur_porte(p3, p4, NON_TRAVERSABLE, porte_2, *t);
}




//tests
void drawMur(Mur *m){
    glBegin(GL_QUADS);

    //gauche
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(m->p1.x, m->p1.y, m->p1.z);
    glVertex3f(m->p1.x, m->p1.y, m->p2.z);
    glVertex3f(m->p1.x, m->p2.y, m->p2.z);
    glVertex3f(m->p1.x, m->p2.y, m->p1.z);
    //fond
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(m->p1.x, m->p1.y, m->p1.z);
    glVertex3f(m->p1.x, m->p2.y, m->p1.z);
    glVertex3f(m->p2.x, m->p2.y, m->p1.z);
    glVertex3f(m->p2.x, m->p1.y, m->p1.z);
    //droite
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(m->p2.x, m->p1.y, m->p1.z);
    glVertex3f(m->p2.x, m->p1.y, m->p2.z);
    glVertex3f(m->p2.x, m->p2.y, m->p2.z);
    glVertex3f(m->p2.x, m->p2.y, m->p1.z);
    //devant
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(m->p1.x, m->p1.y, m->p2.z);
    glVertex3f(m->p1.x, m->p2.y, m->p2.z);
    glVertex3f(m->p2.x, m->p2.y, m->p2.z);
    glVertex3f(m->p2.x, m->p1.y, m->p2.z);
    //bas
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(m->p1.x, m->p1.y, m->p1.z);
    glVertex3f(m->p2.x, m->p1.y, m->p1.z);
    glVertex3f(m->p2.x, m->p1.y, m->p2.z);
    glVertex3f(m->p1.x, m->p1.y, m->p2.z);
    //haut
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(m->p1.x, m->p2.y, m->p1.z);
    glVertex3f(m->p2.x, m->p2.y, m->p1.z);
    glVertex3f(m->p2.x, m->p2.y, m->p2.z);
    glVertex3f(m->p1.x, m->p2.y, m->p2.z);

    glEnd();
}

Mur murInit(Point p1, Point p2, int traversable){
    Mur m;
    m.traversable = NON_TRAVERSABLE;
    m.p1 = p1;
    m.p2 = p2;

    return m;
}

Porte porteInit(Point p1, Point p2){
    Porte p;
    p.p1 = p1;
    p.p2 = p2;

    return p;
}

void drawPorte(Porte p, Texture t){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, t.identifiant);
    glBegin(GL_QUADS);
    
    // Première face
    glTexCoord2f(-0.5,0.0);
    glVertex3f(p.p1.x, p.p1.y, p.p1.z);
    glTexCoord2d(1.0,0.0);
    glVertex3f(p.p2.x, p.p1.y, p.p1.z);
    glTexCoord2d(1.0,1.0);
    glVertex3f(p.p2.x, p.p2.y, p.p1.z);
    glTexCoord2d(-1.0,1.0);
    glVertex3f(p.p1.x, p.p2.y, p.p1.z);

    // Seconde face
    glTexCoord2d(0.0,0.0);
    glVertex3f(p.p1.x, p.p1.y, p.p2.z);
    glTexCoord2d(1.0,0.0);
    glVertex3f(p.p2.x, p.p1.y, p.p2.z);
    glTexCoord2d(1.0,1.0);
    glVertex3f(p.p2.x, p.p2.y, p.p2.z);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(p.p1.x, p.p2.y, p.p2.z);

    glEnd();
    glDisable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
     // Jointures latérales
    //glColor3f(0.2, 0.2, 0.8);
    glVertex3f(p.p2.x, p.p1.y, p.p1.z);
    glVertex3f(p.p2.x, p.p1.y, p.p2.z);
    glVertex3f(p.p2.x, p.p2.y, p.p2.z);
    glVertex3f(p.p2.x, p.p2.y, p.p1.z);

    glVertex3f(p.p1.x, p.p1.y, p.p1.z);
    glVertex3f(p.p1.x, p.p1.y, p.p2.z);
    glVertex3f(p.p1.x, p.p2.y, p.p2.z);
    glVertex3f(p.p1.x, p.p2.y, p.p1.z);

    // Jointure du haut
    glVertex3f(p.p1.x, p.p2.y, p.p1.z);
    glVertex3f(p.p2.x, p.p2.y, p.p1.z);
    glVertex3f(p.p2.x, p.p2.y, p.p2.z);
    glVertex3f(p.p1.x, p.p2.y, p.p2.z);
    glEnd();

}

