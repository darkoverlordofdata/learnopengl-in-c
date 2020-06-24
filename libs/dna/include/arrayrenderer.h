#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <corefw/class.h>
#include "rect.h"
#include "texture2d.h"
#include "tglm.h"

typedef struct DNAArrayRenderer DNAArrayRenderer;
extern const CFWClass *dna_sprite_renderer;

extern void* DNA_ArrayRenderer(DNAShader* shader);

extern void DNA_ArrayRendererDraw(
    DNAArrayRenderer* this, 
    DNATexture2D* texture, 
    DNARect* bounds,
    GLfloat 
    rotate, 
    Vec3 color);

extern void DNA_ArrayRendererDraw2(
    DNAArrayRenderer* this, 
    DNATexture2D* texture, 
    Vec2 position, 
    Vec2 size, 
    GLfloat rotate, 
    Vec3 color);


