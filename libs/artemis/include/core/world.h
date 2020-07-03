#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSWorld;
extern const CFWClass *ECSWorld;

extern void* ECSWorld_New(ECSWorld* this);

extern void ECSWorld_Initialize(ECSWorld* this); 

extern ECSEntityManager* ECSWorld_GetEntityManager(ECSWorld* this); 

extern ECSComponentManager* ECSWorld_GetComponentManager(ECSWorld* this); 

extern ECSManager* ECSWorld_SetManager(ECSWorld* this, ECSManager* manager); 

extern ECSManager* ECSWorld_GetManager(ECSWorld* this, Class type); 

extern void ECSWorld_DeleteManager(ECSWorld* this, ECSManager* manager); 

extern float ECSWorld_GetDelta(ECSWorld* this); 

extern void ECSWorld_SetDelta(ECSWorld* this, float delta); 

extern void ECSWorld_AddEntity(ECSWorld* this, ECSEntity* e); 

extern void ECSWorld_ChangedEntity(ECSWorld* this, ECSEntity* e); 

extern void ECSWorld_DeleteEntity(ECSWorld* this, ECSEntity* e); 

extern void ECSWorld_Enable(ECSWorld* this, ECSEntity* e); 

extern void ECSWorld_Disable(ECSWorld* this, ECSEntity* e); 

extern ECSEntity* ECSWorld_CreateEntity(ECSWorld* this, char* name); 

extern ECSEntity* ECSWorld_GetEntity(ECSWorld* this, int entityId); 

extern CFWArray* ECSWorld_GetSystems(ECSWorld* this); 

extern ECSEntitySystem* ECSWorld_SetSystem(ECSWorld* this, ECSEntitySystem* system, bool passive); 

extern ECSEntitySystem* ECSWorld_SetSystem(ECSWorld* this, ECSEntitySystem* system); 

extern void ECSWorld_DeleteSystem(ECSWorld* this, ECSEntitySystem* system); 

extern void ECSWorld_NotifySystems(ECSWorld* this, ECSPerformer perform, ECSEntity* e); 

extern void NotifyManagers(ECSWorld* this, ECSPerformer perform, ECSEntity* e); 

extern ECSEntitySystem* ECSWorld_GetSystem(ECSWorld* this, Class type); 

extern void ECSWorld_Check(ECSWorld* this, Array* entities, ECSPerformer perform); 

extern void ECSWorld_Update(ECSWorld* this); 

extern void ECSWorld_Draw(ECSWorld* this);
