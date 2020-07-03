#include <stdio.h>
#include <string.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include "dna.h"
#include "object.h"

/**
 *  object DNATexture2D
 */
struct DNATexture2D {
	CFWObject obj;          // CoreFW interface
    GLuint Id;              // Holds the ID of the texture object, used for all texture operations to reference to self particlar texture
    GLuint Width, Height;   // Width and height of loaded image in pixels
    GLuint InternalFormat;  // Format of texture object
    GLuint ImageFormat;     // Format of loaded image
    GLuint wrapS;           // Wrapping mode on S axis
    GLuint wrapT;           // Wrapping mode on T axis
    GLuint filterMin;       // Filtering mode if texture pixels < screen pixels
    GLuint filterMag;       // Filtering mode if texture pixels > screen pixels
    char* path;
};

corefw(DNATexture2D);

/**
 *  DNATexture2D Constructor
 * 
 * @param internalFormat
 * @param imageFormat
 * @param path to image
 */
void* DNATexture2D_New(GLuint internalFormat, GLuint imageFormat, char* path)
{
    struct DNATexture2D* this = cfw_new(DNATexture2D);
    this->path = strdup(path);
    this->Width = 0;
    this->Height = 0;
    this->wrapS = GL_REPEAT;
    this->wrapT = GL_REPEAT;
    this->filterMin = GL_LINEAR;
    this->filterMag = GL_LINEAR;
    this->InternalFormat = internalFormat;
    this->ImageFormat = imageFormat;
    glGenTextures(1, &this->Id);
    return this;
}
/**
 * Generate
 * 
 * @param width of image to generate
 * @param height of image to generate
 * @param data bitmap data
 * 
 */
void DNATexture2D_Generate(
    struct DNATexture2D* this, 
    GLuint width, 
    GLuint height, 
    unsigned char* data)
{
    this->Width = width;
    this->Height = height;
    // Create Texture
    glBindTexture(GL_TEXTURE_2D, this->Id);
    glTexImage2D(GL_TEXTURE_2D, 0, this->InternalFormat, width, height, 0, this->ImageFormat, GL_UNSIGNED_BYTE, data);
                                              // Set Texture wrap and filter modes
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filterMag);
    // Unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

/**
 * Bind
 * 
 * binds the texture to GL
 */
void DNATexture2D_Bind(struct DNATexture2D* this)
{
    glBindTexture(GL_TEXTURE_2D, this->Id);    
}

char* DNATexture2D_ToString(struct DNATexture2D* this)
{
    char* s = calloc(1024, 1);
    sprintf(s, "%s: (%d,%d)", this->path, this->Width, this->Height);
    return s;    

}

/**
 * CFWObject interface 
 */
static bool ctor(void *self, va_list args)
{
	return true;
}

static void dtor(void *self)
{
	struct DNATexture2D *this = self;
}

static bool equal(void *ptr1, void *ptr2)
{
    return ptr1 == ptr2;
}

static uint32_t hash(void *self)
{
    return self;
}

static void* copy(void *self)
{
    return NULL;
}



