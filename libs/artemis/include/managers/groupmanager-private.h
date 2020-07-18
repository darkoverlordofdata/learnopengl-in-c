#pragma once
#include "groupmanager.h"
#include "cfw.h"
#include "ecs.h"

struct ECSGroupManager {
    CFWObject object;
    ECSIManager* vptr;
    ECSWorld* World;
    CFWMap* EntitiesByGroup;
    CFWMap* GroupsByEntity;
};
