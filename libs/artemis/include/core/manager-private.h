#pragma once
#include "cfw.h"
#include "ecs.h"
#include "entityobserver-private.h"
#include "entityobserver.h"
#include "manager.h"

struct ECSManager {
    CFWObject obj;
    ECSIManager* vptr;
    ECSWorld* World;
};
