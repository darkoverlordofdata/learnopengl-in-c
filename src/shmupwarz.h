#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <glad/glad.h>
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
extern void Shmupwarz_Initialize(Shmupwarz* this);
extern void Shmupwarz_LoadContent(Shmupwarz* this);
extern void Shmupwarz_Update(Shmupwarz* this);
extern void Shmupwarz_Draw(Shmupwarz* this);
extern void Shmupwarz_Run(Shmupwarz* this);

