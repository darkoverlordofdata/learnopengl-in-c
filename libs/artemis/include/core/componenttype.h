#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSComponentType;
extern const CFWClass *ECSComponentType;

extern int ECSUniqueComponentIndex;

extern void* ECSComponentType_New(\Class type);
extern char* ECSComponentType_GetName(ECSComponentType* this);
extern int ECSComponentType_GetIndex(ECSComponentType* this);
