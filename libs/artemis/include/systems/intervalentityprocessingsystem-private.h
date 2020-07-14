#pragma once
#include "cfw.h"
#include "component.h"
#include "entity.h"
#include "system/entityprocessingsystem.h"
#include "system/intervalentityprocessingsystem.h"
#include "world.h"

// method bool CheckProcessing(ECSIntervalEntityProcessingSystem* self);
/**
 * Used to generate a unique bit for each system.
 * Only used internally in EntitySystem.
 */
struct ECSIntervalEntityProcessingSystem {
    CFWObject obj;
    ECSIntervalEntitySystem* overload;
    ECSWorld* World;
    int SystemIndex;
    CFWArray* Actives;
    ECSAspect* Aspect;
    CFWBitVector* AllSet;
    CFWBitVector* ExclusionSet;
    CFWBitVector* OneSet;
    bool Passive;
    bool IsDummy;

    float Acc;
    float Interval;
};
