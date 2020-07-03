#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSComponentManager;
extern const CFWClass *ECSComponentManager;

extern BitSet* ECSComponentManager_GetComponentBits(ECSEntity* this);
extern int ECSComponentManager_GetId(ECSEntity* this);

extern void* ECSComponentManager_New();

extern ECSComponentTypeFactory* ECSComponentManager_GetTypeFactory(ECSComponentManager* this);

extern void ECSComponentManager_RemoveComponentsOfEntity(ECSComponentManager* this, ECSEntity* e);

extern void ECSComponentManager_AddComponent(ECSComponentManager* this, ECSEntity* e, ECSComponentType* type, ECSComponent* component);

extern void ECSComponentManager_RemoveComponent(ECSComponentManager* this, ECSEntity* e, ECSComponentType* type);

extern CFWArray* ECSComponentManager_GetComponentsByType(ECSComponentManager* this, ECSComponentType* type);

extern ECSComponent* ECSComponentManager_GetComponent(ECSComponentManager* this, ECSEntity* e, ECSComponentType* type);

extern CFWArray* ECSComponentManager_GetComponentsFor(ECSComponentManager* this, ECSEntity* e, CFWArray* fillBag);

extern void ECSComponentManager_Deleted(ECSComponentManager* this, ECSEntity* e);

extern void ECSComponentManager_Clean(ECSComponentManager* this);

extern void ECSComponentManager_Added(ECSComponentManager* this, ECSEntity* entity);

extern void ECSComponentManager_Changed(ECSComponentManager* this, ECSEntity* entity);

extern void ECSComponentManager_Disabled(ECSComponentManager* this, ECSEntity* entity);

extern void ECSComponentManager_Enabled(ECSComponentManager* this, ECSEntity* entity);
