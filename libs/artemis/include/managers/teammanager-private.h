#pragma once
#include "cfw.h"
#include "ecs.h"
#include "tagmanager.h"

struct ECSTeamManager {
    CFWObject obj;
    ECSIManager* vptr;
    ECSWorld* World;
    CFWMap* PlayersByTeam;
    CFWMap* TeamByPlayer;
};
