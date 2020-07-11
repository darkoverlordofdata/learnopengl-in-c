#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSGroupManager;
extern const CFWClass *ECSGroupManager;

extern void* ECSGroupManager_New(ECSGroupManager* this);

extern method void Initialize(ECSGroupManager* this);

extern method void SetWorld(ECSGroupManager* this, ECSWorld* world);

extern method ECSWorld* GetWorld(ECSGroupManager* this);

extern method void Added(ECSGroupManager* this, ECSEntity* entity);

extern method void Changed(ECSGroupManager* this, ECSEntity* entity);

extern method void Deleted(ECSGroupManager* this, ECSEntity* entity) 

extern method void Disabled(ECSGroupManager* this, ECSEntity* entity);

extern method void Enabled(ECSGroupManager* this, ECSEntity* entity);

extern method void Add(ECSGroupManager* this, ECSEntity* e, char* group);

extern method void Remove(ECSGroupManager* this, ECSEntity* e, char* group);

extern method void RemoveFromAllGroups(ECSGroupManager* this, ECSEntity* e);

extern method CFWArray* GetEntities(ECSGroupManager* this, char* group);

extern method CFWArray* GetGroups(ECSGroupManager* this, ECSEntity* e);

extern method bool IsInAnyGroup(ECSGroupManager* this, ECSEntity* e);

extern method bool IsInGroup(ECSGroupManager* this, ECSEntity* e, char* group);

