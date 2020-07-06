#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>
#include <corefw/corefw.h>
#include <dna.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

typedef struct Triangle Triangle;
extern const CFWClass *TriangleClass;
struct TriangleVtbl;

extern void* Triangle_New(char* title, int width, int height);
extern void Triangle_Initialize(Triangle* this);
extern void Triangle_LoadContent(Triangle* this);
extern void Triangle_Update(Triangle* this);
extern void Triangle_Draw(Triangle* this);
extern void Triangle_Run(Triangle* this);

