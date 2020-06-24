#include <stdio.h>
#include <string.h>
#include <corefw/object.h>
#include <corefw/string.h>
#include <corefw/hash.h>
#include <corefw/class.h>
// #include "dna.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "arrayrenderer.h"

/**
 *  Uses glDrawArrays
 */
struct DNAArrayRenderer 
{
	CFWObject obj;
    DNAShader* shader; 
    GLuint VBO;
    GLuint VAO;
};

void InitArrayRenderData(DNAArrayRenderer* this);
/**
 * ArrayRenderer
 * 
 * @param shader to use for rendering
 * 
 */
static bool ctor(void *self, va_list args)
{
	DNAArrayRenderer *this = self;
	return true;
}

static void dtor(void *self)
{
	DNAArrayRenderer *this = self;
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
}

static bool equal(void *ptr1, void *ptr2)
{
	CFWObject *obj2 = ptr2;
	DNAArrayRenderer *str1, *str2;

	if (obj2->cls != dna_sprite_renderer)
		return false;

    return (ptr1 == ptr2);
}

static uint32_t hash(void *self)
{
	DNAArrayRenderer *this = self;
	size_t i;
	uint32_t hash;

	CFW_HASH_INIT(hash);
    CFW_HASH_ADD(hash, this);
	CFW_HASH_FINALIZE(hash);

	return hash;
}

static void* copy(void *self)
{
	return cfw_ref(self);
}

static CFWClass class = {
	.name = "DNAArrayRenderer",
	.size = sizeof(DNAArrayRenderer),
	.ctor = ctor,
	.dtor = dtor,
	.equal = equal,
	.hash = hash,
	.copy = copy
};
const CFWClass *dna_sprite_renderer = &class;

void* DNA_ArrayRenderer(DNAShader* shader)
{
    DNAArrayRenderer* this = cfw_new(dna_sprite_renderer);
    this->shader = shader;
    printf("%x %x \n", this, this->shader);
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
void DNA_ArrayRendererDraw(
    DNAArrayRenderer* this, 
    DNATexture2D* texture, 
    DNARect* bounds,
    GLfloat rotate, 
    Vec3 color)
{
    // printf("%s (%d,%d)\n", texture.Path, texture.Width, texture.Height);
    // Prepare transformations
    DNA_ShaderUse(this->shader);
    Mat model= {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    Vec3 size = { bounds->w, bounds->h, 1 };
    Vec3 position = { bounds->x, bounds->y, 0 };

    model = glm_translate(model, (Vec3){ position.x, position.y, 0.0f });  // First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)
    model = glm_translate(model, (Vec3){ 0.5f * size.x, 0.5f * size.y, 0.0f }); // Move origin of rotation to center of quad
    model = glm_rotate(model, rotate, (Vec3){ 0.0f, 0.0f, 1.0f }); // Then rotate
    model = glm_translate(model, (Vec3){ -0.5f * size.x, -0.5f * size.y, 0.0f }); // Move origin back
    model = glm_scale(model, (Vec3){ size.x, size.y, 1.0f }); // Last scale


    DNA_ShaderSetMatrix(this->shader, "model", &model, true);

    // Render textured quad
    DNA_ShaderSetVector3v(this->shader, "spriteColor", &color, true);

    glActiveTexture(GL_TEXTURE0);
    DNA_Texture2DBind(texture);

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
