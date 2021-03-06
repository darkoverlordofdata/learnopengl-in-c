#include <game-private.h>
#include "triangle.h"
#include "cfw"
// #include "linmath.h"

struct Triangle {
	CFWObject obj;
    DNAGame *game;
    DNATexture2D* bg;
    DNAElementRenderer* renderer;
    DNAShader* shader;
    DNAResourceManager* resource;
    // ArtemisEntity* mPlayer;
    // id mSystems;
    // ArtemisWorld* mWorld;
    GLuint program;
    GLint mvp_location;
    GLuint vertex_array;
    
};

corefw(Triangle);
/**
 * Create new game
 */
static bool ctor(void *self, va_list args) { return true; }
static bool equal(void *ptr1, void *ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void *self) { return (uint32_t)self; }
static void* copy(void *self) { return NULL; }

static void dtor(void *self)
{
	Triangle *this = self;
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
void* Triangle_New(char* title, int width, int height)
{
    static struct DNAGameVtbl overrides = 
    {
        .Initialize     = Triangle_Initialize, 
        .LoadContent    = Triangle_LoadContent, 
        .Update         = Triangle_Update, 
        .Draw           = Triangle_Draw 
    };

    Triangle* this = cfw_new(TriangleClass);
    this->game = DNAGame_New(title, width, height, this, &overrides);
    return this;
}

///////////////////////////////////////////////////////
typedef struct Vertex
{
    Vec2 pos;
    Vec3 col;
} Vertex;

static const Vertex vertices[3] =
{
    { { -0.6f, -0.4f }, { 1.f, 0.f, 0.f } },
    { {  0.6f, -0.4f }, { 0.f, 1.f, 0.f } },
    { {   0.f,  0.6f }, { 0.f, 0.f, 1.f } }
};

#ifdef __EMSCRIPTEN__
static const char *vertex_shader_text =
    "#version 100\n"
    "uniform mat4 MVP;\n"
    "attribute vec3 vCol;\n"
    "attribute vec2 vPos;\n"
    "varying vec3 color;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
    "    color = vCol;\n"
    "}\n";

#else
static const char* vertex_shader_text =
"#version 330\n"
"uniform mat4 MVP;\n"
"in vec3 vCol;\n"
"in vec2 vPos;\n"
"out vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";
#endif

#ifdef __EMSCRIPTEN__
static const char *fragment_shader_text =
    "#version 100\n"
    "precision mediump float;\n"
    "varying vec3 color;\n"
    "void main()\n"
    "{\n"
    "    gl_FragColor = vec4(color, 1.0);\n"
    "}\n";

#else
static const char* fragment_shader_text =
"#version 330\n"
"in vec3 color;\n"
"out vec4 fragment;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";
#endif

///////////////////////////////////////////////

void Triangle_Initialize(Triangle* this)
{

}

void Triangle_LoadContent(Triangle* this)
{
    // NOTE: OpenGL error checks have been omitted for brevity

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    const GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    this->program = glCreateProgram();
    glAttachShader(this->program, vertex_shader);
    glAttachShader(this->program, fragment_shader);
    glLinkProgram(this->program);

    this->mvp_location = glGetUniformLocation(this->program, "MVP");
    const GLint vpos_location = glGetAttribLocation(this->program, "vPos");
    const GLint vcol_location = glGetAttribLocation(this->program, "vCol");

    glGenVertexArrays(1, &this->vertex_array);
    glBindVertexArray(this->vertex_array);
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*) offsetof(Vertex, pos));
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*) offsetof(Vertex, col));
}

void Triangle_Update(Triangle* this)
{
}

void Triangle_Draw(Triangle* this)
{
    float bgd_r = 0.392156f;
    float bgd_g = 0.584313f;
    float bgd_b = 0.929411f;

    glClearColor(bgd_r, bgd_g, bgd_b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    const float ratio = this->game->width / (float) this->game->height;


    Mat model= {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    float angle = glfwGetTime();
	float s = sinf(angle);
	float c = cosf(angle);

    model = glm_rotateZ(model, (float) glfwGetTime());
    Mat perspective = glm_ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    model = glm_mat_mul(model, perspective);

    glUseProgram(this->program);
    glUniformMatrix4fv(this->mvp_location, 1, GL_FALSE, (const GLfloat*) &model);
    glBindVertexArray(this->vertex_array);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(this->game->window);
    glfwPollEvents();

}

void Triangle_Run(Triangle* this)
{
	DNAGame_Run(this->game);
}
