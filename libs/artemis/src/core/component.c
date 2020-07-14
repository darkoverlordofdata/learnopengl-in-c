#include "core/component.h"
#include "cfw.h"
#include "core/component-private.h"
#include "ecs.h"
#include <assert.h>

method void* New(ECSComponent* this)
{
    return this;
}