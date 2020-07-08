#pragma once
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif
#include "tglm.h"
#include <GLFW/glfw3.h>
#include <corefw/class.h>

typedef struct DNAShader DNAShader;
extern const CFWClass* DNAShaderClass;

extern DNAShader* DNAShader_Use(DNAShader* this);

extern void* DNAShader_New();
extern GLuint DNAShader_GetId(DNAShader* this);
extern void DNAShader_Compile(DNAShader* this, const GLchar* vertexSource, const GLchar* fragmentSource);
extern void DNAShader_SetFloat(
    DNAShader* this,
    const GLchar* name,
    const GLfloat value,
    const GLboolean useShader);

extern void DNAShader_SetInteger(
    DNAShader* this,
    const GLchar* name,
    GLint value,
    GLboolean useShader);

extern void DNAShader_SetVector2(
    DNAShader* this,
    const GLchar* name,
    GLfloat x,
    GLfloat y,
    GLboolean useShader);

extern void DNAShader_SetVector2v(
    DNAShader* this,
    const GLchar* name,
    const Vec2* vector,
    GLboolean useShader);

extern void DNAShader_SetVector3(
    DNAShader* this,
    const GLchar* name,
    GLfloat x,
    GLfloat y,
    GLfloat z,
    GLboolean useShader);

extern void DNAShader_SetVector3v(
    DNAShader* this,
    const GLchar* name,
    const Vec3* vector,
    GLboolean useShader);

extern void DNAShader_SetVector4(
    DNAShader* this,
    const GLchar* name,
    GLfloat x,
    GLfloat y,
    GLfloat z,
    GLfloat w,
    GLboolean useShader);

extern void DNAShader_SetVector4v(
    DNAShader* this,
    const GLchar* name,
    const Vec4* vector,
    GLboolean useShader);

extern method void DNAShader_SetMatrix(
    DNAShader* this,
    const GLchar* name,
    const Mat* matrix,
    GLboolean useShader);

extern method void DNAShader_SetMatrix(
    DNAShader* this,
    const GLchar* name,
    const Mat* matrix);
