#pragma once
#include <GL/gl.h>
#include <corefw/class.h>
#include "tglm.h"

typedef struct DNATexture2D DNATexture2D;
extern const CFWClass *dna_texture2d;

extern void* DNA_Texture2D(GLuint internalFormat, GLuint imageFormat, char* path);

extern void DNA_Texture2DGenerate(
    DNATexture2D* this, 
    GLuint width, 
    GLuint height, 
    unsigned char* data);

extern void DNA_Texture2DBind(DNATexture2D* this);

extern char* DNA_Texture2DToString(DNATexture2D* this);
