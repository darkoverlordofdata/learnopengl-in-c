#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <corefw/class.h>
#include "rect.h"
#include "texture2d.h"
#include "tglm.h"

// typedef struct DNAArrayRenderer DNAArrayRenderer;
struct DNAArrayRenderer;
extern const CFWClass *DNAArrayRenderer;

extern void* DNAArrayRenderer_New(struct DNAShader* shader);

extern void DNAArrayRenderer_Draw(
    struct DNAArrayRenderer* this, 
    struct DNATexture2D* texture, 
    struct DNARect* bounds,
    GLfloat 
    rotate, 
    Vec3 color);

extern void DNAArrayRenderer_Draw2(
    struct DNAArrayRenderer* this, 
    struct DNATexture2D* texture, 
    Vec2 position, 
    Vec2 size, 
    GLfloat rotate, 
    Vec3 color);


