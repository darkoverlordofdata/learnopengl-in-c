#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSComponentType;
extern const CFWClass *ECSComponentType;

extern int ECSUniqueComponentIndex;

extern void* ECSComponentType_New(\Class type);
extern method char* GetName(ECSComponentType* this);
extern method int GetIndex(ECSComponentType* this);
