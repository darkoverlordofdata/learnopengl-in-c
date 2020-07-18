#pragma once
#include "cfw.h"
#include "core/component-private.h"
#include "core/component.h"
#include "core/entity-private.h"
#include "core/entity.h"
#include "core/entitysystem-private.h"
#include "core/entitysystem.h"
#include "core/world-private.h"
#include "core/world.h"
#include "systems/intervalentityprocessingsystem.h"

// method bool CheckProcessing(ECSIntervalEntitySystem* self);
/**
 * Used to generate a unique bit for each system.
 * Only used internally in EntitySystem.
 */
struct ECSIntervalEntitySystem {
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

    float Acc;
    float Interval;
};
