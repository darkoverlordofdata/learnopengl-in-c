#include <game-private.h>
#include "shmupwarz.h"
#include "object.h"

struct Shmupwarz {
	CFWObject obj;
    DNAGame *game;
    DNATexture2D* bg;
    DNAElementRenderer* renderer;
    DNAShader* shader;
    DNAResourceManager* resource;
    // ArtemisEntity* mPlayer;
    // id mSystems;
    // ArtemisWorld* mWorld;
};

corefw(Shmupwarz);
/**
 * Create new game
 */
static bool ctor(void *self, va_list args) { return true; }
static bool equal(void *ptr1, void *ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void *self) { return (uint32_t)self; }
static void* copy(void *self) { return NULL; }

static void dtor(void *self)
{
	Shmupwarz *this = self;
    cfw_unref(this->game);
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
void* Shmupwarz_New(char* title, int width, int height)
{
    static struct DNAGameVtbl overrides = 
    {
        .Initialize     = (DNAGameFunc)Shmupwarz_Initialize, 
        .LoadContent    = (DNAGameFunc)Shmupwarz_LoadContent, 
        .Update         = (DNAGameFunc)Shmupwarz_Update, 
        .Draw           = (DNAGameFunc)Shmupwarz_Draw 
    };

    // Shmupwarz* this = cfw_new((CFWClass*)ShmupwarzClass);
    Shmupwarz* this = cfw_new((CFWClass*)ShmupwarzClass);
    this->game = DNAGame_New(title, width, height, this, &overrides);
    return this;
}

void Shmupwarz_Initialize(Shmupwarz* this)
{

}

void Shmupwarz_LoadContent(Shmupwarz* this)
{
    Mat projection = glm_ortho(0.0f, this->game->width, this->game->height, 0.0f, -1.0f, 1.0f);

    this->resource = DNAResourceManager_New();
#ifdef __EMSCRIPTEN__
    this->shader = DNAResourceManager_LoadShader(this->resource, "data/shaders/es/elementrender.vs", "data/shaders/es/elementrender.fs", "shader");
#else
    this->shader = DNAResourceManager_LoadShader(this->resource, "data/shaders/core/elementrender.vs", "data/shaders/core/elementrender.fs", "shader");
#endif
    DNAShader_Use(this->shader);
    DNAShader_SetInteger(this->shader, "image", 0, true);
    DNAShader_SetMatrix(this->shader, "projection", &projection, true);

    this->bg = DNAResourceManager_LoadTexture(this->resource, "data/images/background.png", GL_TRUE, "background");
    this->renderer = DNAElementRenderer_New(this->shader);
}

void Shmupwarz_Update(Shmupwarz* this)
{
}

void Shmupwarz_Draw(Shmupwarz* this)
{
    float bgd_r = 0.392156f;
    float bgd_g = 0.584313f;
    float bgd_b = 0.929411f;

    glClearColor(bgd_r, bgd_g, bgd_b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Vec3 color = { 0, 0, 0 };

    DNARect bounds = { this->game->width/2, this->game->height/2,
                                this->game->width, this->game->height };

    DNAElementRenderer_Draw(this->renderer, this->bg, bounds, 0.0f, color);


    glfwSwapBuffers(this->game->window);
    glfwPollEvents();

}

void Shmupwarz_Run(Shmupwarz* this)
{
	DNAGame_Run(this->game);
}
