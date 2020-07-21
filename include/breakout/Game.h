/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cfw.h>
#include <dna.h>

#define IsGame(object) _Generic((object), Game * \
                                : true, default  \
                                : false)
#define AsGame(object) _Generic((object),        \
                                Game *           \
                                : (Game*)object, \
                                default          \
                                : NULL)

typedef struct Collision Collision;
typedef struct Game Game;
extern const CFWClass* GameClass;
extern DNAResourceManager* ResourceManager;

// Represents the current state of the game
typedef enum {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
} GameState;

extern method void* New(Game* this, int Width, int Height);

extern method void SetKey(Game* this, int key, bool value);

extern method void SetState(Game* this, GameState state);

extern method void Start(Game* this);

extern method void Update(Game* this, GLfloat dt);

extern method void ProcessInput(Game* this, GLfloat dt);

extern method void Render(Game* this);

extern method void ResetLevel(Game* this);

extern method void ResetPlayer(Game* this);

extern method void Dispose(Game* this);

extern method void DoCollisions(Game* this);

extern method char* ToString(Game* this);
