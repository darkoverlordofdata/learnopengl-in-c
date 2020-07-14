#pragma once
#include "cfw.h"
#include "componenttypefactory.h"
#include "ecs.h"

struct ECSComponentTypeFactory {
    CFWObject obj;
    CFWObject* override;
    CFWMap* ComponentTypes;
    int ComponentTypeCount;
    CFWArray* Types;
};
