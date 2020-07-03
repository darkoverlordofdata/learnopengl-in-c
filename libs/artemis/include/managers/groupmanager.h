#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSGroupManager;
extern const CFWClass *ECSGroupManager;

extern void* ECSGroupManager_New(ECSGroupManager* this);

extern void ECSGroupManager_Initialize(ECSGroupManager* this);

extern void ECSGroupManager_SetWorld(ECSGroupManager* this, ECSWorld* world);

extern ECSWorld* ECSGroupManager_GetWorld(ECSGroupManager* this);

extern void ECSGroupManager_Added(ECSGroupManager* this, ECSEntity* entity);

extern void ECSGroupManager_Changed(ECSGroupManager* this, ECSEntity* entity);

extern void ECSGroupManager_Deleted(ECSGroupManager* this, ECSEntity* entity) 

extern void ECSGroupManager_Disabled(ECSGroupManager* this, ECSEntity* entity);

extern void ECSGroupManager_Enabled(ECSGroupManager* this, ECSEntity* entity);

extern void ECSGroupManager_Add(ECSGroupManager* this, ECSEntity* e, char* group);

extern void ECSGroupManager_Remove(ECSGroupManager* this, ECSEntity* e, char* group);

extern void ECSGroupManager_RemoveFromAllGroups(ECSGroupManager* this, ECSEntity* e);

extern CFWArray* ECSGroupManager_GetEntities(ECSGroupManager* this, char* group);

extern CFWArray* ECSGroupManager_GetGroups(ECSGroupManager* this, ECSEntity* e);

extern bool ECSGroupManager_IsInAnyGroup(ECSGroupManager* this, ECSEntity* e);

extern bool ECSGroupManager_IsInGroup(ECSGroupManager* this, ECSEntity* e, char* group);

