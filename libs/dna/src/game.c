#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/time.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "object.h"
#include "dna.h"

/**
 *  MACRO Min
 *      cache results of calculation in pocket scope 
 */
#define Min(a, b)                                                       \
({                                                                      \
    auto _a = a;                                                        \
    auto _b = b;                                                        \
    (_a < _b) ? _a : _b;                                                \
})

/**
 *  MACRO Max
 *      cache results of calculation in pocket scope 
 */
#define Max(a, b)                                                       \
({                                                                      \
    auto _a = a;                                                        \
    auto _b = b;                                                        \
    (_a > _b) ? _a : _b;                                                \
})


#define TicksPerMillisecond  10000.0
#define MillisecondsPerTick 1.0 / (TicksPerMillisecond)
#define TicksPerSecond TicksPerMillisecond * 1000.0   // 10,000,000
#define SecondsPerTick  1.0 / (TicksPerSecond)         // 0.0001

void DNAGame_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

/**
 *  class DNAGame
 */
struct DNAGame {
	CFWObject obj;
    void* subclass;
    struct DNAGameVtbl const *override;
    GLFWwindow *window;
    // SDL_GLContext context;
    struct DNAResourceManager* resource;
    char* title;
    int len;
    bool *keys;
    double delta;
    double factor;
    uint64_t targetElapsedTime;
    uint64_t accumulatedElapsedTime;
    uint64_t maxElapsedTime;
    uint64_t totalGameTime;
    uint64_t elapsedGameTime;
    uint64_t currentTime;
    long previousTicks;
    int x;
    int y;
    int width;
    int height;
    uint32_t flags;
    int mouseX;
    int mouseY;
    bool mouseDown;
    int sdlVersion;
    int frameSkip;
    int gl_major_version;
    int gl_minor_version;
    bool isRunning;
    int ticks;
    int fps;
    bool isFixedTimeStep;
    bool isRunningSlowly;
    int updateFrameLag;
    bool shouldExit;
    bool suppressDraw;
};

static CFWClass class = {
	.name = "DNAGame",
	.size = sizeof(struct DNAGame),
	.ctor = ctor,
	.dtor = dtor,
	.equal = equal,
	.hash = hash,
	.copy = copy
};
const CFWClass *DNAGame = &class;


static bool ctor(void *self, va_list args)
{
	// struct DNAGame *this = self;
	return true;
}

static void dtor(void *self)
{
	struct DNAGame *this = self;

    free(this->title);
    free(this->keys);
    cfw_unref(this->resource);
    glfwTerminate();
}

static bool equal(void *ptr1, void *ptr2)
{
	CFWObject *obj2 = ptr2;
	struct DNAGame *str1, *str2;

	if (obj2->cls != DNAGame)
		return false;

	str1 = ptr1;
	str2 = ptr2;

	if (str1->len != str2->len)
		return false;

	return !memcmp(str1->title, str2->title, str1->len);
}

static uint32_t hash(void *self)
{
	struct DNAGame *this = self;
	size_t i;
	uint32_t hash;

	CFW_HASH_INIT(hash);

	for (i = 0; i < this->len; i++)
		CFW_HASH_ADD(hash, this->title[i]);

	CFW_HASH_FINALIZE(hash);

	return hash;
}

static void* copy(void *self)
{
	return cfw_ref(self);
}

static uint64_t GetTicks() { 
    struct timeval t;     
    gettimeofday(&t, NULL);

    uint64_t ts = t.tv_sec;
    uint64_t us = t.tv_usec;
    return ((ts * 1000000L) + us) * 10;
}


static void LogSDLError(const char* msg)
{
    printf("%s error: %s", msg, SDL_GetError());
}

void* DNAGame_New(char* cstr, int width, int height, void* subclass, struct DNAGameVtbl *vptr)
{
    struct DNAGame* this = cfw_new(DNAGame);

    this->subclass = subclass;
    this->override = vptr;
    srand(time(NULL));
    this->title = strdup(cstr);
    this->len = strlen(cstr);
    this->keys = calloc(1024, 1);
    this->width = width;
    this->height = height;
    this->frameSkip = 0;
    this->isRunning = false;
    this->previousTicks = 0;
    this->isFixedTimeStep = true;
    this->shouldExit = false;
    this->suppressDraw = false;
    this->maxElapsedTime = 500 * TicksPerMillisecond; 
    this->targetElapsedTime = 166667;
    this->accumulatedElapsedTime = 0;
    this->currentTime = GetTicks();


    printf("Hello, world!\n");
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    this->window = glfwCreateWindow(this->width, this->height, "LearnOpenGL", NULL, NULL);
    if (this->window == NULL)
    {
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, DNAGame_framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return -1;
    }


    glViewport(0, 0, this->width, this->height);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return this;

}


/**
 * DNAGame::Start
 */
void DNAGame_Start(struct DNAGame* const this) 
{
    this->isRunning = true;
}


/**
 * DNAGame::HandleEvents
 */
void DNAGame_HandleEvents(struct DNAGame* const this) 
{
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(this->window, true);
        this->shouldExit = true;
        return;
    }

    // SDL_Event event;
    // // if (SDL_PollEvent(&event)) 
    // while (SDL_PollEvent(&event) != 0) 
    // {
    //     switch (event.type) 
    //     {
    //         case SDL_QUIT:
    //             this->isRunning = false;
    //             return;
    //             break;
    //         case SDL_KEYDOWN: 
    //             this->keys[ event.key.keysym.sym & 0xff ] = true;
    //             break;
    //         case SDL_KEYUP:   
    //             this->keys[ event.key.keysym.sym & 0xff ] = false;
    //             break;
    //         case SDL_MOUSEBUTTONDOWN:
    //             this->mouseDown = true;
    //             break;
    //         case SDL_MOUSEBUTTONUP:
    //             this->mouseDown = false;
    //             break;
    //         case SDL_MOUSEMOTION:
    //             this->mouseX = event.motion.x;
    //             this->mouseY = event.motion.y;
    //             break;
    //     }
    // }
}


/**
 * DNAGame::Tick
 */
void DNAGame_Tick(struct DNAGame* const this) 
{
    while (true) {
        // Advance the accumulated elapsed time.
        long currentTicks = (GetTicks() - this->currentTime);//*10;
        this->accumulatedElapsedTime = this->accumulatedElapsedTime + currentTicks - this->previousTicks;
        this->previousTicks = (long)currentTicks;

        // If we're in the fixed timestep mode and not enough time has elapsed
        // to perform an update we sleep off the the remaining time to save battery
        // life and/or release CPU time to other threads and processes.
        if (this->isFixedTimeStep && this->accumulatedElapsedTime < this->targetElapsedTime)
        {
            int sleepTime = (int)((this->targetElapsedTime - this->accumulatedElapsedTime) * MillisecondsPerTick ); //).TotalMilliseconds();
            if (sleepTime < 1) { break; }
            // NOTE: While sleep can be inaccurate in general it is 
            // accurate enough for frame limiting purposes if some
            // fluctuation is an acceptable result.
            
            // #ifndef usleep
            // SDL_Delay(sleepTime);
            // #else
            usleep(sleepTime*1000);
            // #endif
            // goto RetryTick;
        }
        else break;
    }    
    // Do not allow any update to take longer than our maximum.
    if (this->accumulatedElapsedTime > this->maxElapsedTime)
        this->accumulatedElapsedTime = this->maxElapsedTime;

    if (this->isFixedTimeStep)
    {
        this->elapsedGameTime = this->targetElapsedTime;
        int stepCount = 0;

        // Perform as many full fixed length time steps as we can.
        while (this->accumulatedElapsedTime >= this->targetElapsedTime && !this->shouldExit)
        {
            this->totalGameTime += this->targetElapsedTime;
            this->accumulatedElapsedTime -= this->targetElapsedTime;
            ++stepCount;
            this->delta = (double)this->elapsedGameTime * SecondsPerTick;
            DNAGame_Update(this);
            // this->override->Update(self);
        }
        //Every update after the first accumulates lag
        this->updateFrameLag += Max(0, stepCount - 1);
        //If we think we are isRunning slowly, wait until the lag clears before resetting it
        if (this->isRunningSlowly)
        {
            if (this->updateFrameLag == 0)
            
                this->isRunningSlowly = false;
        }
        else if (this->updateFrameLag >= 5)
        {
            //If we lag more than 5 frames, start thinking we are isRunning slowly
            this->isRunningSlowly = true;
        }
        //Every time we just do one update and one draw, then we are not isRunning slowly, so decrease the lag
        if (stepCount == 1 && this->updateFrameLag > 0)
            this->updateFrameLag--;

        // Draw needs to know the total elapsed time
        // that occured for the fixed length updates.
        this->elapsedGameTime = this->targetElapsedTime * stepCount;
    }
    else
    {
        // Perform a single variable length update.
        this->elapsedGameTime = this->accumulatedElapsedTime;
        this->totalGameTime += this->accumulatedElapsedTime;
        this->accumulatedElapsedTime = 0;
        
        this->delta = (double)this->elapsedGameTime * SecondsPerTick;
        DNAGame_Update(this);
        // this->override->Update(self);
    }
    // Draw unless the update suppressed it.
    if (this->suppressDraw)
        this->suppressDraw = false;
    else
    {
        DNAGame_Draw(this);
        // this->override->Draw(self);
    }

    if (this->shouldExit) 
        this->isRunning = false;
        // Platform.Exit();
}


/**
 * DNAGame::RunLoop
 */
void DNAGame_RunLoop(struct DNAGame* const this)
{
    DNAGame_HandleEvents(this);
    // if (this->keys[SDLK_ESCAPE]) {
    //     this->shouldExit = true;
    // }
    DNAGame_Tick(this);
}

/**
 * DNAGame::Run
 */
void DNAGame_Run(struct DNAGame* const this) 
{
    DNAGame_Initialize(this);
    DNAGame_LoadContent(this);
    DNAGame_Start(this);
    while (this->isRunning) {
        DNAGame_RunLoop(this);
    }
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///// override methods
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

/**
 * DNAGame::Draw
 */
void DNAGame_Draw(struct DNAGame* const this) 
{
    this->override->Draw(this->subclass);
}

/**
 * DNAGame::LoadContent
 */
void DNAGame_LoadContent(struct DNAGame* const this)
{ 
    this->override->LoadContent(this->subclass);
}

/**
 * DNAGame::Initialize
 */
void DNAGame_Initialize(struct DNAGame* const this)
{ 
    this->override->Initialize(this->subclass);
}

/**
 * DNAGame::Update
 */
void DNAGame_Update(struct DNAGame* const this)
{ 
    this->override->Update(this->subclass);
}


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///// properties
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void DNAGame_SetResourceManager(struct DNAGame* const this, struct DNAResourceManager* rm)
{
    this->resource = rm;
    assert(this->resource != NULL);
}

void* DNAGame_GetWindow(struct DNAGame* const this)
{
    return this->window;
}

void* DNAGame_GetResource(struct DNAGame* const this)
{
    return this->resource;
}

int DNAGame_GetWidth(struct DNAGame* const this)
{
    return this->width;
}
int DNAGame_GetHeight(struct DNAGame* const this)
{
    return this->height;
}
