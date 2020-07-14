#include "systems/voidentitysystem.h"
#include "cfw.h"
#include "systems/voidentitysystem-private.h"
#include "ecs.h"


/**
 * Creates an entity system that uses the specified aspect as a matcher against entities.
 * @param aspect to match against entities
 */
method void* New(ECSVoidEntitySystem* this)
{
    return this;
}

/**
 * Called before processing of entities begins. 
 */
method void Begin(ECSVoidEntitySystem* this) { this->overload->Begin(this); }

method void Process(ECSVoidEntitySystem* this)
{   
    Process(this->base);
}

/**
 * Called after the processing of entities ends.
 */
method void End(ECSVoidEntitySystem* this) { this->overload->End(this); }

/**
 * Any implementing entity system must implement this method and the logic
 * to process the given entities of the system.
 * 
 * @param entities the entities this system contains.
 */
method void ProcessEntities(ECSVoidEntitySystem* this, Array* entities) { 
    ProcessSystem(this);
}

/**
 * 
 * @return true if the system should be processed, false if not.
 */
method bool CheckProcessing(ECSVoidEntitySystem* this) { 
    return true;
}

/**
 * Override to implement code that gets executed when systems are initialized.
 */
method void Initialize(ECSVoidEntitySystem* this) { this->overload->Initialize(this); }

/**
 * Called if the system has received a entity it is interested in, e.g. created or a component was added to it.
 * @param e the entity that was added to this system.
 */
method void Inserted(ECSVoidEntitySystem* this, ECSEntity* e) { 
    this->overload->Inserted(this, e); 
}

/**
 * Called if a entity was removed from this system, e.g. deleted or had one of it's components removed.
 * @param e the entity that was removed from this system.
 */
method void Removed(ECSVoidEntitySystem* this, ECSEntity* e) { 
    this->overload->Removed(this, e); 
}

/**
 * Will Check if the entity is of interest to this system.
 * @param e entity to Check
 */
method void Check(ECSVoidEntitySystem* this, ECSEntity* e) { 
    Check(this->base, e);
}

method void RemoveFromSystem(ECSVoidEntitySystem* this, ECSEntity* e) 
{
    RemoveFromSystem(this->base, e);
}

method void InsertToSystem(ECSVoidEntitySystem* this, ECSEntity* e) 
{
    InsertToSystem(this->base, e);
}

method void Added(ECSVoidEntitySystem* this, ECSEntity* entity) { }

method void Changed(ECSVoidEntitySystem* this, ECSEntity* e) {
    Check(this, e);
}

method void Deleted(ECSVoidEntitySystem* this, ECSEntity* e) {
    Deleted(this->base, e);
}

method void Disabled(ECSVoidEntitySystem* this, ECSEntity* e) {
    Disabled(this->base, e);
}

method void Enabled(ECSVoidEntitySystem* this, ECSEntity* e) {
    Enabled(this->base, e);
}

method void SetWorld(ECSVoidEntitySystem* this, ECSWorld* world) {
    SetWorld(this->base, world);
}

method bool IsPassive(ECSVoidEntitySystem* this) {
    return IsPassive(this->base);
}

method void SetPassive(ECSVoidEntitySystem* this, bool passive) {
    SetPassive(this->base, passive);
}

method Array* GetActive(ECSVoidEntitySystem* this) {
    return GetActive(this);
}

method void ProcessSystem(ECSVoidEntitySystem* this) { 
    this->overload->ProcessSystem(this); 
    
}
