#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "corefw/class.h"
#include "resourcemanager.h"
typedef struct DNAGame DNAGame;
struct DNAGameVtbl;
extern const CFWClass *dna_game;

// 
struct DNAGameVtbl {
    void (*Initialize)  (void* const self);
    void (*LoadContent) (void* const self);
    void (*Update)      (void* const self);
    void (*Draw)        (void* const self);
};

extern void* DNA_Game(char* cstr, int width, int height, void* super, struct DNAGameVtbl *vptr);


/**
 * DNAGame::HandleEvents
 */
extern void DNA_GameHandleEvents(DNAGame* const this);

/**
 * DNAGame::Start
 */
extern void DNA_GameStart(DNAGame* const this);

/**
 * DNAGame::Tick
 */
extern void DNA_GameTick(DNAGame* const this);

/**
 * DNAGame::RunLoop
 */
extern void DNA_GameRunLoop(DNAGame* const this);

/**
 * DNAGame::Run
 */
extern void DNA_GameRun(DNAGame* const this); 

/**
 * DNAGame::Initialize
 */
extern void DNA_GameInitialize(DNAGame* const this);

/**
 * DNAGame::LoadContent
 */
extern void DNA_GameLoadContent(DNAGame* const this);

/**
 * DNAGame::Update
 */
extern void DNA_GameUpdate(DNAGame* const this);

/**
 * DNAGame::Draw
 */
extern void DNA_GameDraw(DNAGame* const this);


/*
 * properties
 */
extern void DNA_GameSetResourceManager(DNAGame* const this, DNAResourceManager* rm);

// extern SDL_Window* DNA_GameGetWindow(DNAGame* const this);
extern void* DNA_GameGetWindow(DNAGame* const this);
extern void* DNA_GameGetResource(DNAGame* const this);