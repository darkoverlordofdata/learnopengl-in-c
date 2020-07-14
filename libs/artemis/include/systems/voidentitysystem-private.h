#pragma once
#include "cfw.h"
#include "component.h"
#include "entity.h"
#include "world.h"

// method bool CheckProcessing(ECSVoidEntitySystem* self);
/**
 * Used to generate a unique bit for each system.
 * Only used internally in EntitySystem.
 */
struct ECSVoidEntitySystem {
    CFWObject obj;
    ECSEntitySystem* overload;
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
