#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <corefw/class.h>
#include "rect.h"
#include "texture2d.h"
#include "tglm.h"

typedef struct DNAArrayRenderer DNAArrayRenderer;
extern const CFWClass *DNAArrayRendererClass;

extern void* DNAArrayRenderer_New(DNAShader* shader);

extern void DNAArrayRenderer_Draw(
    const DNAArrayRenderer* this, 
    DNATexture2D* texture, 
    DNARect* bounds,
    GLfloat 
    rotate, 
    Vec3 color);

