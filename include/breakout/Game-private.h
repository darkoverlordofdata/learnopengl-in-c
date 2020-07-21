/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#pragma once

#include "BallObject.h"
#include "Game.h"
#include "GameLevel.h"
#include "GameObject.h"

struct Game {
    CFWObject obj;
    GameState State;
    bool Keys[1024];
    GLuint Width;
    GLuint Height;
    CFWArray* Levels;
    GLuint Level;
};
