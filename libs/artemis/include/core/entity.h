#pragma once
#include "cfw.h"

typedef struct ECSEntity ECSEntity;
extern const CFWClass* ECSEntityClass;

typedef struct ECSWorld ECSWorld;
typedef struct ECSComponent ECSComponent;
typedef struct ECSComponentType ECSComponentType;

extern method void* New(ECSEntity* this, ECSWorld* world, int id, char* name);

extern method CFWBitVector* GetComponentBits(ECSEntity* this);

extern method CFWBitVector* GetSystemBits(ECSEntity* this);

extern method int GetId(ECSEntity* this);

extern method CFWUuid* GetUUID(ECSEntity* this);

extern method void Reset(ECSEntity* this);

extern method ECSEntity* AddComponent(ECSEntity* this, ECSComponent* component);

extern method ECSComponentType* GetTypeFor(ECSEntity* this, CFWClass* c);

extern method ECSEntity* RemoveComponentInstance(ECSEntity* this, ECSComponent* component);

extern method ECSEntity* RemoveComponent(ECSEntity* this, ECSComponentType* type);

extern method ECSEntity* RemoveComponentByType(ECSEntity* this, CFWClass* type);

extern method bool IsActive(ECSEntity* this);

extern method bool IsEnabled(ECSEntity* this);

extern method ECSComponent* GetComponent(ECSEntity* this, ECSComponentType* type);

extern method ECSComponent* GetComponentByType(ECSEntity* this, CFWClass* type);

extern method CFWArray* GetCompoments(ECSEntity* this, CFWArray* fillBag);

extern method void AddToWorld(ECSEntity* this);

extern method void ChangedInWorld(ECSEntity* this);

extern method void DeleteFromWorld(ECSEntity* this);

extern method void Enable(ECSEntity* this);

extern method void Disable(ECSEntity* this);

extern method ECSWorld* GetWorld(ECSEntity* this);
