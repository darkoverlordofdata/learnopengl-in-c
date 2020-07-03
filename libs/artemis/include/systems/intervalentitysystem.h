#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSIntervalEntitySystem;
extern const CFWClass *ECSIntervalEntitySystem;

extern void* ECSIntervalEntitySystem_New(ECSIntervalEntitySystem* this, ECSAspect* aspect, float interval);

extern void ECSIntervalEntitySystem_Begin(ECSIntervalEntitySystem* this);virtual(ECSIntervalEntitySystem);

extern void ECSIntervalEntitySystem_Process(ECSIntervalEntitySystem* this);

extern void ECSIntervalEntitySystem_End(ECSIntervalEntitySystem* this);virtual(ECSIntervalEntitySystem);

extern void ECSIntervalEntitySystem_ProcessEntities(ECSIntervalEntitySystem* this, Array* entities);

extern bool ECSIntervalEntitySystem_CheckProcessing(ECSIntervalEntitySystem* this);

extern void ECSIntervalEntitySystem_Initialize(ECSIntervalEntitySystem* this);

extern void ECSIntervalEntitySystem_Inserted(ECSIntervalEntitySystem* this, ECSEntity* e);

extern void ECSIntervalEntitySystem_Removed(ECSIntervalEntitySystem* this, ECSEntity* e);

extern void ECSIntervalEntitySystem_Check(ECSIntervalEntitySystem* this, ECSEntity* e);

extern void ECSIntervalEntitySystem_RemoveFromSystem(ECSIntervalEntitySystem* this, ECSEntity* e); 

extern void ECSIntervalEntitySystem_InsertToSystem(ECSIntervalEntitySystem* this, ECSEntity* e); 

extern void ECSIntervalEntitySystem_Added(ECSIntervalEntitySystem* this, ECSEntity* entity);

extern void ECSIntervalEntitySystem_Changed(ECSIntervalEntitySystem* this, ECSEntity* e);

extern void ECSIntervalEntitySystem_Deleted(ECSIntervalEntitySystem* this, ECSEntity* e);

extern void ECSIntervalEntitySystem_Disabled(ECSIntervalEntitySystem* this, ECSEntity* e);

extern void ECSIntervalEntitySystem_Enabled(ECSIntervalEntitySystem* this, ECSEntity* e);

extern void ECSIntervalEntitySystem_SetWorld(ECSIntervalEntitySystem* this, ECSWorld* world);

extern bool ECSIntervalEntitySystem_IsPassive(ECSIntervalEntitySystem* this);

extern void ECSIntervalEntitySystem_SetPassive(ECSIntervalEntitySystem* this, bool passive);

extern CFWArray* ECSIntervalEntitySystem_GetActive(ECSIntervalEntitySystem* this);
