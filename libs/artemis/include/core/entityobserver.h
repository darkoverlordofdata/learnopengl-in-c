#pragma once
#include "cfw.h"

typedef struct ECSEntityObserver ECSEntityObserver;
extern const CFWClass* ECSEntityObserverClass;

typedef struct ECSEntity ECSEntity;
// typedef struct ECS ECS;

typedef void (*ECSEntityProc)(void* this, void* entity);
struct ECSIEntityObserver {
    void (*Added)(void* this, void* entity);
    void (*Changed)(void* this, void* entity);
    void (*Deleted)(void* this, void* entity);
    void (*Disabled)(void* this, void* entity);
    void (*Enabled)(void* this, void* entity);
};

extern method void* New(ECSEntityObserver* this);

extern method void Added(ECSEntityObserver* this, ECSEntity* entity);

extern method void Changed(ECSEntityObserver* this, ECSEntity* entity);

extern method void Deleted(ECSEntityObserver* this, ECSEntity* entity);

extern method void Disabled(ECSEntityObserver* this, ECSEntity* entity);

extern method void Enabled(ECSEntityObserver* this, ECSEntity* entity);

