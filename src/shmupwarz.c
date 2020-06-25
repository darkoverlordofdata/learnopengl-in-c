#include "shmupwarz.h"
#include "object.h"

struct Shmupwarz {
	CFWObject obj;
    CFWObject *game;
    struct DNATexture2D* bg;
    struct DNAElementRenderer* renderer;
    struct DNAShader* shader;
    struct DNAResourceManager* resource;
    // Entity* mPlayer;
    // id mSystems;l
    // ArtemisWorld* mWorld;
};

static CFWClass class = {
	.name = "Shmupwarz",
	.size = sizeof(struct Shmupwarz),
	.ctor = ctor,
	.dtor = dtor,
	.equal = equal,
	.hash = hash,
	.copy = copy
};
const CFWClass *Shmupwarz = &class;


/**
 * Create new game
 */
static bool ctor(void *self, va_list args)
{
    static struct DNAGameVtbl vptr = 
    {
        .Initialize     = Shmupwarz_Initialize, 
        .LoadContent    = Shmupwarz_LoadContent, 
        .Update         = Shmupwarz_Update, 
        .Draw           = Shmupwarz_Draw 
    };
    struct Shmupwarz *this = self;
    this->game = DNAGame_New("Shmupwarz", 700, 640, this, &vptr);

	return true; 
}

static void dtor(void *self)
{
	struct Shmupwarz *this = self;
    cfw_unref(this->game);
    cfw_unref(this->bg);
    cfw_unref(this->renderer);
    cfw_unref(this->shader);
    cfw_unref(this->resource);
}

static bool equal(void *ptr1, void *ptr2)
{
	struct Shmupwarz *this = ptr1;
    return this->game->cls->equal(this->game, ptr2);
}

static uint32_t hash(void *self)
{
	struct Shmupwarz *this = self;
    return this->game->cls->hash(this->game);
}

static void* copy(void *self)
{
	struct Shmupwarz *this = self;
    return this->game->cls->copy(this->game);
}

// static CFWClass class = {
// 	.name = "Shmupwarz",
// 	.size = sizeof(struct Shmupwarz),
// 	.ctor = ctor,
// 	.dtor = dtor,
// 	.equal = equal,
// 	.hash = hash,
// 	.copy = copy
// };
// const CFWClass *Shmupwarz = &class;

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///// methods
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void* Shmupwarz_New(char* title, int width, int height)
{
    static struct DNAGameVtbl vptr = 
    {
        .Initialize     = Shmupwarz_Initialize, 
        .LoadContent    = Shmupwarz_LoadContent, 
        .Update         = Shmupwarz_Update, 
        .Draw           = Shmupwarz_Draw 
    };
    struct Shmupwarz* this = cfw_new(Shmupwarz);
    this->game = DNAGame_New(title, width, height, this, &vptr);
    return this;
}

void Shmupwarz_Initialize(struct Shmupwarz* this)
{

}

void Shmupwarz_LoadContent(struct Shmupwarz* this)
{
    // Mat projection = glm_ortho(0.0f, 700.0f, 640.0f, 0.0f, -1.0f, 1.0f);
    Mat projection = glm_ortho(0.0f, DNAGame_GetWidth(this->game), DNAGame_GetHeight(this->game), 0.0f, -1.0f, 1.0f);

    this->resource = DNAResourceManager_New();
    DNAGame_SetResourceManager(this->game, this->resource);

    this->shader = DNAResourceManager_LoadShader(this->resource, "data/shaders/elementrender.vs", "data/shaders/elementrender.fs", "shader");
    DNAShader_Use(this->shader);
    DNAShader_SetInteger(this->shader, "image", 0, true);
    DNAShader_SetMatrix(this->shader, "projection", &projection, true);

    this->bg = DNAResourceManager_LoadTexture(this->resource, "data/images/background.png", GL_TRUE, "background");
    this->renderer = DNAElementRenderer_New(this->shader);
}

void Shmupwarz_Update(struct Shmupwarz* this)
{
}

void Shmupwarz_Draw(struct Shmupwarz* this)
{
    float bgd_r = 0.392156f;
    float bgd_g = 0.584313f;
    float bgd_b = 0.929411f;

    glClearColor(bgd_r, bgd_g, bgd_b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Vec3 color = { 0, 0, 0 };
    // DNARect bounds = { 0, 0, 700, 640}; 
    struct DNARect bounds = { DNAGame_GetWidth(this->game)/2, DNAGame_GetHeight(this->game)/2, 
                        DNAGame_GetWidth(this->game), DNAGame_GetHeight(this->game)}; 
    DNAElementRenderer_Draw(this->renderer, this->bg, bounds, 0.0f, color);


    glfwSwapBuffers(DNAGame_GetWindow(this->game));
    glfwPollEvents();

}

void Shmupwarz_Run(struct Shmupwarz* this)
{
	DNAGame_Run(this->game);
}
