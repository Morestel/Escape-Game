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
/*
    Texture t;
    FILE * file;
    file = fopen(adresse_image, "rb");
    if (file == NULL) 
        exit(EXIT_FAILURE);
    unsigned char *data = (unsigned char *)malloc(width * height *3);
    
    fread(data, width * height *3 , 1, file);
    fclose(file);
    GLuint id_texture;

    glEnable(GL_TEXTURE_2D);
    //Genere la texture dans OpenGL
    glGenTextures(1, &id_texture);
    glBindTexture(GL_TEXTURE_2D, id_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    free(data);
    
    t.identifiant = id_texture;
    return t;
*/
    
        Texture t;
        glEnable(GL_TEXTURE_2D);

      unsigned char * data;

      FILE * file;
      file = fopen( adresse_image, "rb" );

      data = (unsigned char *)malloc( width * height * 3 );
      //int size = fseek(file,);
      int32_t offset;
if (fseek(file, 0x0A, SEEK_SET) == -1
	|| fread(&offset, sizeof offset, 1, file) != 1
	/*|| fseek(file, 0x12, SEEK_SET) == -1
	|| fread(&w, sizeof w, 1, f) != 1
	|| fseek(file, 0x16, SEEK_SET) == -1
	|| fread(&h, sizeof w, 1, f) != 1 */
	|| fseek(file, offset, SEEK_SET) == -1) {
	fputs("Can't open BMP file: Bad file\n", stderr);
	exit(-1);
}
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
    
      glGenTextures( 1, &t.identifiant );
      glBindTexture( GL_TEXTURE_2D, t.identifiant );
      glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
      glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

      glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
      glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
      glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
      gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
      free( data );

      return t;
/*
    
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

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    t.identifiant = id_texture;
    glDisable(GL_TEXTURE_2D);
    return t;
    */
}

