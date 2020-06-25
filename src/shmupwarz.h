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
#include <dna.h>

#include "corefw/object.h"
#include "corefw/string.h"
#include "corefw/hash.h"
#include "corefw/class.h"

struct Shmupwarz;
extern const CFWClass *Shmupwarz;
struct ShmupwarzVtbl;

extern void Shmupwarz_Initialize(struct Shmupwarz* this);
extern void Shmupwarz_LoadContent(struct Shmupwarz* this);
extern void Shmupwarz_Update(struct Shmupwarz* this);
extern void Shmupwarz_Draw(struct Shmupwarz* this);
extern void Shmupwarz_Run(struct Shmupwarz* this);

