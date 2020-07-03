#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSEntitySystem;
extern const CFWClass *ECSEntitySystem;

struct ECSSystemIndexManager;
extern int ECSSystemIndexManager_GetIndexFor(char* es);

extern void* ECSEntitySystem_New(ECSEntitySystem* this, ECSAspect* aspect);

extern void ECSEntitySystem_Begin(ECSEntitySystem* this);

extern void ECSEntitySystem_Process(ECSEntitySystem* this);

extern void ECSEntitySystem_End(ECSEntitySystem* this);

extern void ECSEntitySystem_ProcessEntities(ECSEntitySystem* this, Array* entities);

extern bool CheckProcessing(ECSEntitySystem* this);

extern void ECSEntitySystem_Initialize(ECSEntitySystem* this);

extern void ECSEntitySystem_Inserted(ECSEntitySystem* this, ECSEntity* e);

extern void ECSEntitySystem_Removed(ECSEntitySystem* this, ECSEntity* e);

extern void ECSEntitySystem_Check(ECSEntitySystem* this, ECSEntity* e); 

extern void ECSEntitySystem_RemoveFromSystem(ECSEntitySystem* this, ECSEntity* e);

extern void ECSEntitySystem_InsertToSystem(ECSEntitySystem* this, ECSEntity* e);

extern void ECSEntitySystem_Added(ECSEntitySystem* this, ECSEntity* entity);

extern void ECSEntitySystem_Changed(ECSEntitySystem* this, ECSEntity* e);

extern void ECSEntitySystem_Deleted(ECSEntitySystem* this, ECSEntity* e);

extern void ECSEntitySystem_Disabled(ECSEntitySystem* this, ECSEntity* e);

extern void ECSEntitySystem_Enabled(ECSEntitySystem* this, ECSEntity* e);

extern void ECSEntitySystem_SetWorld(ECSEntitySystem* this, ECSWorld* world);

extern bool ECSEntitySystem_IsPassive(ECSEntitySystem* this);

extern void ECSEntitySystem_SetPassive(ECSEntitySystem* this, bool passive);

extern CFWArray* ECSEntitySystem_GetActive(ECSEntitySystem* this);
