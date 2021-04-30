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

    
      GLuint texture;
      int width, height;
      unsigned char * data;

      FILE * file;
      file = fopen( filename, "rb" );

      if ( file == NULL ) return 0;
      width = 1024;
      height = 512;
      data = (unsigned char *)malloc( width * height * 3 );
      //int size = fseek(file,);
      fread( data, width * height * 3, 1, file );
      fclose( file );

      for(int i = 0; i < width * height ; ++i)
      {
        int index = i*3;
        unsigned char B,R;
        B = data[index];
        R = data[index+2];

        data[index] = R;
        data[index+2] = B;
      }

      glGenTextures( 1, &texture );
      glBindTexture( GL_TEXTURE_2D, texture );
      glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
      glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

      glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
      glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
      glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
      gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
      free( data );

      return texture;
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

