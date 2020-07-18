#pragma once
#include "cfw.h"
#include "ecs.h"
#include "entityobserver-private.h"
#include "entityobserver.h"
#include "entitysystem.h"

// method bool CheckProcessing(ECSEntitySystem* self);
/**
 * Used to generate a unique bit for each system.
 * Only used internally in EntitySystem.
 */
struct ECSSystemIndexManager {
    int Index;
    CFWMap* Indices;
};

struct ECSEntitySystem {
    CFWObject obj;
    ECSIEntitySystem* vptr;
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
