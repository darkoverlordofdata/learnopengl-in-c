#include "managers/tagmanager.h"
#include "cfw.h"
#include "core/entity.h"
#include "core/world.h"
#include "ecs.h"
#include "managers/tagmanager-private.h"

method void* New(ECSTagManager* this)
{
    this->EntitiesByTag = cfw_new(cfw_map, NULL);
    this->TagsByEntity = cfw_new(cfw_map, NULL);
    return this;
}

method void Initialize(ECSTagManager* this) { this->overload->Initialize(this); }

method void SetWorld(ECSTagManager* this, ECSWorld* world)
{
    SetWorld(this->overload, world);
}

method ECSWorld* GetWorld(ECSTagManager* this)
{
    return GetWorld(this->overload);
}

method void Added(ECSTagManager* this, ECSEntity* entity) { this->overload->Added(this, entity); }

method void Changed(ECSTagManager* this, ECSEntity* entity) { this->overload->Changed(this, entity); }

method void Deleted(ECSTagManager* this, ECSEntity* entity) 
{ 
    Remove(this->EntitiesByTag, (char*)Get(this->TagsByEntity, entity->key));
}

method void Disabled(ECSTagManager* this, ECSEntity* entity) { this->overload->Disabled(this, entity); }

method void Enabled(ECSTagManager* this, ECSEntity* entity) { this->overload->Enabled(this, entity); }

method void Register(ECSTagManager* this, char* tag, ECSEntity* e) {
    Put(this->EntitiesByTag, tag, e);
    Put(this->TagsByEntity, e->key, tag);
}

method void Unregister(ECSTagManager* this, char* tag) {
    Remove(this->TagsByEntity, ((ECSEntity*)(Get(this->EntitiesByTag, tag)))->key);
    Remove(this->EntitiesByTag, tag);
}

method bool IsRegistered(ECSTagManager* this, char* tag) {
    return Get(this->EntitiesByTag, tag) != NULL;
}

method ECSEntity* GetEntity(ECSTagManager* this, char* tag) {
    return Get(this->EntitiesByTag, tag);
}

method CFWArray* GetRegisteredTags(ECSTagManager* this) {

    CFWArray* res = cfw_new(cfw_array);
    ForEach(this->TagsByEntity, ^(void* s) {
        Add(res, s);
    });
    return res;
}
