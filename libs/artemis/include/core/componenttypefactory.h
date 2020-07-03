#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSComponentTypeFactory;
extern const CFWClass *ECSComponentTypeFactory;


extern void* ECSComponentTypeFactory_New();

extern ECSComponentType* ECSComponentTypeFactory_GetTypeFor(ECSComponentTypeFactory* this, Class c);

extern int ECSComponentTypeFactory_GetIndexFor(ECSComponentTypeFactory* this, Class c);
