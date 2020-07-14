#pragma once
#include "cfw.h"
#include "componenttype.h"
#include "ecs.h"

struct ECSComponentType
{
    CFWObject obj;
    CFWObject* override;
    int Index;
    CFWClass* Type;
};
