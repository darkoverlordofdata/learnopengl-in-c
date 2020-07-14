#pragma once
#include "cfw.h"
#include "ecs.h"
#include "tagmanager.h"

struct ECSTagManager {
    CFWObject obj;
    ECSManager* base;
    ECSWorld* World;
    CFWMap* EntitiesByTag;
    CFWMap* TagsByEntity;
};
