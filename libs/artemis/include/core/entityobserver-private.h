#pragma once
#include "cfw.h"
#include "ecs.h"
#include "entityobserver.h"

struct ECSEntityObserver {
    CFWObject obj;
    CFWObject* override;
};
