#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <corefw/class.h>
#include "rect.h"
#include "texture2d.h"
#include "tglm.h"

typedef struct DNAElementRenderer DNAElementRenderer;
extern const CFWClass *DNAElementRendererClass;

extern void* DNAElementRenderer_New(DNAShader* shader);

extern void DNAElementRenderer_Draw(
    const DNAElementRenderer* this, 
    DNATexture2D* texture, 
    DNARect bounds,
    GLfloat 
    rotate, 
    Vec3 color);

// extern void DNAElementRenderer_Draw2(
//     DNAElementRenderer* this, 
//     DNATexture2D* texture, 
//     Vec2 position, 
//     Vec2 size, 
//     GLfloat rotate, 
//     Vec3 color);


