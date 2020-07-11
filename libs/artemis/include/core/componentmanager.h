#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSComponentManager;
extern const CFWClass *ECSComponentManager;

extern method BitSet* GetComponentBits(ECSEntity* this);
extern method int GetId(ECSEntity* this);

extern void* ECSComponentManager_New();

extern method ECSComponentTypeFactory* GetTypeFactory(ECSComponentManager* this);

extern method void RemoveComponentsOfEntity(ECSComponentManager* this, ECSEntity* e);

extern method void AddComponent(ECSComponentManager* this, ECSEntity* e, ECSComponentType* type, ECSComponent* component);

extern method void RemoveComponent(ECSComponentManager* this, ECSEntity* e, ECSComponentType* type);

extern method CFWArray* GetComponentsByType(ECSComponentManager* this, ECSComponentType* type);

extern method ECSComponent* GetComponent(ECSComponentManager* this, ECSEntity* e, ECSComponentType* type);

extern method CFWArray* GetComponentsFor(ECSComponentManager* this, ECSEntity* e, CFWArray* fillBag);

extern method void Deleted(ECSComponentManager* this, ECSEntity* e);

extern method void Clean(ECSComponentManager* this);

extern method void Added(ECSComponentManager* this, ECSEntity* entity);

extern method void Changed(ECSComponentManager* this, ECSEntity* entity);

extern method void Disabled(ECSComponentManager* this, ECSEntity* entity);

extern method void Enabled(ECSComponentManager* this, ECSEntity* entity);
