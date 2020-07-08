#pragma once
#include "corefw/class.h"
#include "shader.h"
#include "texture2d.h"

typedef struct DNAResourceManager DNAResourceManager;
extern const CFWClass* DNAResourceManagerClass;

extern void* DNAResourceManager_New();

extern DNAShader* DNAResourceManager_LoadShader(
    const DNAResourceManager* this,
    const GLchar* vShaderFile,
    const GLchar* fShaderFile,
    const char* name);

extern DNAShader* DNAResourceManager_GetShader(
    const DNAResourceManager* this,
    const char* name);

extern DNATexture2D* DNAResourceManager_LoadTexture(
    const DNAResourceManager* this,
    const GLchar* file,
    GLboolean alpha,
    const char* name);

extern DNATexture2D* DNAResourceManager_GetTexture(
    const DNAResourceManager* this,
    const char* name);
