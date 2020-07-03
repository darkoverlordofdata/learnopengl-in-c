#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSVoidEntitySystem;
extern const CFWClass *ECSVoidEntitySystem;

extern void* ECSVoidEntitySystem_New(ECSVoidEntitySystem* this);

extern void ECSVoidEntitySystem_Begin(ECSVoidEntitySystem* this);

extern void ECSVoidEntitySystem_Process(ECSVoidEntitySystem* this);

extern void ECSVoidEntitySystem_End(ECSVoidEntitySystem* this);

extern void ECSVoidEntitySystem_ProcessEntities(ECSVoidEntitySystem* this, Array* entities);

extern bool ECSVoidEntitySystem_CheckProcessing(ECSVoidEntitySystem* this);

extern void ECSVoidEntitySystem_Initialize(ECSVoidEntitySystem* this);

extern void ECSVoidEntitySystem_Inserted(ECSVoidEntitySystem* this, ECSEntity* e);

extern void ECSVoidEntitySystem_Removed(ECSVoidEntitySystem* this, ECSEntity* e);

extern void ECSVoidEntitySystem_Check(ECSVoidEntitySystem* this, ECSEntity* e);

extern void ECSVoidEntitySystem_RemoveFromSystem(ECSVoidEntitySystem* this, ECSEntity* e); 

extern void ECSVoidEntitySystem_InsertToSystem(ECSVoidEntitySystem* this, ECSEntity* e); 

extern void ECSVoidEntitySystem_Added(ECSVoidEntitySystem* this, ECSEntity* entity);

extern void ECSVoidEntitySystem_Changed(ECSVoidEntitySystem* this, ECSEntity* e);

extern void ECSVoidEntitySystem_Deleted(ECSVoidEntitySystem* this, ECSEntity* e);

extern void ECSVoidEntitySystem_Disabled(ECSVoidEntitySystem* this, ECSEntity* e);

extern void ECSVoidEntitySystem_Enabled(ECSVoidEntitySystem* this, ECSEntity* e);

extern void ECSVoidEntitySystem_SetWorld(ECSVoidEntitySystem* this, ECSWorld* world);

extern bool ECSVoidEntitySystem_IsPassive(ECSVoidEntitySystem* this);

extern void ECSVoidEntitySystem_SetPassive(ECSVoidEntitySystem* this, bool passive);

extern CFWArray* ECSVoidEntitySystem_GetActive(ECSVoidEntitySystem* this);

extern void ECSVoidEntitySystem_ProcessSystem(ECSVoidEntitySystem* this);

