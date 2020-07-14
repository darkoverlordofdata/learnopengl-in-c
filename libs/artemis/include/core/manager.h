#pragma once
#include "cfw.h"

typedef struct ECSWorld ECSWorld;
typedef struct ECSEntity ECSEntity;
typedef struct ECSManager ECSManager;

typedef struct ECSManager ECSManager;
extern const CFWClass* ECSManagerClass;

extern method void* New(ECSManager* this);

extern method void Initialize(ECSManager* this);

extern method void SetWorld(ECSManager* this, ECSWorld* world);

extern method ECSWorld* GetWorld(ECSManager* this);

extern method void Added(ECSManager* this, ECSEntity* entity);

extern method void Changed(ECSManager* this, ECSEntity* entity);

extern method void Deleted(ECSManager* this, ECSEntity* entity);

extern method void Disabled(ECSManager* this, ECSEntity* entity);

extern method void Enabled(ECSManager* this, ECSEntity* entity);
