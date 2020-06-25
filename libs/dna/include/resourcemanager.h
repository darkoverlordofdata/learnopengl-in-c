#pragma once
#include "corefw/class.h"
#include "shader.h"
#include "texture2d.h"

struct DNAResourceManager;
extern const CFWClass *DNAResourceManager;
 
extern void* DNAResourceManager_New();

extern struct DNAShader* DNAResourceManager_LoadShader(
    struct DNAResourceManager* this, 
    const GLchar *vShaderFile, 
    const GLchar *fShaderFile, 
    const char* name);

extern struct DNAShader* DNAResourceManager_GetShader(
    struct DNAResourceManager* this, 
    const char* name);

extern struct DNATexture2D*  DNAResourceManager_LoadTexture(
    struct DNAResourceManager* this, 
    const GLchar *file, 
    GLboolean alpha,
    const char* name);

extern struct DNATexture2D* DNAResourceManager_GetTexture(
    struct DNAResourceManager* this, 
    const char* name);
