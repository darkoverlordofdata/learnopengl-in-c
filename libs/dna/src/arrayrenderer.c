#include <stdio.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif
#include "arrayrenderer-private.h"
#include "dna.h"
#include "cfw.h"
#include <GLFW/glfw3.h>

corefw(DNAArrayRenderer);

static bool ctor(void* self, va_list args) { return true; }
static bool equal(void* ptr1, void* ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void* self) { return (uint32_t)self; }
static void* copy(void* self) { return NULL; }

void InitArrayRenderData(DNAArrayRenderer* this);
/**
 * ArrayRenderer
 * 
 * @param shader to use for rendering
 * 
 */
static void dtor(void* self)
{
    DNAArrayRenderer* this = self;
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
}

void* DNAArrayRenderer_New(DNAShader* shader)
{
    DNAArrayRenderer* this = cfw_new((CFWClass*)DNAArrayRendererClass);
    this->shader = shader;
    InitArrayRenderData(this);

    return this;
}

/**
 * Draw
 * 
 * @param texture the image to render
 * @param position to render at
 * @param size to render
 * @param rotate amount to rotate by
 * @param color to tint
 * 
 */
method void Draw(
    const DNAArrayRenderer* this,
    DNATexture2D* texture,
    DNARect* bounds,
    GLfloat rotate,
    Vec3 color)
{
    // Prepare transformations
    Use(this->shader);
    Mat model = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    Vec3 size = { bounds->w, bounds->h, 1 };
    Vec3 position = { bounds->x, bounds->y, 0 };

    model = glm_translate(model, (Vec3) { position.x, position.y, 0.0f }); // First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)
    model = glm_translate(model, (Vec3) { 0.5f * size.x, 0.5f * size.y, 0.0f }); // Move origin of rotation to center of quad
    model = glm_rotate(model, rotate, (Vec3) { 0.0f, 0.0f, 1.0f }); // Then rotate
    model = glm_translate(model, (Vec3) { -0.5f * size.x, -0.5f * size.y, 0.0f }); // Move origin back
    model = glm_scale(model, (Vec3) { size.x, size.y, 1.0f }); // Last scale

    SetMatrix(this->shader, "model", &model, true);

    // Render textured quad
    SetVector3v(this->shader, "spriteColor", &color, true);

    glActiveTexture(GL_TEXTURE0);
    // DNATexture2D_Bind(texture);
    Bind(texture);

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void InitArrayRenderData(DNAArrayRenderer* this)
{
    GLfloat vertices[] = {
        // Pos      // Tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
