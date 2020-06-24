#include <stdio.h>
#include <string.h>
// #include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <corefw/object.h>
#include <corefw/string.h>
#include <corefw/hash.h>
#include <corefw/class.h>
// #include "dna.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include "texture2d.h"

struct DNATexture2D {
	CFWObject obj;
    // Holds the ID of the texture object, used for all texture operations to reference to self particlar texture
    GLuint Id;
    // Texture image dimensions
    GLuint Width, Height; // Width and height of loaded image in pixels
    // Texture Format
    GLuint InternalFormat; // Format of texture object
    GLuint ImageFormat; // Format of loaded image
    // Texture configuration
    GLuint wrapS; // Wrapping mode on S axis
    GLuint wrapT; // Wrapping mode on T axis
    GLuint filterMin; // Filtering mode if texture pixels < screen pixels
    GLuint filterMag; // Filtering mode if texture pixels > screen pixels
    char* path;
};

/**
 * Texture2D
 * 
 * @param InternalFormat for binding the image
 * @param ImageFormat for binding the image
 * 
 */
static bool ctor(void *self, va_list args)
{
	return true;
}

static void dtor(void *self)
{
	DNATexture2D *this = self;
}

static bool equal(void *ptr1, void *ptr2)
{
	CFWObject *obj2 = ptr2;
	DNATexture2D *str1, *str2;

	if (obj2->cls != dna_texture2d)
		return false;

    return (ptr1 == ptr2);
}

static uint32_t hash(void *self)
{
	DNATexture2D *this = self;
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
	.name = "DNATexture2D",
	.size = sizeof(DNATexture2D),
	.ctor = ctor,
	.dtor = dtor,
	.equal = equal,
	.hash = hash,
	.copy = copy
};
const CFWClass *dna_texture2d = &class;

/**
 *  DNA_Texture2D Constructor
 * 
 * @param internalFormat
 * @param imageFormat
 * @param path to image
 */
void* DNA_Texture2D(GLuint internalFormat, GLuint imageFormat, char* path)
{
    DNATexture2D* this = cfw_new(dna_texture2d);
    this->path = strdup(path);
    this->Width = 0;
    this->Height = 0;
    // this->InternalFormat = GL_RGB;
    // this->ImageFormat = GL_RGB;
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
void DNA_Texture2DGenerate(
    DNATexture2D* this, 
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
void DNA_Texture2DBind(DNATexture2D* this)
{
    glBindTexture(GL_TEXTURE_2D, this->Id);    
}

char* DNA_Texture2DToString(DNATexture2D* this)
{
    char* s = calloc(1024, 1);
    sprintf(s, "%s: (%d,%d)", this->path, this->Width, this->Height);
    return s;    

}