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

typedef struct Shmupwarz Shmupwarz;
extern const CFWClass *ShmupwarzClass;
struct ShmupwarzVtbl;

extern void* Shmupwarz_New(char* title, int width, int height);
extern method void Initialize(Shmupwarz* this);
extern method void LoadContent(Shmupwarz* this);
extern method void Update(Shmupwarz* this);
extern method void Draw(Shmupwarz* this);
extern method void Run(Shmupwarz* this);

