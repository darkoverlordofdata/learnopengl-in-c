#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>
#include "object.h"
#include "dna.h"
#include "shader-private.h"

corefw(DNAShader);
static bool ctor(void *self, va_list args) { return true; }
static bool equal(void *ptr1, void *ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void *self) { return self; }
static void* copy(void *self) { return NULL; }

static void dtor(void *self)
{
	DNAShader *this = self;
}

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

void* DNAShader_New(const GLchar* vShaderSrc, const GLchar* fShaderSrc)
{
    DNAShader* this =  cfw_new(DNAShaderClass);

    DNAShader_Compile(this, vShaderSrc, fShaderSrc);
    return this;
}

/**
 * Use shader
 */
DNAShader* DNAShader_Use(const DNAShader* this)
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
    const DNAShader* this, 
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
void DNAShader_Compile(
    DNAShader* this, 
    const GLchar* vShaderSrc, 
    const GLchar* fShaderSrc)
{
    // printf("=============================\n");
    // CFWString* vShaderPath = DNAFileSystem.getPath("data/shaders/");
    // cfw_string_append_c(vShaderPath, vShaderFile);
    // printf("v shader %s\n", cfw_string_c(vShaderPath));
    // FILE* vertexShaderFile = fopen(cfw_string_c(vShaderPath), "r");

    // CFWString* fShaderPath = DNAFileSystem.getPath("data/shaders/");
    // cfw_string_append_c(fShaderPath, fShaderFile);
    // printf("f shader %s\n", cfw_string_c(fShaderPath));
    // FILE* fragmentShaderFile = fopen(cfw_string_c(fShaderPath), "r");
    // printf("=============================\n");

    // if (!vertexShaderFile) printf("Unable to open %s", vShaderFile);
    // if (!fragmentShaderFile) printf("Unable to open %s", fShaderFile);

    // // Read file's buffer contents into streams
    // const GLchar *vShaderSrc = ReadTextFile(vertexShaderFile);
    // const GLchar *fShaderSrc = ReadTextFile(fragmentShaderFile);
    // // close file handlers
    // fclose(vertexShaderFile);
    // fclose(fragmentShaderFile);


    GLuint sVertex, sFragment;
    // Vertex DNAShader
    sVertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVertex, 1, &vShaderSrc, NULL);
    glCompileShader(sVertex);
    CheckCompileErrors(this, sVertex, "VERTEX");
    // Fragment DNAShader
    sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFragment, 1, &fShaderSrc, NULL);
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

void DNAShader_SetFloat(
    const DNAShader* this, 
    const GLchar *name, 
    const GLfloat value, 
    const GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniform1f(glGetUniformLocation(this->Id, name), value);
}

void DNAShader_SetInteger(
    const DNAShader* this, 
    const GLchar *name, 
    GLint value, 
    GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniform1i(glGetUniformLocation(this->Id, name), value);
}

void DNAShader_SetVector2(
    const DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniform2f(glGetUniformLocation(this->Id, name), x, y);
}

void DNAShader_SetVector2v(
    const DNAShader* this, 
    const GLchar *name, 
    const Vec2* vector,
    GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniform2fv(glGetUniformLocation(this->Id, name), 1, (GLfloat*)vector);
}

void DNAShader_SetVector3(
    const DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniform3f(glGetUniformLocation(this->Id, name), x, y, z);
}

void DNAShader_SetVector3v(
    const DNAShader* this, 
    const GLchar *name, 
    const Vec3* vector,
    GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniform3fv(glGetUniformLocation(this->Id, name), 1, (GLfloat*)vector);
}

void DNAShader_SetVector4(
    const DNAShader* this, 
    const GLchar *name,
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLfloat w, 
    GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniform4f(glGetUniformLocation(this->Id, name), x, y, z, w);
}

void DNAShader_SetVector4v(
    const DNAShader* this, 
    const GLchar *name,
    const Vec4* vector,
    GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniform4fv(glGetUniformLocation(this->Id, name), 1, (GLfloat*)vector);
}

void DNAShader_SetMatrix(
    const DNAShader* this, 
    const GLchar *name, 
    const Mat* matrix, 
    GLboolean useShader)
{
    if (useShader)
        DNAShader_Use(this);
    glUniformMatrix4fv(glGetUniformLocation(this->Id, name), 1, GL_FALSE, (GLfloat*)matrix);
}

