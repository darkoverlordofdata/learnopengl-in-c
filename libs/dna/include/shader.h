#pragma once
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>
#include <corefw/class.h>
#include "tglm.h"

typedef struct DNAShader DNAShader;
extern const CFWClass *DNAShaderClass;

extern DNAShader* DNAShader_Use(const DNAShader* this);

extern void* DNAShader_New();
extern GLuint DNAShader_GetId(const DNAShader* this);
extern void DNAShader_Compile(DNAShader* this, const GLchar* vertexSource, const GLchar* fragmentSource);
extern void DNAShader_SetFloat(
    const DNAShader* this, 
    const GLchar *name, 
    const GLfloat value, 
    const GLboolean useShader);

extern void DNAShader_SetInteger(
    const DNAShader* this, 
    const GLchar *name, 
    GLint value, 
    GLboolean useShader);

extern void DNAShader_SetVector2(
    const DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLboolean useShader);

extern void DNAShader_SetVector2v(
    const DNAShader* this, 
    const GLchar *name, 
    const Vec2* vector,
    GLboolean useShader);

extern void DNAShader_SetVector3(
    const DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLboolean useShader);

extern void DNAShader_SetVector3v(
    const DNAShader* this, 
    const GLchar *name, 
    const Vec3* vector,
    GLboolean useShader);

extern void DNAShader_SetVector4(
    const DNAShader* this, 
    const GLchar *name,
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLfloat w, 
    GLboolean useShader);

extern void DNAShader_SetVector4v(
    const DNAShader* this, 
    const GLchar *name,
    const Vec4* vector,
    GLboolean useShader);

extern method void DNAShader_SetMatrix(
    const DNAShader* this, 
    const GLchar *name, 
    const Mat* matrix, 
    GLboolean useShader);

extern method void DNAShader_SetMatrix(
    const DNAShader* this, 
    const GLchar *name, 
    const Mat* matrix);
