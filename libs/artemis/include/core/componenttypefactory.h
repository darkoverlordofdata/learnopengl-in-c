#pragma once
#include "cfw.h"
#include "componenttype.h"

typedef struct ECSComponentTypeFactory ECSComponentTypeFactory;
extern const CFWClass* ECSComponentTypeFactoryClass;

extern method void* New(ECSComponentTypeFactory* this);

extern method ECSComponentType* GetTypeFor(ECSComponentTypeFactory* this, CFWClass* c);

extern method int GetIndexFor(ECSComponentTypeFactory* this, CFWClass* c);
