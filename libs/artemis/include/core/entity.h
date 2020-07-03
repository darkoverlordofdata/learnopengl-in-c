#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSEntity;
extern const CFWClass *ECSEntity;

extern void* ECSEntity_New(ECSEntity* this, ECSWorld* world, int id, char* name);

extern BitSet* ECSEntity_GetComponentBits(ECSEntity* this);

extern BitSet* ECSEntity_GetSystemBits(ECSEntity* this);

extern int ECSEntity_GetId(ECSEntity* this);

extern UUID* ECSEntity_GetUUID(ECSEntity* this);

extern void ECSEntity_Reset(ECSEntity* this);

extern ECSEntity* ECSEntity_AddComponent(ECSEntity* this, ECSComponent* component);

extern ECSComponentType* ECSEntity_GetTypeFor(ECSEntity* this, Class c);

extern ECSEntity* ECSEntity_RemoveComponentInstance(ECSEntity* this, ECSComponent* component);

extern ECSEntity* ECSEntity_RemoveComponent(ECSEntity* this, ECSComponentType* type);

extern ECSEntity* ECSEntity_RemoveComponentByType(ECSEntity* this, Class type);

extern bool ECSEntity_IsActive(ECSEntity* this);

extern bool ECSEntity_IsEnabled(ECSEntity* this);

extern ECSComponent* ECSEntity_GetComponent(ECSEntity* this, ECSComponentType* type);

extern ECSComponent* ECSEntity_GetComponentByType(ECSEntity* this, Class type);

extern Array* ECSEntity_GetCompoments(ECSEntity* this, Array* fillBag);

extern void ECSEntity_AddToWorld(ECSEntity* this);

extern void ECSEntity_ChangedInWorld(ECSEntity* this);

extern void ECSEntity_DeleteFromWorld(ECSEntity* this);

extern void ECSEntity_Enable(ECSEntity* this);

extern void ECSEntity_Disable(ECSEntity* this);

extern ECSWorld* ECSEntity_GetWorld(ECSEntity* this);
