/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#pragma once
#include "Game.h"
#include "BallObject-private.h"
#include "BallObject.h"
#include "Collision-private.h"
#include "Collision.h"
#include "Game-private.h"
#include "GameLevel-private.h"
#include "GameLevel.h"
#include "GameObject-private.h"
#include "GameObject.h"
#include "Particle-private.h"
#include "Particle.h"

corefw(Game);
/**
 * Create new game
 */
static bool ctor(void* self, va_list args) { return true; }
static bool equal(void* ptr1, void* ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void* self) { return (uint32_t)self; }
static void* copy(void* self) { return NULL; }
static void dtor(void* self) {}

// Initial size of the player paddle
static const Vec2 PLAYER_SIZE = { 100, 20 };
// Initial velocity of the player paddle
static const GLfloat PLAYER_VELOCITY = 500.0f;
// Initial velocity of the Ball
static const Vec2 INITIAL_BALL_VELOCITY = { 100.0f, -350.0f };
// Radius of the ball object
static const GLfloat BALL_RADIUS = 12.5f;

static const Vec2 ZERO = { 0, 0 };
static const Vec3 WHITE = { 1, 1, 1 };

// Game-related State data
DNAResourceManager* ResourceManager;
static DNAArrayRenderer* Renderer;
static GameObject* Player;
static BallObject* Ball;


/**
 * Create Game instance
 * 
 * @param Width of screen
 * @param Height of screen
 * 
 */
method void* New(
    Game* this,
    int Width,
    int Height)
{
    this->Levels = cfw_new(cfw_array, NULL);
    this->Level = 0;
    this->State = GAME_ACTIVE;
    this->Width = Width;
    this->Height = Height;
    ResourceManager = new (DNAResourceManager);
    return this;
}

method void SetKey(Game* this, int key, bool value)
{
    this->Keys[key] = value;
}

method void SetState(Game* this, GameState state)
{
    this->State = state;
}

/**
 * Start the game
 */
method void Start(Game* this)
{

    // Load shaders
    LoadShader(ResourceManager, "data/shaders/core/sprite.vs", "data/shaders/core/sprite.frag", "sprite");
    // Configure shaders
    Mat projection = glm_ortho(0, (GLfloat)this->Width, (GLfloat)this->Height, 0, -1, 1);
    DNAShader* shader = GetShader(ResourceManager, "sprite");
    Use(shader);
    SetInteger(shader, "sprite", 0);
    SetMatrix(shader, "projection", &projection);

    // Load textures
    LoadTexture(ResourceManager, "data/textures/block.png", false, "block");
    LoadTexture(ResourceManager, "data/textures/paddle.png", false, "paddle");
    LoadTexture(ResourceManager, "data/textures/block.png", false, "block");
    LoadTexture(ResourceManager, "data/textures/block_solid.png", false, "block_solid");
    LoadTexture(ResourceManager, "data/textures/awesomeface.png", true, "face");
    LoadTexture(ResourceManager, "data/textures/background.jpg", false, "background");
    // Set render-specific controls
    Renderer = new (DNAArrayRenderer, GetShader(ResourceManager, "sprite"));
    // Load levels

    Add(this->Levels, new (GameLevel, "data/levels/one.lvl", this->Width, (this->Height * 0.5)));
    Add(this->Levels, new (GameLevel, "data/levels/two.lvl", this->Width, this->Height * 0.5));
    Add(this->Levels, new (GameLevel, "data/levels/three.lvl", this->Width, this->Height * 0.5));
    Add(this->Levels, new (GameLevel, "data/levels/four.lvl", this->Width, this->Height * 0.5));

    // Configure game objects
    Vec2 playerPos = (Vec2) { this->Width / 2 - PLAYER_SIZE.x / 2, this->Height - PLAYER_SIZE.y };
    Player = new (GameObject, "player", playerPos, PLAYER_SIZE, GetTexture(ResourceManager, "paddle"), WHITE);
    Vec2 ballPos = playerPos + (Vec2) { PLAYER_SIZE.x / 2 - BALL_RADIUS, -BALL_RADIUS * 2 };
    Ball = new (BallObject, ballPos, BALL_RADIUS, INITIAL_BALL_VELOCITY, GetTexture(ResourceManager, "face"));
}

/**
 * Update
 * 
 * @param dt deltat time
 */
method void Update(Game* this, GLfloat dt)
{
    // Update objects
    Move(Ball, dt, this->Width);
    // Check for collisions

    DoCollisions(this);
    // Check loss condition
    if (Ball->Position.x >= this->Height) // Did ball reach bottom edge?
    {
        ResetLevel(this);
        ResetPlayer(this);
    }
}

/**
 * ProcessInput
 * 
 * @param dt deltat time
 */
method void ProcessInput(Game* this, GLfloat dt)
{
    if (this->State == GAME_ACTIVE) {
        GLfloat velocity = PLAYER_VELOCITY * dt;
        // Move playerboard
        if (this->Keys[GLFW_KEY_A] || this->Keys[GLFW_KEY_LEFT]) {
            if (Player->Position.x >= 0) {
                Player->Position.x -= velocity;
                if (Ball->Stuck)
                    Ball->Position.x -= velocity;
            }
        }
        if (this->Keys[GLFW_KEY_D] || this->Keys[GLFW_KEY_RIGHT]) {
            if (Player->Position.x <= this->Width - Player->Size.x) {
                Player->Position.x += velocity;
                if (Ball->Stuck)
                    Ball->Position.x += velocity;
            }
        }
        if (this->Keys[GLFW_KEY_SPACE])
            Ball->Stuck = false;
    }
}

/**
 * Render
 * 
 */
method void Render(Game* this)
{
    if (this->State == GAME_ACTIVE) {
        // Draw background
        DNARect bounds = { 0, 0, this->Width, this->Height };
        Draw(Renderer, GetTexture(ResourceManager, "background"), &bounds, 0.0f, WHITE);
        GameLevel* level = (GameLevel*)Get(this->Levels, this->Level);
        Draw(level, Renderer);
        Draw(Player, Renderer);
        Draw(Ball, Renderer);
    }
}

/**
 * ResetLevel
 * 
 */
method void ResetLevel(Game* this)
{
    if (this->Level == 0) {
        GameLevel* level = Get(this->Levels, 0);
        Load(level, "data/levels/one.lvl", this->Width, this->Height * 0.5f);
    } else if (this->Level == 1) {
        GameLevel* level = Get(this->Levels, 1);
        Load(level, "data/levels/two.lvl", this->Width, this->Height * 0.5f);
    } else if (this->Level == 2) {
        GameLevel* level = Get(this->Levels, 2);
        Load(level, "data/levels/three.lvl", this->Width, this->Height * 0.5f);
    } else if (this->Level == 3) {
        GameLevel* level = Get(this->Levels, 3);
        Load(level, "data/levels/four.lvl", this->Width, this->Height * 0.5f);
    }
}

/**
 * ResetPlayer
 * 
 */
method void ResetPlayer(Game* this)
{
    Player->Size = PLAYER_SIZE;
    Player->Position = (Vec2) { this->Width / 2 - PLAYER_SIZE.x / 2, this->Height - PLAYER_SIZE.y };
    Reset(Ball, Player->Position + (Vec2) { PLAYER_SIZE.x / 2 - BALL_RADIUS, -(BALL_RADIUS * 2) }, INITIAL_BALL_VELOCITY);
}

/**
 * Release game resources
 */
method void Dispose(Game* this)
{
}

//===============================================================//
// -------------------- C O L L I S I O N S -------------------- //
//===============================================================//

/**
 * Calculates which direction a vector is facing (N,E,S or W)
 * 
 */
static inline Direction ArrayDirection(Vec2 target)
{
    Vec2 compass[4] = {
        { 0.0f, 1.0f }, // up
        { 1.0f, 0.0f }, // right
        { 0.0f, -1.0f }, // down
        { -1.0f, 0.0f } // left
    };
    GLfloat max = 0.0f;
    GLuint best_match = -1;
    target = glm_normalize(target);
    for (GLuint i = 0; i < 4; i++) {
        GLfloat dot_product = glm_dot(target, compass[i]);
        if (dot_product > max) {
            max = dot_product;
            best_match = i;
        }
    }
    return (Direction)best_match;
}

/**
 * CheckCollision2
 * 
 * @param one first game object to check
 * @param two second game object to check
 * 
 */
static inline GLboolean CheckCollision2(Game* this, GameObject* one, GameObject* two) // AABB - AABB collision
{
    // Collision x-axis?
    bool collisionX = one->Position.x + one->Size.x >= two->Position.x && two->Position.x + two->Size.x >= one->Position.x;
    // Collision y-axis?
    bool collisionY = one->Position.y + one->Size.y >= two->Position.y && two->Position.y + two->Size.y >= one->Position.y;
    // Collision only if on both axes
    return collisionX && collisionY;
}

/**
 * CheckCollision2
 * 
 * @param one first ball object to check
 * @param two second game object to check
 * 
 */
static inline Collision* CheckCollision(
    Game* this,
    BallObject* one,
    GameObject* two) // AABB - Circle collision
{
    // Get center point circle first
    Vec2 center = { one->Position + one->Radius };
    // Calculate AABB info (center, half-extents)
    Vec2 aabb_half_extents = { two->Size.x / 2, two->Size.y / 2 };
    Vec2 aabb_center = { two->Position.x + aabb_half_extents.x, two->Position.y + aabb_half_extents.y };
    // Get difference vector between both centers
    Vec2 difference = center - aabb_center;

    Vec2 clamped = glm_clamp(difference, -aabb_half_extents, aabb_half_extents);

    // Now that we know the the clamped values, add this to AABB_center and we get the value of box closest to circle
    Vec2 closest = aabb_center + clamped;
    // Now retrieve vector between center circle and closest point AABB and check if length < radius
    difference = closest - center;

    if (glm_length(difference) < one->Radius) // not <= since in that case a collision also occurs when object one exactly touches object two, which they are at the end of each collision resolution stage.
        return new (Collision, true, ArrayDirection(difference), difference);
    else
        return new (Collision, false, UP, (Vec2) { 0, 0 });
}

/**
 * DoCollisions
 * 
 */
method void DoCollisions(Game* this)
{
    GameLevel* level = Get(this->Levels, this->Level);
    CFWArray* bricks = level->Bricks;

    for (int i = 0; i < Length(bricks); i++) {
        GameObject* box = (GameObject*)Get(bricks, i);
        // TGameObject box = bricks->data[i];

        if (!box->Destroyed) {
            Collision* collision = CheckCollision(this, Ball, box);
            if (collision->IsTrue) // If collision is true
            {
                // Destroy block if not solid
                if (!box->IsSolid)
                    box->Destroyed = GL_TRUE;
                // Collision resolution
                Direction dir = collision->Dir;
                Vec2 diff_vector = collision->Vec;
                if (dir == LEFT || dir == RIGHT) // Horizontal collision
                {
                    Ball->Velocity.x = -Ball->Velocity.x; // Reverse horizontal velocity
                    // Relocate
                    GLfloat penetration = Ball->Radius - abs(diff_vector.x);
                    if (dir == LEFT)
                        Ball->Position.x += penetration; // Move ball to right
                    else
                        Ball->Position.x -= penetration; // Move ball to left;
                } else // Vertical collision
                {
                    Ball->Velocity.y = -Ball->Velocity.y; // Reverse vertical velocity
                    // Relocate
                    GLfloat penetration = Ball->Radius - abs(diff_vector.y);
                    if (dir == UP)
                        Ball->Position.y -= penetration; // Move ball bback up
                    else
                        Ball->Position.y += penetration; // Move ball back down
                }
            }
            // DSFree(collision);
        }
    }
    // Also check collisions for player pad (unless stuck)
    Collision* result = CheckCollision(this, Ball, Player);
    if (!Ball->Stuck && result->Dir) {
        // Check where it hit the board, and change velocity based on where it hit the board
        GLfloat centerBoard = Player->Position.x + Player->Size.x / 2;
        GLfloat distance = (Ball->Position.x + Ball->Radius) - centerBoard;
        GLfloat percentage = distance / (Player->Size.x / 2);
        // Then move accordingly
        GLfloat strength = 2.0f;
        Vec2 oldVelocity = { Ball->Velocity.x, Ball->Velocity.y };
        Ball->Velocity.x = INITIAL_BALL_VELOCITY.x * percentage * strength;
        //Ball->Velocity.y = -Ball->Velocity.y;
        Ball->Velocity = glm_normalize(Ball->Velocity) * glm_length(oldVelocity); // Keep speed consistent over both axes (multiply by length of old velocity, so total strength is not changed)
        // Fix sticky paddle
        Ball->Velocity.y = -1 * abs(Ball->Velocity.y);
    }
    // DSFree(result);
}

/**
 * ToString
 */
method char* ToString(Game* this)
{
    return "Game";
}
