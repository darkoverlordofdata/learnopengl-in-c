#pragma once
#include "entitymanager.h"
#include "cfw.h"
#include "ecs.h"

/*
 * Used only internally to generate distinct ids for entities and reuse them.
 */
struct ECSIdentifierPool
{
    CFWArray* Ids;
    int NextAvailableId;

};

struct ECSEntityManager
{
    CFWObject obj;
    ECSManager* override;
    ECSWorld* World;
    CFWArray* Entities;
    CFWBitVector* Disabled;
    int Active;
    int Added;
    int Created;
    int Deleted;
    ECSIdentifierPool* IdentifierPool;
};

