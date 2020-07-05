#include <stdio.h>
#include <string.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "object.h"
#include "dna.h"
#include "elementrenderer-private.h"

corefw(DNAElementRenderer);
static bool ctor(void *self, va_list args) { return true; }
static bool equal(void *ptr1, void *ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void *self) { return self; }
static void* copy(void *self) { return NULL; }

void InitElementRenderData(DNAElementRenderer* this);
/**
 * ElementRenderer
 * 
 * @param shader to use for rendering
 * 
 */
static void dtor(void *self)
{
	DNAElementRenderer *this = self;
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
}

void* DNAElementRenderer_New(DNAShader* shader)
{
    DNAElementRenderer* this = cfw_new(DNAElementRendererClass);
    this->shader = shader;
    printf("%x %x \n", this, this->shader);
    InitElementRenderData(this);
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
void DNAElementRenderer_Draw(
    const DNAElementRenderer* this, 
    DNATexture2D* texture, 
    DNARect bounds,
    GLfloat rotate, 
    Vec3 color)
{
    // Prepare transformations

    Vec3 size = { bounds.w, bounds.h, 1 };
    Vec3 position = { bounds.x, bounds.y, 0 };
    Mat model= {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    model = glm_translate(model, (Vec3){ position.x, position.y, 0.0f });  // First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)
    model = glm_translate(model, (Vec3){ 0.5f * size.x, 0.5f * size.y, 0.0f }); // Move origin of rotation to center of quad
    model = glm_rotate(model, rotate, (Vec3){ 0.0f, 0.0f, 1.0f }); // Then rotate
    model = glm_translate(model, (Vec3){ -0.5f * size.x, -0.5f * size.y, 0.0f }); // Move origin back
    model = glm_scale(model, (Vec3){ size.x, size.y, 1.0f }); // Last scale

    DNAShader_Use(this->shader);
    DNAShader_SetMatrix(this->shader, "model", &model, true);
    DNAShader_SetVector3v(this->shader, "spriteColor", &color, true);
    glActiveTexture(GL_TEXTURE0);
    Bind(texture);
    // DNATexture2D_Bind(texture);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


void InitElementRenderData(DNAElementRenderer* this)
{
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // positions           // texture coords
         0.5f,  0.5f, 0.0f,    1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,    1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,    0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,    0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}          
