#pragma once
#include "cfw.h"
#include "ecs.h"
#include "manager.h"

struct ECSManager {
    CFWObject obj;
    ECSEntityObserver* override;
    ECSWorld* World;
};
