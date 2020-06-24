#pragma once
// #include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <corefw/class.h>
#include "tglm.h"

typedef struct DNAShader DNAShader;
extern const CFWClass *dna_shader;

extern DNAShader* DNA_ShaderUse(DNAShader* this);

extern void* DNA_Shader();
extern GLuint DNA_ShaderGetId(DNAShader* this);
extern void DNA_ShaderCompile(DNAShader* this, const GLchar* vertexSource, const GLchar* fragmentSource);
extern void DNA_ShaderSetFloat(
    DNAShader* this, 
    const GLchar *name, 
    const GLfloat value, 
    const GLboolean useShader);

extern void DNA_ShaderSetInteger(
    DNAShader* this, 
    const GLchar *name, 
    GLint value, 
    GLboolean useShader);

extern void DNA_ShaderSetVector2(
    DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLboolean useShader);

extern void DNA_ShaderSetVector2v(
    DNAShader* this, 
    const GLchar *name, 
    const Vec2* vector,
    GLboolean useShader);

extern void DNA_ShaderSetVector3(
    DNAShader* this, 
    const GLchar *name, 
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLboolean useShader);

extern void DNA_ShaderSetVector3v(
    DNAShader* this, 
    const GLchar *name, 
    const Vec3* vector,
    GLboolean useShader);

extern void DNA_ShaderSetVector4(
    DNAShader* this, 
    const GLchar *name,
    GLfloat x, 
    GLfloat y, 
    GLfloat z, 
    GLfloat w, 
    GLboolean useShader);

extern void DNA_ShaderSetVector4v(
    DNAShader* this, 
    const GLchar *name,
    const Vec4* vector,
    GLboolean useShader);

extern void DNA_ShaderSetMatrix(
    DNAShader* this, 
    const GLchar *name, 
    const Mat* matrix, 
    GLboolean useShader);
