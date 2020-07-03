#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSManager;
extern const CFWClass *ECSManager;

extern void* ECSManager_New(ECSManager* this);

extern void ECSManager_Initialize(ECSManager* this);

extern void ECSManager_SetWorld(ECSManager* this, ECSWorld* world);

extern ECSWorld* ECSManager_GetWorld(ECSManager* this);

extern void ECSManager_Added(ECSManager* this, ECSEntity* entity);

extern void ECSManager_Changed(ECSManager* this, ECSEntity* entity);

extern void ECSManager_Deleted(ECSManager* this, ECSEntity* entity);

extern void ECSManager_Disabled(ECSManager* this, ECSEntity* entity);

extern void ECSManager_Enabled(ECSManager* this, ECSEntity* entity);
