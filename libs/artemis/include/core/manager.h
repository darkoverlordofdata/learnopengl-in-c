#pragma once
#include "cfw.h"

typedef struct ECSWorld ECSWorld;
typedef struct ECSEntity ECSEntity;
typedef struct ECSManager ECSManager;

typedef struct ECSIManager ECSIManager;
typedef struct ECSManager ECSManager;
extern const CFWClass* ECSManagerClass;

struct ECSIManager {
    //ECSIEntityObserver
    void (*Added)(void* this, ECSEntity* entity);
    void (*Changed)(void* this, ECSEntity* entity);
    void (*Deleted)(void* this, ECSEntity* entity);
    void (*Disabled)(void* this, ECSEntity* entity);
    void (*Enabled)(void* this, ECSEntity* entity);
    void (*Begin)(void* this);
    void (*End)(void* this);

    //ECSIManager
    void (*Initialize)(void* this);
};


extern method void* New(ECSManager* this, ECSIManager* vptr);

extern method void Initialize(ECSManager* this);

extern method void SetWorld(ECSManager* this, ECSWorld* world);

extern method ECSWorld* GetWorld(ECSManager* this);

extern method void Added(ECSManager* this, ECSEntity* entity);

extern method void Changed(ECSManager* this, ECSEntity* entity);

extern method void Deleted(ECSManager* this, ECSEntity* entity);

extern method void Disabled(ECSManager* this, ECSEntity* entity);

extern method void Enabled(ECSManager* this, ECSEntity* entity);
