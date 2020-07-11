#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSAspect;
extern const CFWClass* ECSAspect;

extern void* ECSAspect_New();

extern method void SetTypeFactory(ECSComponentTypeFactory* typeFactory);

extern method void SetWorld(ECSAspect* this, ECSWorld* world);

extern method BitSet* GetAllSet(ECSAspect* this);

extern method BitSet* GetExclusionSet(ECSAspect* this);

extern method BitSet* GetOneSet(ECSAspect* this);

extern method ECSAspect* All(ECSAspect* this, int count, va_list _args);

extern method ECSAspect* Exclude(ECSAspect* this, int count, va_list _args);

extern method ECSAspect* One(ECSAspect* this, int count, va_list _args);

extern method ECSAspect* GetAspectForAll(int count, ...);

extern method ECSAspect* GetAspectForOne(int count, ...);

extern method ECSAspect* GetAspectForNone(void);