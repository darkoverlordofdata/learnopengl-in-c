#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <corefw/class.h>
#include "rect.h"
#include "texture2d.h"
#include "tglm.h"

// typedef struct DNAElementRenderer DNAElementRenderer;
struct DNAElementRenderer;
extern const CFWClass *DNAElementRenderer;

extern void* DNAElementRenderer_New(struct DNAShader* shader);

extern void DNAElementRenderer_Draw(
    struct DNAElementRenderer* this, 
    struct DNATexture2D* texture, 
    struct DNARect bounds,
    GLfloat 
    rotate, 
    Vec3 color);

extern void DNAElementRenderer_Draw2(
    struct DNAElementRenderer* this, 
    struct DNATexture2D* texture, 
    Vec2 position, 
    Vec2 size, 
    GLfloat rotate, 
    Vec3 color);


