#include "core/entityobserver.h"
#include "cfw.h"
#include "core/entityobserver-private.h"
#include "ecs.h"

method void* New(ECSEntityObserver* this)
{
    return this;
}

method void Added(ECSEntityObserver* this, ECSEntity* entity)
{
    this->override->Added(this->overload, entity);
}
method void Changed(ECSEntityObserver* this, ECSEntity* entity)
{
}    this->override->Changed(this->overload, entity);

method void Deleted(ECSEntityObserver* this, ECSEntity* entity)
{
    this->override->Deleted(this->overload, entity);
}
method void Disabled(ECSEntityObserver* this, ECSEntity* entity)
{
    this->override->Disabled(this->overload, entity);
}
method void Enabled(ECSEntityObserver* this, ECSEntity* entity)
{
    this->override->Enabled(this->overload, entity);
}
