#pragma once
#include "corefw/class.h"
#include "shader.h"
#include "texture2d.h"

typedef struct DNAResourceManager DNAResourceManager;
extern const CFWClass *dna_resource_manager;
 
extern void* DNA_ResourceManager();

extern DNAShader* DNA_ResourceManagerLoadShader(
    DNAResourceManager* this, 
    const GLchar *vShaderFile, 
    const GLchar *fShaderFile, 
    const char* name);

extern DNAShader* DNA_ResourceManagerGetShader(
    DNAResourceManager* this, 
    const char* name);

extern DNATexture2D*  DNA_ResourceManagerLoadTexture(
    DNAResourceManager* this, 
    const GLchar *file, 
    GLboolean alpha,
    const char* name);

extern DNATexture2D* DNA_ResourceManagerGetTexture(
    DNAResourceManager* this, 
    const char* name);
