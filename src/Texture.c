#include "Texture.h"
/*
Texture Charger_Texture(char *adresse_image, int width, int height){

    Texture t;
    //glClearColor(.5,.5,.5,0);
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
    gluBuild2DMipmaps(GL_TEXTURE_2D,     
                     GL_RGB,           
                     width,            
                     height,            
                     GL_RGB,           
                     GL_UNSIGNED_BYTE,	
                     data); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    //glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    

    t.identifiant = id_texture;

    return t;
}*/

Texture Charger_Texture(char *adresse_image, int width, int height){

    Texture t;
    glEnable(GL_TEXTURE_2D);
    
    FILE * file;
    file = fopen(adresse_image, "rb");
    if (file == NULL) 
        exit(EXIT_FAILURE);
    unsigned char *data = (unsigned char *)malloc(width * height *3);
    fread(data, width * height *3 , 1, file);
    fclose(file);
    GLuint id_texture;
    //Genere la texture dans OpenGL
    glGenTextures(1, &id_texture);
    
    //On la bind
    glBindTexture(GL_TEXTURE_2D, id_texture);

    gluBuild2DMipmaps(GL_TEXTURE_2D,     
                     GL_RGB,           
                     width,            
                     height,            
                     GL_RGB,           
                     GL_UNSIGNED_BYTE,	
                     data); 
/*
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  */  

    t.identifiant = id_texture;
    glDisable(GL_TEXTURE_2D);
    return t;
}

