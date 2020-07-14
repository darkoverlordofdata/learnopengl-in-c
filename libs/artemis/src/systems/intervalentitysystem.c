#include "systems/intervalentitysystem.h"
#include "cfw.h"
#include "systems/intervalentitysystem-private.h"
#include "ecs.h"
/**
 * Creates an entity system that uses the specified aspect as a matcher against entities.
 * @param aspect to match against entities
 */
method void* New(ECSIntervalEntitySystem* this, ECSAspect* aspect, float interval)
{
    this->Acc = 0;
    this->Interval = interval;
    return this;
}

/**
 * Called before processing of entities begins. 
 */
method void Begin(ECSIntervalEntitySystem* this) { this->overload->Begin(this); }

method void Process(ECSIntervalEntitySystem* this)
{   
    Process(this->overload);
}

/**
 * Called after the processing of entities ends.
 */
method void End(ECSIntervalEntitySystem* this) { this->overload->End(this); }

/**
 * Any implementing entity system must implement this method and the logic
 * to process the given entities of the system.
 * 
 * @param entities the entities this system contains.
 */
method void ProcessEntities(ECSIntervalEntitySystem* this, Array* entities) { 
    this->overload->ProcessEntities(this, entities); 
}

/**
 * 
 * @return true if the system should be processed, false if not.
 */
method bool CheckProcessing(ECSIntervalEntitySystem* this) { 
    if ((this->Acc += GetDelta(this->World)) >= this->Interval) {
        this->Acc -= this->Interval;
        return true;
    }
    return false;
}

/**
 * Override to implement code that gets executed when systems are initialized.
 */
method void Initialize(ECSIntervalEntitySystem* this) { this->overload->Initialize(this); }

/**
 * Called if the system has received a entity it is interested in, e.g. created or a component was added to it.
 * @param e the entity that was added to this system.
 */
method void Inserted(ECSIntervalEntitySystem* this, ECSEntity* e) { 
    this->overload->Inserted(this, e); 
}

/**
 * Called if a entity was removed from this system, e.g. deleted or had one of it's components removed.
 * @param e the entity that was removed from this system.
 */
method void Removed(ECSIntervalEntitySystem* this, ECSEntity* e) { 
    this->overload->Removed(this, e); 
}

/**
 * Will Check if the entity is of interest to this system.
 * @param e entity to Check
 */
method void Check(ECSIntervalEntitySystem* this, ECSEntity* e) { 
    Check(this->overload, e);
}

method void RemoveFromSystem(ECSIntervalEntitySystem* this, ECSEntity* e) 
{
    RemoveFromSystem(this->overload, e);
}

method void InsertToSystem(ECSIntervalEntitySystem* this, ECSEntity* e) 
{
    InsertToSystem(this->overload, e);
}

method void Added(ECSIntervalEntitySystem* this, ECSEntity* entity) { }

method void Changed(ECSIntervalEntitySystem* this, ECSEntity* e) {
    Check(this, e);
}

method void Deleted(ECSIntervalEntitySystem* this, ECSEntity* e) {
    Deleted(this->overload, e);
}

method void Disabled(ECSIntervalEntitySystem* this, ECSEntity* e) {
    Disabled(this->overload, e);
}

method void Enabled(ECSIntervalEntitySystem* this, ECSEntity* e) {
    Enabled(this->overload, e);
}

method void SetWorld(ECSIntervalEntitySystem* this, ECSWorld* world) {
    SetWorld(this->overload, world);
}

method bool IsPassive(ECSIntervalEntitySystem* this) {
    return IsPassive(this->overload);
}

method void SetPassive(ECSIntervalEntitySystem* this, bool passive) {
    SetPassive(this->overload, passive);
}

method Array* GetActive(ECSIntervalEntitySystem* this) {
    return GetActive(this);
}

