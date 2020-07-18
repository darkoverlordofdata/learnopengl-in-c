#pragma once
#include "cfw.h"
#include "core/component-private.h"
#include "core/component.h"
#include "core/entity-private.h"
#include "core/entity.h"
#include "core/world-private.h"
#include "core/world.h"
#include "systems/entityprocessingsystem-private.h"
#include "systems/entityprocessingsystem.h"
#include "systems/intervalentityprocessingsystem.h"
#include "systems/intervalentitysystem-private.h"
#include "systems/intervalentitysystem.h"

// method bool CheckProcessing(ECSIntervalEntityProcessingSystem* self);
/**
 * Used to generate a unique bit for each system.
 * Only used internally in EntitySystem.
 */
struct ECSIntervalEntityProcessingSystem {
    CFWObject obj;
    ECSIIntervalEntityProcessingSystem* vptr;
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
