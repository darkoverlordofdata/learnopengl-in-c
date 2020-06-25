#include <stdio.h>
#include <string.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "object.h"
#include "dna.h"

/**
 *  class DNAResourceManager
 */
struct DNAResourceManager {
	CFWObject obj;
    CFWMap* Shaders;
    CFWMap* Textures;
};

static CFWClass class = {
	.name = "DNAResourceManager",
	.size = sizeof(struct DNAResourceManager),
	.ctor = ctor,
	.dtor = dtor,
	.equal = equal,
	.hash = hash,
	.copy = copy
};
const CFWClass *DNAResourceManager = &class;



void Init(struct DNAResourceManager* this);

struct DNAShader* LoadShaderFromFile(
    struct DNAResourceManager* this, 
    const GLchar *vShaderFile, 
    const GLchar *fShaderFile);
struct DNATexture2D* LoadTextureFromFile(
    struct DNAResourceManager* this, 
    const GLchar *file, 
    GLboolean alpha);

static bool ctor(void *self, va_list args)
{
	struct DNAResourceManager *this = self;
	return true;
}

static void dtor(void *self)
{
	struct DNAResourceManager *this = self;
	cfw_map_iter_t iter;

	cfw_map_iter(this->Shaders, &iter);
	while (iter.key != NULL) {
		if (cfw_is(iter.obj, DNAShader)) 
            cfw_unref(iter.obj);
		cfw_map_iter_next(&iter);
    }
    cfw_unref(this->Shaders);

	cfw_map_iter(this->Textures, &iter);
	while (iter.key != NULL) {
		if (cfw_is(iter.obj, DNATexture2D)) 
            cfw_unref(iter.obj);
		cfw_map_iter_next(&iter);
    }
    cfw_unref(this->Textures);
}

static bool equal(void *ptr1, void *ptr2)
{
	CFWObject *obj2 = ptr2;
	struct DNAResourceManager *str1, *str2;

	if (obj2->cls != DNATexture2D)
		return false;

    return (ptr1 == ptr2);
}

static uint32_t hash(void *self)
{
	struct DNAResourceManager *this = self;
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

void Init(struct DNAResourceManager* this)
{
    this->Shaders = cfw_new(cfw_map, NULL);
    this->Textures = cfw_new(cfw_map, NULL);
}
/**
 * ReadTextFile
 * 
 * @param path path to file
 * @returns string with file contents
 * 
 */
static char* ReadTextFile(FILE* f)
{
    fseek(f, 0L, SEEK_END);
    long s = ftell(f);
    rewind(f);
    char* buf = (char*)calloc(1, s+1);
    buf[s] = '\0';

    if (buf != NULL)
    {
        fread(buf, s, 1, f);
        return buf;
    }
    return buf;
}


void* DNAResourceManager_New()
{
    struct DNAResourceManager* this = cfw_new(DNAResourceManager);
    Init(this);
    return this;
}
/**
 * LoadShader
 * 
 * @param vShaderFile path to vertex shader
 * @param fShaderFile path to fragment shader
 * @param name to cache as
 * @returns loaded, compiled and linked shader program
 */
struct DNAShader* DNAResourceManager_LoadShader(
    struct DNAResourceManager* this, 
    const GLchar *vShaderFile, 
    const GLchar *fShaderFile, 
    const char* name)
{
    cfw_map_set_c(this->Shaders, name, LoadShaderFromFile(this, vShaderFile, fShaderFile));
    return cfw_map_get_c(this->Shaders, name);
}

/**
 * GetShader
 * 
 * @param name to retrieve
 * @returns loaded, compiled and linked shader program
 * 
 */
struct DNAShader* DNAResourceManager_GetShader(
    struct DNAResourceManager* this, 
    const char* name)
{
    return cfw_map_get_c(this->Shaders, name);    
}

/**
 * loadTexture
 * 
 * @param file path to texture
 * @param alpha does the texture have an alpha channel?
 * @param name to cache as
 * @returns Texture
 * 
 */
struct DNATexture2D*  DNAResourceManager_LoadTexture(
    struct DNAResourceManager* this, 
    const GLchar *file, 
    GLboolean alpha,
    const char* name)
{
    cfw_map_set_c(this->Textures, name, LoadTextureFromFile(this, file, alpha));
    return cfw_map_get_c(this->Textures, name);
}

/**
 * GetTexture
 * 
 * @param name to retrieve
 * @returns Texture
 * 
 */
struct DNATexture2D* DNAResourceManager_GetTexture(
    struct DNAResourceManager* this, 
    const char* name)
{
    return cfw_map_get_c(this->Textures, name);    
}

void Clear(struct DNAResourceManager* this)
{
    dtor(this);
    Init(this);
}

// static inline char* join(const char* s1, const char* s2) { return nullptr;}
/**
 * loadShaderFromFile
 * 
 * @param vShaderFile path to vertex shader
 * @param fShaderFile path to fragment shader
 * @returns loaded, compiled and linked shader program
 * 
 */
struct DNAShader* LoadShaderFromFile(
    struct DNAResourceManager* this, 
    const GLchar *vShaderFile, 
    const GLchar *fShaderFile)
{

    FILE* vertexShaderFile = fopen(vShaderFile, "r");
    FILE* fragmentShaderFile = fopen(fShaderFile, "r");

    if (!vertexShaderFile) printf("Unable to open %s", vShaderFile);
    if (!fragmentShaderFile) printf("Unable to open %s", fShaderFile);

    // Read file's buffer contents into streams
    const GLchar *vShaderCode = ReadTextFile(vertexShaderFile);
    const GLchar *fShaderCode = ReadTextFile(fragmentShaderFile);
    // close file handlers
    fclose(vertexShaderFile);
    fclose(fragmentShaderFile);

    // 2. Now create shader object from source code
    struct DNAShader* shader = DNAShader_New(vShaderCode, fShaderCode);
    // DNAShaderCompile(shader, vShaderCode, fShaderCode);
    return shader;

}

/**
 * loadTextureFromFile
 * 
 * @param file path to texture
 * @param alpha does the texture have an alpha channel?
 * @returns Texture
 * 
 */
struct DNATexture2D* LoadTextureFromFile(
    struct DNAResourceManager* this, 
    const GLchar *file,                                                                 
    GLboolean alpha)
{
    int format = alpha ? GL_RGBA : GL_RGB;
    int stbiFlag = alpha ? STBI_rgb_alpha : STBI_rgb;

    struct DNATexture2D* texture = DNATexture2D_New(format, format, file);

    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    int width, height, nrChannels;
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, stbiFlag);

    // SDL_Surface * surface = IMG_Load(file);
    // if (SDL_MUSTLOCK(surface)) 
    //     SDL_LockSurface(surface);
    // // Now generate texture
    DNATexture2D_Generate(texture, width, height, (unsigned char*)data);
    // if (SDL_MUSTLOCK(surface)) 
    //     SDL_UnlockSurface(surface);
    // // And finally free image data
    // SDL_FreeSurface(surface);
    stbi_image_free(data);

    return texture;

}
