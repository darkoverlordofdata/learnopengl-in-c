#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSEntityProcessingSystem;
extern const CFWClass *ECSEntityProcessingSystem;

extern void* ECSEntityProcessingSystem_New(ECSEntityProcessingSystem* this, ECSAspect* aspect);

extern void ECSEntityProcessingSystem_Begin(ECSEntityProcessingSystem* this);

extern void ECSEntityProcessingSystem_Process(ECSEntityProcessingSystem* this);

extern void ECSEntityProcessingSystem_End(ECSEntityProcessingSystem* this);

extern void ECSEntityProcessingSystem_ProcessEntities(ECSEntityProcessingSystem* this, Array* entities);

extern bool ECSEntityProcessingSystem_CheckProcessing(ECSEntityProcessingSystem* this);

extern void ECSEntityProcessingSystem_Initialize(ECSEntityProcessingSystem* this);

extern void ECSEntityProcessingSystem_Inserted(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_Removed(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_Check(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_RemoveFromSystem(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_InsertToSystem(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_Added(ECSEntityProcessingSystem* this, ECSEntity* entity);

extern void ECSEntityProcessingSystem_Changed(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_Deleted(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_Disabled(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_Enabled(ECSEntityProcessingSystem* this, ECSEntity* e);

extern void ECSEntityProcessingSystem_SetWorld(ECSEntityProcessingSystem* this, ECSWorld* world);

extern bool ECSEntityProcessingSystem_IsPassive(ECSEntityProcessingSystem* this);

extern void ECSEntityProcessingSystem_SetPassive(ECSEntityProcessingSystem* this, bool passive);

extern CFWArray* ECSEntityProcessingSystem_GetActive(ECSEntityProcessingSystem* this);

extern void ECSEntityProcessingSystem_ProcessEach(ECSEntityProcessingSystem* this, ECSEntity* e);

