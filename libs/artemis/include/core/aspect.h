#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSAspect;
extern const CFWClass *ECSAspect;

extern void* ECSAspect_New();

extern void ECSAspect_SetTypeFactory(ECSComponentTypeFactory* typeFactory);

extern void ECSAspect_SetWorld(ECSAspect* this, ECSWorld* world);

extern BitSet* ECSAspect_GetAllSet(ECSAspect* this);

extern BitSet* ECSAspect_GetExclusionSet(ECSAspect* this);

extern BitSet* ECSAspect_GetOneSet(ECSAspect* this);

extern ECSAspect* ECSAspect_All(ECSAspect* this, int count, va_list _args);

extern ECSAspect* ECSAspect_Exclude(ECSAspect* this, int count, va_list _args);

extern ECSAspect* ECSAspect_One(ECSAspect* this, int count, va_list _args);

extern ECSAspect* ECSAspect_GetAspectForAll(int count, ...);

extern ECSAspect* ECSAspect_GetAspectForOne(int count, ...);

extern ECSAspect* ECSAspect_GetAspectForNone(void);