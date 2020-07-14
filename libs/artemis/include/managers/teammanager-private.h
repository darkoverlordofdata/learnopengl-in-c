#pragma once
#include "cfw.h"
#include "ecs.h"
#include "tagmanager.h"

struct ECSTeamManager {
    CFWObject obj;
    ECSManager* overload;
    ECSWorld* World;
    CFWMap* PlayersByTeam;
    CFWMap* TeamByPlayer;
};
