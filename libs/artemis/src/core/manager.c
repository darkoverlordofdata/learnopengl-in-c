#include "core/manager.h"
#include "cfw.h"
#include "core/entity.h"
#include "core/manager-private.h"
#include "core/world.h"
#include "ecs.h"

method void* New(ECSManager* this)
{
    return this;
}

method void Initialize(ECSManager* this) { this->override->Initialize(this->subclass); }

method void SetWorld(ECSManager* this, ECSWorld* world)
{
    this->World = world;
}

method ECSWorld* GetWorld(ECSManager* this)
{
    return this->World;
}

method void Added(ECSManager* this, ECSEntity* entity) { this->override->Added(this->subclass, entity); }

method void Changed(ECSManager* this, ECSEntity* entity) { this->override->Changed(this->subclass, entity); }

method void Deleted(ECSManager* this, ECSEntity* entity) { this->override->Deleted(this->subclass, entity); }

method void Disabled(ECSManager* this, ECSEntity* entity) { this->override->Disabled(this->subclass, entity); }

method void Enabled(ECSManager* this, ECSEntity* entity) { this->override->Enabled(this->subclass, entity); }
