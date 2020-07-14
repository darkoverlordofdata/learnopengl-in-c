#pragma once
#include "entity.h"
#include "cfw.h"
#include "ecs.h"

/**
 * The entity class. Cannot be instantiated outside the framework, you must
 * create new entities using World.
 * 
 * @author Arni Arent
 * 
 */
struct ECSEntity {
    CFWObject obj;
    char* Name;
    int Id;
    CFWUuid* uuid;
    char* key;
    CFWBitVector* ComponentBits;
    CFWBitVector* SystemBits;
    ECSWorld* World;
    ECSEntityManager* EntityManager;
    ECSComponentManager* ComponentManager;
};
