#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSComponentTypeFactory;
extern const CFWClass *ECSComponentTypeFactory;


extern void* ECSComponentTypeFactory_New();

extern method ECSComponentType* GetTypeFor(ECSComponentTypeFactory* this, Class c);

extern method int GetIndexFor(ECSComponentTypeFactory* this, Class c);
