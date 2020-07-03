#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSIntervalEntityProcessingSystem;
extern const CFWClass *ECSIntervalEntityProcessingSystem;

extern void* ECSIntervalEntityProcessingSystem_New(ECSIntervalEntityProcessingSystem* this, ECSAspect* aspect, float interval);

extern void ECSIntervalEntityProcessingSystem_Begin(ECSIntervalEntityProcessingSystem* this);

extern void ECSIntervalEntityProcessingSystem_Process(ECSIntervalEntityProcessingSystem* this);

extern void ECSIntervalEntityProcessingSystem_End(ECSIntervalEntityProcessingSystem* this);

extern void ECSIntervalEntityProcessingSystem_ProcessEntities(ECSIntervalEntityProcessingSystem* this, Array* entities);

extern bool ECSIntervalEntityProcessingSystem_CheckProcessing(ECSIntervalEntityProcessingSystem* this);

extern void ECSIntervalEntityProcessingSystem_Initialize(ECSIntervalEntityProcessingSystem* this);

extern void ECSIntervalEntityProcessingSystem_Inserted(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern void ECSIntervalEntityProcessingSystem_Removed(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern void ECSIntervalEntityProcessingSystem_Check(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern void ECSIntervalEntityProcessingSystem_RemoveFromSystem(ECSIntervalEntityProcessingSystem* this, ECSEntity* e); 

extern void ECSIntervalEntityProcessingSystem_InsertToSystem(ECSIntervalEntityProcessingSystem* this, ECSEntity* e); 

extern void ECSIntervalEntityProcessingSystem_Added(ECSIntervalEntityProcessingSystem* this, ECSEntity* entity);

extern void ECSIntervalEntityProcessingSystem_Changed(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern void ECSIntervalEntityProcessingSystem_Deleted(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern void ECSIntervalEntityProcessingSystem_Disabled(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern void ECSIntervalEntityProcessingSystem_Enabled(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern void ECSIntervalEntityProcessingSystem_SetWorld(ECSIntervalEntityProcessingSystem* this, ECSWorld* world);

extern bool ECSIntervalEntityProcessingSystem_IsPassive(ECSIntervalEntityProcessingSystem* this);

extern void ECSIntervalEntityProcessingSystem_SetPassive(ECSIntervalEntityProcessingSystem* this, bool passive);

extern CFWArray* ECSIntervalEntityProcessingSystem_GetActive(ECSIntervalEntityProcessingSystem* this);

extern void ECSIntervalEntityProcessingSystem_ProcessEach(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);
