#pragma once
#include "cfw.h"
#include "ecs.h"
#include "playermanager.h"

struct ECSPlayerManager {
    CFWObject obj;
    ECSIManager* vptr;
    ECSWorld* World;
    CFWMap* PlayerByEntity;
    CFWMap* EntitiesByPlayer;
};
