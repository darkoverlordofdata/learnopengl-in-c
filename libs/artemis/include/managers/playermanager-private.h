#pragma once
#include "cfw.h"
#include "ecs.h"
#include "playermanager.h"

struct ECSPlayerManager {
    CFWObject obj;
    ECSManager* overload;
    ECSWorld* World;
    CFWMap* PlayerByEntity;
    CFWMap* EntitiesByPlayer;
};
