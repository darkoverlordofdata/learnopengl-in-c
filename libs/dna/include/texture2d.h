#pragma once
#include <GL/gl.h>
#include <corefw/class.h>
#include "tglm.h"

/**
 * class DNATexture2D
 */
typedef struct DNATexture2D DNATexture2D;
extern const CFWClass *DNATexture2DClass;

extern void* DNATexture2D_New(GLuint internalFormat, GLuint imageFormat, char* path);

extern void DNATexture2D_Generate(
    DNATexture2D* this, 
    GLuint width, 
    GLuint height, 
    unsigned char* data);

// extern void DNATexture2D_Bind(const DNATexture2D* this);
extern void method Bind(const DNATexture2D* this);

// extern char* DNATexture2D_ToString(const DNATexture2D* this);
char* __attribute__((overloadable)) ToString(const DNATexture2D* this);

