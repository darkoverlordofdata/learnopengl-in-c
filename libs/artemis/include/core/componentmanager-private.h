#pragma once
#include "cfw.h"
#include "componentmanager.h"
#include "ecs.h"


struct ECSComponentManager
{
    CFWObject obj;
    ECSManager* override;
    ECSWorld* World;
    CFWArray* ComponentsByType; // Array of Array
    CFWArray* Deleted;
    ECSComponentTypeFactory* TypeFactory;
};

