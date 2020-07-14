#include "core/componenttype.h"
#include "cfw.h"
#include "core/componenttype-private.h"
#include "ecs.h"
#include <assert.h>

int ECSUniqueComponentIndex = 0;

method void* New(ECSComponentType* this, CFWClass* type)
{
    this->Type = type;
    this->Index = ECSUniqueComponentIndex++;
    return this;
}

method char* GetName(ECSComponentType* this)
{
    return this->Type->name;
}

method int GetIndex(ECSComponentType* this)
{
    return this->Index;
}
