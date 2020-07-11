#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSManager;
extern const CFWClass *ECSManager;

extern void* ECSManager_New(ECSManager* this);

extern method void Initialize(ECSManager* this);

extern method void SetWorld(ECSManager* this, ECSWorld* world);

extern method ECSWorld* GetWorld(ECSManager* this);

extern method void Added(ECSManager* this, ECSEntity* entity);

extern method void Changed(ECSManager* this, ECSEntity* entity);

extern method void Deleted(ECSManager* this, ECSEntity* entity);

extern method void Disabled(ECSManager* this, ECSEntity* entity);

extern method void Enabled(ECSManager* this, ECSEntity* entity);
