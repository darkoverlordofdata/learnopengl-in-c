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

typedef struct DNAGame DNAGame;
struct DNAGameVtbl;
extern const CFWClass *DNAGameClass;

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
extern void DNAGame_HandleEvents(DNAGame* const this);

/**
 * DNAGame::Start
 */
extern void DNAGame_Start(DNAGame* const this);

/**
 * DNAGame::Tick
 */
extern void DNAGame_Tick(DNAGame* const this);

/**
 * DNAGame::RunLoop
 */
extern void DNAGame_RunLoop(DNAGame* const this);

/**
 * DNAGame::Run
 */
extern void DNAGame_Run(DNAGame* const this); 

/**
 * DNAGame::Initialize
 */
extern void DNAGame_Initialize(DNAGame* const this);

/**
 * DNAGame::LoadContent
 */
extern void DNAGame_LoadContent(DNAGame* const this);

/**
 * DNAGame::Update
 */
extern void DNAGame_Update(DNAGame* const this);

/**
 * DNAGame::Draw
 */
extern void DNAGame_Draw(DNAGame* const this);


