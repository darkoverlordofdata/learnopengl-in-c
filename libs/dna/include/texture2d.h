#pragma once
#include <GL/gl.h>
#include <corefw/class.h>
#include "tglm.h"

/**
 * class DNATexture2D
 */
struct DNATexture2D;
extern const CFWClass *DNATexture2D;

extern void* DNATexture2D_New(GLuint internalFormat, GLuint imageFormat, char* path);

extern void DNATexture2D_Generate(
    struct DNATexture2D* this, 
    GLuint width, 
    GLuint height, 
    unsigned char* data);

extern void DNATexture2D_Bind(struct DNATexture2D* this);

extern char* DNATexture2D_ToString(struct DNATexture2D* this);
