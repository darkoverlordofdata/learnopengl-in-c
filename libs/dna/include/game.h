#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "corefw/class.h"

struct DNAGame;
struct DNAGameVtbl;
extern const CFWClass *DNAGame;

struct DNAGameVtbl {
    void (*Initialize)  (void* const self);
    void (*LoadContent) (void* const self);
    void (*Update)      (void* const self);
    void (*Draw)        (void* const self);
};

extern void* DNAGame_New(char* cstr, int width, int height, void* subclass, struct DNAGameVtbl *vptr);


/**
 * DNAGame::HandleEvents
 */
extern void DNAGame_HandleEvents(struct DNAGame* const this);

/**
 * DNAGame::Start
 */
extern void DNAGame_Start(struct DNAGame* const this);

/**
 * DNAGame::Tick
 */
extern void DNAGame_Tick(struct DNAGame* const this);

/**
 * DNAGame::RunLoop
 */
extern void DNAGame_RunLoop(struct DNAGame* const this);

/**
 * DNAGame::Run
 */
extern void DNAGame_Run(struct DNAGame* const this); 

/**
 * DNAGame::Initialize
 */
extern void DNAGame_Initialize(struct DNAGame* const this);

/**
 * DNAGame::LoadContent
 */
extern void DNAGame_LoadContent(struct DNAGame* const this);

/**
 * DNAGame::Update
 */
extern void DNAGame_Update(struct DNAGame* const this);

/**
 * DNAGame::Draw
 */
extern void DNAGame_Draw(struct DNAGame* const this);


