#include "cfw.h"
#include "shmupwarz-private.h"
#include <game-private.h>

corefw(Shmupwarz);
/**
 * Create new game
 */
static bool ctor(void* self, va_list args) { return true; }
static bool equal(void* ptr1, void* ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void* self) { return (uint32_t)self; }
static void* copy(void* self) { return NULL; }

static void dtor(void* self)
{
    Shmupwarz* this = self;
    cfw_unref(this->bg);
    cfw_unref(this->renderer);
    cfw_unref(this->shader);
    cfw_unref(this->resource);
}


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///// methods
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
typedef void (*ShmupwarzProc)(Shmupwarz* this);
void* Shmupwarz_New(char* title, int width, int height)
{
    static struct DNAGameVtbl overrides = {
        .Initialize = (DNAGameProc)(ShmupwarzProc)Initialize,
        .LoadContent = (DNAGameProc)(ShmupwarzProc)LoadContent,
        .Update = (DNAGameProc)(ShmupwarzProc)Update,
        .Draw = (DNAGameProc)(ShmupwarzProc)Draw,
    };

    Shmupwarz* this = cfw_new((CFWClass*)ShmupwarzClass);
    DNAGame_ctor(&this->game, title, width, height, this, &overrides);
    return (void*)this;
}

method void Initialize(Shmupwarz* this)
{
}

method void LoadContent(Shmupwarz* this)
{
    Mat projection = glm_ortho(0.0f, this->game.width, this->game.height, 0.0f, -1.0f, 1.0f);

    this->resource = DNAResourceManager_New();
#ifdef __EMSCRIPTEN__
    this->shader = LoadShader(this->resource, "data/shaders/es/elementrender.vs", "data/shaders/es/elementrender.fs", "shader");
#else
    this->shader = LoadShader(this->resource, "data/shaders/core/elementrender.vs", "data/shaders/core/elementrender.fs", "shader");
#endif
    Use(this->shader);
    SetInteger(this->shader, "image", 0, true);
    SetMatrix(this->shader, "projection", &projection, true);

    this->bg = LoadTexture(this->resource, "data/images/background.png", GL_TRUE, "background");
    this->renderer = DNAElementRenderer_New(this->shader);
}

method void Update(Shmupwarz* this)
{
}

method void Draw(Shmupwarz* this)
{
    float bgd_r = 0.392156f;
    float bgd_g = 0.584313f;
    float bgd_b = 0.929411f;

    glClearColor(bgd_r, bgd_g, bgd_b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Vec3 color = { 0, 0, 0 };

    DNARect bounds = { this->game.width / 2, this->game.height / 2,
        this->game.width, this->game.height };

    Draw(this->renderer, this->bg, bounds, 0.0f, color);

    glfwSwapBuffers(this->game.window);
    glfwPollEvents();
}

method void Run(Shmupwarz* this)
{
    Run(&this->game);
}
