#include "managers/playermanager.h"
#include "cfw.h"
#include "core/entity.h"
#include "core/world.h"
#include "ecs.h"
#include "managers/playermanager-private.h"

method void* New(ECSPlayerManager* this)
{
    this->PlayerByEntity = cfw_new(cfw_map, NULL);
    this->EntitiesByPlayer = cfw_new(cfw_map, NULL);
    return this;
}

method void Initialize(ECSPlayerManager* this) { this->overload->Initialize(this); }

method void SetWorld(ECSPlayerManager* this, ECSWorld* world)
{
    SetWorld(this->overload, world);
}

method ECSWorld* GetWorld(ECSPlayerManager* this)
{
    return GetWorld(this->overload);
}

method void Added(ECSPlayerManager* this, ECSEntity* entity) { this->overload->Added(this, entity); }

method void Changed(ECSPlayerManager* this, ECSEntity* entity) { this->overload->Changed(this, entity); }

method void Deleted(ECSPlayerManager* this, ECSEntity* entity)
{
    RemoveFromPlayer(this, entity);
}

method void Disabled(ECSPlayerManager* this, ECSEntity* entity) { this->overload->Disabled(this, entity); }

method void Enabled(ECSPlayerManager* this, ECSEntity* entity) { this->overload->Enabled(this, entity); }

method void SetPlayer(ECSPlayerManager* this, ECSEntity* e, char* player)
{
    Put(this->PlayerByEntity, e->key, player);
    CFWArray* entities = Get(this->EntitiesByPlayer, player);
    if (entities == NULL) {
        entities = cfw_new(cfw_array, NULL);
        Put(this->EntitiesByPlayer, player, entities);
    }
    Add(entities, e);
}

method CFWArray* GetEntitiesOfPlayer(ECSPlayerManager* this, char* player)
{
    CFWArray* entities = Get(this->EntitiesByPlayer, player);
    if (entities == NULL) {
        entities = cfw_new(cfw_array, NULL);
    }
    return entities;
}

method void RemoveFromPlayer(ECSPlayerManager* this, ECSEntity* e)
{
    char* player = Get(this->PlayerByEntity, e->key);
    if (player != NULL) {
        CFWArray* entities = Get(this->EntitiesByPlayer, player);
        if (entities != NULL) {
            Remove(entities, e);
        }
    }
}

method char* GetPlayer(ECSPlayerManager* this, ECSEntity* e)
{
    return Get(this->PlayerByEntity, e->key);
}
