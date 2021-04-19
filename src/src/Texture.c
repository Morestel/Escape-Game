#include "Texture.h"

Texture Charger_Texture(char *adresse_image, int width, int height){

    Texture t;
    glEnable(GL_TEXTURE_2D);
    
    FILE * file;
    file = fopen(adresse_image, "rb");
    if (file == NULL) 
        exit(EXIT_FAILURE);
    unsigned char *data = (unsigned char *)malloc(width * height * 3);
    fread(data, width * height *3 , 1, file);
    fclose(file);
    GLuint id_texture;
    //Genere la texture dans OpenGL
    glGenTextures(1, &id_texture);
    
    //On la bind
    glBindTexture(GL_TEXTURE_2D, id_texture);
    gluBuild2DMipmaps(GL_TEXTURE_2D,     // texture to specify
                     GL_RGB,           // internal texture storage format
                     width,             // texture width
                     height,            // texture height
                     GL_RGB,           // pixel format
                     GL_UNSIGNED_BYTE,	// color component format
                     data);    // pointer to texture image
    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_LINEAR);
    glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    

    t.identifiant = id_texture;

    return t;
}