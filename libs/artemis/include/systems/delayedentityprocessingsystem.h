#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSDelayedEntityProcessingSystem;
extern const CFWClass *ECSDelayedEntityProcessingSystem;

extern void* ECSDelayedEntityProcessingSystem_New(ECSDelayedEntityProcessingSystem* this, ECSAspect* aspect);

extern void ECSDelayedEntityProcessingSystem_Begin(ECSDelayedEntityProcessingSystem* this);

extern void ECSDelayedEntityProcessingSystem_Process(ECSDelayedEntityProcessingSystem* this);

extern void ECSDelayedEntityProcessingSystem_End(ECSDelayedEntityProcessingSystem* this);

extern void ECSDelayedEntityProcessingSystem_ProcessEntities(ECSDelayedEntityProcessingSystem* this, Array* entities) 

extern bool ECSDelayedEntityProcessingSystem_CheckProcessing(ECSDelayedEntityProcessingSystem* this);

extern void ECSDelayedEntityProcessingSystem_Initialize(ECSDelayedEntityProcessingSystem* this);

extern void ECSDelayedEntityProcessingSystem_Inserted(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_Removed(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_Check(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_RemoveFromSystem(ECSDelayedEntityProcessingSystem* this, ECSEntity* e); 

extern void ECSDelayedEntityProcessingSystem_InsertToSystem(ECSDelayedEntityProcessingSystem* this, ECSEntity* e); 

extern void ECSDelayedEntityProcessingSystem_Added(ECSDelayedEntityProcessingSystem* this, ECSEntity* entity);

extern void ECSDelayedEntityProcessingSystem_Changed(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_Deleted(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_Disabled(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_Enabled(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_SetWorld(ECSDelayedEntityProcessingSystem* this, ECSWorld* world);

extern bool ECSDelayedEntityProcessingSystem_IsPassive(ECSDelayedEntityProcessingSystem* this);

extern void ECSDelayedEntityProcessingSystem_SetPassive(ECSDelayedEntityProcessingSystem* this, bool passive);

extern CFWArray* ECSDelayedEntityProcessingSystem_GetActive(ECSDelayedEntityProcessingSystem* this);

extern float ECSDelayedEntityProcessingSystem_GetRemainingDelay(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_ProcessDelta(ECSDelayedEntityProcessingSystem* this, ECSEntity* e, float accumulatedDelta);

extern void ECSDelayedEntityProcessingSystem_ProcessExpired(ECSDelayedEntityProcessingSystem* this, ECSEntity* e);

extern void ECSDelayedEntityProcessingSystem_Restart(ECSDelayedEntityProcessingSystem* this, float delay);

extern void ECSDelayedEntityProcessingSystem_OfferDelay(ECSDelayedEntityProcessingSystem* this, float delay);

extern float ECSDelayedEntityProcessingSystem_GetInitialTimeDelay(ECSDelayedEntityProcessingSystem* this);

extern float ECSDelayedEntityProcessingSystem_GetRemainingTimeUntilProcessing(ECSDelayedEntityProcessingSystem* this);

extern bool ECSDelayedEntityProcessingSystem_IsRunning(ECSDelayedEntityProcessingSystem* this);

extern void ECSDelayedEntityProcessingSystem_Stop(ECSDelayedEntityProcessingSystem* this);

