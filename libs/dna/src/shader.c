#include "shader.h"
#include <stdio.h>
#include <string.h>
// #include <glad/glad.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <corefw/object.h>
#include <corefw/string.h>
#include <corefw/hash.h>
#include <corefw/class.h>
#include "tglm.h"
#include "filesystem.h"


struct DNAShader {
	CFWObject obj;
    GLuint Id; 
};

static bool ctor(void *self, va_list args)
{
	DNAShader *this = self;
	return true;
}

static void dtor(void *self)
{
	DNAShader *this = self;
}

static bool equal(void *ptr1, void *ptr2)
{
	CFWObject *obj2 = ptr2;
	DNAShader *str1, *str2;

	if (obj2->cls != dna_shader)
		return false;

    return (ptr1 == ptr2);
}

static uint32_t hash(void *self)
{
	DNAShader *this = self;
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
	.name = "DNAShader",
	.size = sizeof(DNAShader),
	.ctor = ctor,
	.dtor = dtor,
	.equal = equal,
	.hash = hash,
	.copy = copy
};
const CFWClass *dna_shader = &class;

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

void* DNA_Shader(const GLchar* vShaderFile, const GLchar* fShaderFile)
{
    DNAShader* this =  cfw_new(dna_shader);

    DNA_ShaderCompile(this, vShaderFile, fShaderFile);
    return this;
}

/**
 * Use shader
 */
DNAShader* DNA_ShaderUse(DNAShader* this)
{
    glUseProgram(this->Id);
    return this;
}

/**
 * CheckCompileErrors
 * 
 * Checks if compilation or linking failed and if so, print the error logs
 */
void CheckCompileErrors(
    DNAShader* this, 
    GLuint object, 
    char* type)
{
    GLint success;
    GLchar infoLog[1024];
    if (strncmp(type, "PROGRAM", 7) != 0)
    {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(object, 1024, NULL, infoLog);
            printf("| ERROR::SHADER: Compile-time error: type: %s\n%s\n", type, infoLog);
            printf(" -- --------------------------------------------------- --\n");
        }
    }
    else
    {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, NULL, infoLog);
            printf("| ERROR::SHADER: Link-time error: type: %s\n%s\n", type, infoLog);
            printf(" -- --------------------------------------------------- --\n");
        }
    }
}        

/**
 * Compile
 * 
 * @param vertexSource vertex shader source code
 * @param fragmentSource fragment shader source code
 * 
 */
void DNA_ShaderCompile(
    DNAShader* this, 
    const GLchar* vShaderFile, 
    const GLchar* fShaderFile)
{
    CFWString* vShaderPath = DNA_FileSystem.getPath("data/shaders/");
    cfw_string_append_c(vShaderPath, vShaderFile);
    FILE* vertexShaderFile = fopen(cfw_string_c(vShaderPath), "r");

    CFWString* fShaderPath = DNA_FileSystem.getPath("data/shaders/");
    cfw_string_append_c(fShaderPath, fShaderFile);
    FILE* fragmentShaderFile = fopen(cfw_string_c(fShaderPath), "r");

    if (!vertexShaderFile) printf("Unable to open %s", vShaderFile);
    if (!fragmentShaderFile) printf("Unable to open %s", fShaderFile);

    // Read file's buffer contents into streams
    const GLchar *vShaderCode = ReadTextFile(vertexShaderFile);
    const GLchar *fShaderCode = ReadTextFile(fragmentShaderFile);
    // close file handlers
    fclose(vertexShaderFile);
    fclose(fragmentShaderFile);


    GLuint sVertex, sFragment;
    // Vertex DNAShader
    sVertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVertex, 1, &vShaderCode, NULL);
    glCompileShader(sVertex);
    CheckCompileErrors(this, sVertex, "VERTEX");
    // Fragment DNAShader
    sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFragment, 1, &fShaderCode, NULL);
    glCompileShader(sFragment);
    CheckCompileErrors(this, sFragment, "FRAGMENT");

    this->Id = glCreateProgram();
    glAttachShader(this->Id, sVertex);
    glAttachShader(this->Id, sFragment);
    glLinkProgram(this->Id);
    CheckCompileErrors(this, this->Id, "PROGRAM");
    // Delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(sVertex);
    glDeleteShader(sFragment);

} 

void DNA_ShaderSetFloat(
    DNAShader* this, 
    const GLchar *name, 
    const GLfloat value, 
    const GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniform1f(glGetUniformLocation(this->Id, name), value);
}

void DNA_ShaderSetInteger(
    DNAShader* this, 
    const GLchar *name, 
    GLint value, 
    GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniform1i(glGetUniformLocation(this->Id, name), value);
}

void DNA_ShaderSetVector2(
    DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniform2f(glGetUniformLocation(this->Id, name), x, y);
}

void DNA_ShaderSetVector2v(
    DNAShader* this, 
    const GLchar *name, 
    const Vec2* vector,
    GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniform2fv(glGetUniformLocation(this->Id, name), 1, (GLfloat*)vector);
}

void DNA_ShaderSetVector3(
    DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniform3f(glGetUniformLocation(this->Id, name), x, y, z);
}

void DNA_ShaderSetVector3v(
    DNAShader* this, 
    const GLchar *name, 
    const Vec3* vector,
    GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniform3fv(glGetUniformLocation(this->Id, name), 1, (GLfloat*)vector);
}

void DNA_ShaderSetVector4(
    DNAShader* this, 
    const GLchar *name,
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLfloat w, 
    GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniform4f(glGetUniformLocation(this->Id, name), x, y, z, w);
}

void DNA_ShaderSetVector4v(
    DNAShader* this, 
    const GLchar *name,
    const Vec4* vector,
    GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniform4fv(glGetUniformLocation(this->Id, name), 1, (GLfloat*)vector);
}

void DNA_ShaderSetMatrix(
    DNAShader* this, 
    const GLchar *name, 
    const Mat* matrix, 
    GLboolean useShader)
{
    if (useShader)
        DNA_ShaderUse(this);
    glUniformMatrix4fv(glGetUniformLocation(this->Id, name), 1, GL_FALSE, (GLfloat*)matrix);
}

GLuint DNA_ShaderGetId(DNAShader* this)
{
    return this->Id;
}
