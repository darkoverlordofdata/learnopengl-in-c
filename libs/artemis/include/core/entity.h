#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSEntity;
extern const CFWClass *ECSEntity;

extern void* ECSEntity_New(ECSEntity* this, ECSWorld* world, int id, char* name);

extern method BitSet* GetComponentBits(ECSEntity* this);

extern method BitSet* GetSystemBits(ECSEntity* this);

extern method int GetId(ECSEntity* this);

extern method UUID* GetUUID(ECSEntity* this);

extern method void Reset(ECSEntity* this);

extern method ECSEntity* AddComponent(ECSEntity* this, ECSComponent* component);

extern method ECSComponentType* GetTypeFor(ECSEntity* this, Class c);

extern method ECSEntity* RemoveComponentInstance(ECSEntity* this, ECSComponent* component);

extern method ECSEntity* RemoveComponent(ECSEntity* this, ECSComponentType* type);

extern method ECSEntity* RemoveComponentByType(ECSEntity* this, Class type);

extern method bool IsActive(ECSEntity* this);

extern method bool IsEnabled(ECSEntity* this);

extern method ECSComponent* GetComponent(ECSEntity* this, ECSComponentType* type);

extern method ECSComponent* GetComponentByType(ECSEntity* this, Class type);

extern method Array* GetCompoments(ECSEntity* this, Array* fillBag);

extern method void AddToWorld(ECSEntity* this);

extern method void ChangedInWorld(ECSEntity* this);

extern method void DeleteFromWorld(ECSEntity* this);

extern method void Enable(ECSEntity* this);

extern method void Disable(ECSEntity* this);

extern method ECSWorld* GetWorld(ECSEntity* this);
