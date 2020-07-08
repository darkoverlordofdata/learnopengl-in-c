#pragma once
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>
#include <corefw/corefw.h>

#include "rect.h"
#include "texture2d.h"
#include "tglm.h"

typedef struct DNAElementRenderer DNAElementRenderer;
extern const CFWClass* DNAElementRendererClass;

extern void* DNAElementRenderer_New(DNAShader* shader);

extern void DNAElementRenderer_Draw(
    const DNAElementRenderer* this,
    DNATexture2D* texture,
    DNARect bounds,
    GLfloat rotate,
    Vec3 color);

// extern void DNAElementRenderer_Draw2(
//     DNAElementRenderer* this,
//     DNATexture2D* texture,
//     Vec2 position,
//     Vec2 size,
//     GLfloat rotate,
//     Vec3 color);
