#pragma once
#include "cfw.h"
#include "shmupwarz.h"
#include <game-private.h>

struct Shmupwarz {
    DNAGame game;
    DNATexture2D* bg;
    DNAElementRenderer* renderer;
    DNAShader* shader;
    DNAResourceManager* resource;
    // ArtemisEntity* mPlayer;
    // id mSystems;
    // ArtemisWorld* mWorld;
};
