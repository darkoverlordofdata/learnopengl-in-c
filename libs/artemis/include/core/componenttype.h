#pragma once
#include "cfw.h"

typedef struct ECSComponentType ECSComponentType;
extern const CFWClass* ECSComponentTypeClass;

extern int ECSUniqueComponentIndex;

extern method void* New(ECSComponentType* this, CFWClass* type);
extern method char* GetName(ECSComponentType* this);
extern method int GetIndex(ECSComponentType* this);
