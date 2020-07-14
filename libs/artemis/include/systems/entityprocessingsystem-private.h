#pragma once
#include "cfw.h"
#include "component.h"
#include "system/entityprocessingsystem.h"
#include "entity.h"
#include "world.h"
/**
 * A typical entity system. Use this when you need to process entities possessing the
 * provided component types.
 *
 * @author Arni Arent
 *
 */
struct ECSEntityProcessingSystem {
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
