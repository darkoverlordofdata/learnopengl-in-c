#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif
#include "dna.h"
#include "game-private.h"
#include "cfw.h"
#include <GLFW/glfw3.h>
#if __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

/**
 *  class DNAGame
 */
corefw(DNAGame);

static bool ctor(void* self, va_list args) { return true; }
static bool equal(void* ptr1, void* ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void* self) { return (uint32_t)self; }
static void* copy(void* self) { return NULL; }

#define TicksPerMillisecond 10000.0
#define MillisecondsPerTick 1.0 / (TicksPerMillisecond)
#define TicksPerSecond TicksPerMillisecond * 1000.0 // 10,000,000
#define SecondsPerTick 1.0 / (TicksPerSecond) // 0.0001

void DNAGame_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

static void dtor(void* self)
{
    DNAGame* this = self;

    free(this->title);
    free(this->keys);
    glfwTerminate();
}

static uint64_t GetTicks()
{
    struct timeval t;
    gettimeofday(&t, NULL);

    uint64_t ts = t.tv_sec;
    uint64_t us = t.tv_usec;
    return ((ts * 1000000L) + us) * 10;
}

method void* New(DNAGame* this, char* cstr, int width, int height, void* subclass, struct DNAGameVtbl* vptr)
{
    this->subclass = subclass;
    this->override = vptr;
    srand(time(NULL));
    this->title = cfw_strdup(cstr);
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

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
#ifdef __EMSCRIPTEN__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
#else
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    // glfw window creation
    // --------------------
    this->window = glfwCreateWindow(this->width, this->height, "LearnOpenGL", NULL, NULL);
    if (this->window == NULL) {
        printf("Failed to create GLFW window");
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, DNAGame_framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
#ifdef __EMSCRIPTEN__
#else
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD");
        exit(-1);
    }
#endif
    glfwSwapInterval(1);

    glViewport(0, 0, this->width, this->height);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    return this;
}

method char* ToString(DNAGame* this)
{
    return this->title;
}
/**
 * DNAGame::Start
 */
method void Start(DNAGame* const this)
{
    this->isRunning = true;
}

/**
 * DNAGame::HandleEvents
 */
method void HandleEvents(DNAGame* const this)
{
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
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
method void Tick(DNAGame* const this)
{
    while (true) {
        // Advance the accumulated elapsed time.
        long currentTicks = (GetTicks() - this->currentTime); //*10;
        this->accumulatedElapsedTime = this->accumulatedElapsedTime + currentTicks - this->previousTicks;
        this->previousTicks = (long)currentTicks;

        // If we're in the fixed timestep mode and not enough time has elapsed
        // to perform an update we sleep off the the remaining time to save battery
        // life and/or release CPU time to other threads and processes.
        if (this->isFixedTimeStep && this->accumulatedElapsedTime < this->targetElapsedTime) {
            int sleepTime = (int)((this->targetElapsedTime - this->accumulatedElapsedTime) * MillisecondsPerTick); //).TotalMilliseconds();
            if (sleepTime < 1) {
                break;
            }
            // NOTE: While sleep can be inaccurate in general it is
            // accurate enough for frame limiting purposes if some
            // fluctuation is an acceptable result.

            // #ifndef usleep
            // SDL_Delay(sleepTime);
            // #else
#ifdef __EMSCRIPTEN__
#else
            usleep(sleepTime * 1000);
#endif
            // #endif
            // goto RetryTick;
        } else
            break;
    }
    // Do not allow any update to take longer than our maximum.
    if (this->accumulatedElapsedTime > this->maxElapsedTime)
        this->accumulatedElapsedTime = this->maxElapsedTime;

    if (this->isFixedTimeStep) {
        this->elapsedGameTime = this->targetElapsedTime;
        int stepCount = 0;

        // Perform as many full fixed length time steps as we can.
        while (this->accumulatedElapsedTime >= this->targetElapsedTime && !this->shouldExit) {
            this->totalGameTime += this->targetElapsedTime;
            this->accumulatedElapsedTime -= this->targetElapsedTime;
            ++stepCount;
            this->delta = (double)this->elapsedGameTime * SecondsPerTick;
            Update(this);
            // this->override->Update(self);
        }
        //Every update after the first accumulates lag
        this->updateFrameLag += Max(0, stepCount - 1);
        //If we think we are isRunning slowly, wait until the lag clears before resetting it
        if (this->isRunningSlowly) {
            if (this->updateFrameLag == 0)

                this->isRunningSlowly = false;
        } else if (this->updateFrameLag >= 5) {
            //If we lag more than 5 frames, start thinking we are isRunning slowly
            this->isRunningSlowly = true;
        }
        //Every time we just do one update and one draw, then we are not isRunning slowly, so decrease the lag
        if (stepCount == 1 && this->updateFrameLag > 0)
            this->updateFrameLag--;

        // Draw needs to know the total elapsed time
        // that occured for the fixed length updates.
        this->elapsedGameTime = this->targetElapsedTime * stepCount;
    } else {
        // Perform a single variable length update.
        this->elapsedGameTime = this->accumulatedElapsedTime;
        this->totalGameTime += this->accumulatedElapsedTime;
        this->accumulatedElapsedTime = 0;

        this->delta = (double)this->elapsedGameTime * SecondsPerTick;
        Update(this);
        // this->override->Update(self);
    }
    // Draw unless the update suppressed it.
    if (this->suppressDraw)
        this->suppressDraw = false;
    else {
        Draw(this);
    }

    if (this->shouldExit)
        this->isRunning = false;
    // Platform.Exit();
}

/**
 * DNAGame::RunLoop
 */
method void RunLoop(DNAGame* const this)
{
    HandleEvents(this);
    // if (this->keys[SDLK_ESCAPE]) {
    //     this->shouldExit = true;
    // }
    Tick(this);
}

/**
 * DNAGame::Run
 */
method void Run(DNAGame* const this)
{
    Initialize(this);
    LoadContent(this);
    Start(this);
#if __EMSCRIPTEN__
    emscripten_set_main_loop_arg((em_arg_callback_func)RunLoop, (void*)this, -1, 1);
#else
    while (this->isRunning) {
        RunLoop(this);
    }
#endif
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
///// override methods
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

/**
 * DNAGame::Draw
 */
method void Draw(DNAGame* const this)
{
    this->override->Draw(this->subclass);
}

/**
 * DNAGame::LoadContent
 */
method void LoadContent(DNAGame* const this)
{
    this->override->LoadContent(this->subclass);
}

/**
 * DNAGame::Initialize
 */
method void Initialize(DNAGame* const this)
{
    this->override->Initialize(this->subclass);
}

/**
 * DNAGame::Update
 */
method void Update(DNAGame* const this)
{
    this->override->Update(this->subclass);
}
