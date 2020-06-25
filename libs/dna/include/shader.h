#pragma once
// #include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <corefw/class.h>
#include "tglm.h"

struct DNAShader;
extern const CFWClass *DNAShader;

extern struct DNAShader* DNAShaderUse(struct DNAShader* this);

extern void* DNAShader_New();
extern GLuint DNAShader_GetId(struct DNAShader* this);
extern void DNAShader_Compile(struct DNAShader* this, const GLchar* vertexSource, const GLchar* fragmentSource);
extern void DNAShader_SetFloat(
    struct DNAShader* this, 
    const GLchar *name, 
    const GLfloat value, 
    const GLboolean useShader);

extern void DNAShader_SetInteger(
    struct DNAShader* this, 
    const GLchar *name, 
    GLint value, 
    GLboolean useShader);

extern void DNAShader_SetVector2(
    struct DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLboolean useShader);

extern void DNAShader_SetVector2v(
    struct DNAShader* this, 
    const GLchar *name, 
    const Vec2* vector,
    GLboolean useShader);

extern void DNAShader_SetVector3(
    struct DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLboolean useShader);

extern void DNAShader_SetVector3v(
    struct DNAShader* this, 
    const GLchar *name, 
    const Vec3* vector,
    GLboolean useShader);

extern void DNAShader_SetVector4(
    struct DNAShader* this, 
    const GLchar *name,
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLfloat w, 
    GLboolean useShader);

extern void DNAShader_SetVector4v(
    struct DNAShader* this, 
    const GLchar *name,
    const Vec4* vector,
    GLboolean useShader);

extern void DNAShader_SetMatrix(
    struct DNAShader* this, 
    const GLchar *name, 
    const Mat* matrix, 
    GLboolean useShader);
