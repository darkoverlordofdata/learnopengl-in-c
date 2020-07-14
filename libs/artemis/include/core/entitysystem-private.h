#pragma once
#include "cfw.h"
#include "ecs.h"
#include "entitysystem.h"

// method bool CheckProcessing(ECSEntitySystem* self);
/**
 * Used to generate a unique bit for each system.
 * Only used internally in EntitySystem.
 */
struct ECSSystemIndexManager ECSSystemIndexManager;
struct ECSSystemIndexManager {
    int Index;
    Map* Indices;
};

struct ECSEntitySystem {
    CFWObject obj;
    ECSEntityObserver* override;
    ECSWorld* World;
    int SystemIndex;
    CFWArray* Actives;
    ECSAspect* Aspect;
    CFWBitVector* AllSet;
    CFWBitVector* ExclusionSet;
    CFWBitVector* OneSet;
    bool Passive;
    bool IsDummy;
};
