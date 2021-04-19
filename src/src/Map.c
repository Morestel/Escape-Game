#include "Map.h"

Point creer_point(float x, float y, float z){
    Point p;
    p.x = x;
    p.y = y;
    p.z = z;

    return p;
}


Mur creer_mur(Point p1, Point p2, int traversable){
    Mur m;
    m.traversable = traversable;
    m.p1 = p1;
    m.p2 = p2;

    glEnable(GL_TEXTURE_2D);

    int width = 1000, height = 1000;
    FILE * file;
    unsigned char * data;
    file = fopen("mur.png", "rb" );
    if ( file == NULL ) 
        return m;
    data = (unsigned char *)malloc( width * height * 4 );
    fread( data, width * height * 4, 1, file );
    fclose( file );
    GLuint id_texture;
    //Genere la texture dans OpenGL
    glGenTextures(1, &id_texture);

    //On la bind
    glBindTexture(GL_TEXTURE_2D, id_texture);
/*
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
*/
    //On charge l'image dans la texture OPENGL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    //On genere le Mipmap
    //glGenerateMipmap(GL_TEXTURE_2D);


glBindTexture(GL_TEXTURE_2D, id_texture);
    glBegin(GL_QUADS);
    

    // Premiere face
    glTexCoord2d(0,1);
    glVertex3i(p1.x, p1.y, p1.z);
    glTexCoord2d(0,0);
    glVertex3i(p2.x, p1.y, p1.z);
    glTexCoord2d(1,0);
    glVertex3i(p2.x, p2.y, p1.z);
    glTexCoord2d(1,1);
    glVertex3i(p1.x, p2.y, p1.z);
    
    // Seconde face
    glTexCoord2d(0,1);
    glVertex3i(p2.x, p2.y, p2.z);
    glTexCoord2d(0,0);
    glVertex3i(p1.x, p2.y, p2.z);
    glVertex3i(p1.x, p1.y, p2.z);
    glVertex3i(p2.x, p1.y, p2.z);
    
    // Premiere jointure
    glTexCoord2d(0,1);
    glVertex3i(p2.x, p2.y, p2.z);
    glTexCoord2d(0,0);
    glVertex3i(p2.x, p2.y, p1.z);
    glTexCoord2d(1,0);
    glVertex3i(p2.x, p1.y, p1.z);
    glTexCoord2d(1,1);
    glVertex3i(p2.x, p1.y, p2.z);
    
    // Seconde jointure
    glTexCoord2d(0,1);
    glVertex3i(p1.x, p1.y, p1.z);
    glTexCoord2d(0,0);
    glVertex3i(p1.x, p2.y, p1.z);
    glTexCoord2d(1,0);
    glVertex3i(p1.x, p2.y, p2.z);
    glTexCoord2d(1,1);
    glVertex3i(p1.x, p1.y, p2.z);
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
    return m;
}

Mur creer_mur_porte(Point p1, Point p2, int traversable, Porte porte){
    Mur m;
    m.p1 = p1; m.p2 = p2; m.traversable = traversable;

    Point premiere_partie = creer_point(porte.p1.x, p2.y, p2.z);
    glColor3f(1.0, 0.0, 0.0);
    
    creer_mur(p1, premiere_partie, traversable);
    
    Point seconde_partie = creer_point(porte.p2.x, p1.y, p1.z);
    glColor3f(0.0,1.0,0.0);
    creer_mur(seconde_partie, p2, traversable);
      
    glColor3f(0.8, 0.1, 0.2);
    Point jointure_1 = creer_point(porte.p1.x, porte.p2.y, porte.p1.z);
    Point jointure_2 = creer_point(porte.p2.x, p2.y, p2.z);
    creer_mur(jointure_1, jointure_2, NON_TRAVERSABLE);
    
    return m;
}

Porte creer_porte(Point p1, Point p2){
    Porte p;
    p.p1 = p1;
    p.p2 = p2;
    
    creer_mur(p1, p2, NON_TRAVERSABLE);

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
