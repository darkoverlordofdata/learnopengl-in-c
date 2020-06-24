#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <corefw/class.h>
#include "rect.h"
#include "texture2d.h"
#include "tglm.h"

typedef struct DNAElementRenderer DNAElementRenderer;
extern const CFWClass *dna_vertex_renderer;

extern void* DNA_ElementRenderer(DNAShader* shader);

extern void DNA_ElementRendererDraw(
    DNAElementRenderer* this, 
    DNATexture2D* texture, 
    DNARect bounds,
    GLfloat 
    rotate, 
    Vec3 color);

extern void DNA_ElementRendererDraw2(
    DNAElementRenderer* this, 
    DNATexture2D* texture, 
    Vec2 position, 
    Vec2 size, 
    GLfloat rotate, 
    Vec3 color);


