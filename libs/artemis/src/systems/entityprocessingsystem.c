#include "systems/entityprocessingsystem.h"
#include "cfw.h"
#include "systems/entityprocessingsystem-private.h"
#include "ecs.h"

/**
 * Creates an entity system that uses the specified aspect as a matcher against entities.
 * @param aspect to match against entities
 */
method ECSEntityProcessingSystem* New(ECSEntityProcessingSystem* this, ECSAspect* aspect)
{
    return this;
}

/**
 * Called before processing of entities begins. 
 */
method void Begin(ECSEntityProcessingSystem* this) { 
    this->overload->Begin(this); 
}

method void Process(ECSEntityProcessingSystem* this)
{   
    Process(this->overload);
}

/**
 * Called after the processing of entities ends.
 */
method void End(ECSEntityProcessingSystem* this) { 
    this->overload->End(this); 
}

/**
 * Any implementing entity system must implement this method and the logic
 * to process the given entities of the system.
 * 
 * @param entities the entities this system contains.
 */
method void ProcessEntities(ECSEntityProcessingSystem* this, CFWArray* entities) {
    for (var i=0; i<entities->length; i++) {
        ProcessEach(this, Get(entities, i));
    } 
}

/**
 * 
 * @return true if the system should be processed, false if not.
 */
method bool CheckProcessing(ECSEntityProcessingSystem* this) { 
    return true;
}

/**
 * Override to implement code that gets executed when systems are initialized.
 */
method void Initialize(ECSEntityProcessingSystem* this) { 
    this->overload->Initialize(this); 
}

/**
 * Called if the system has received a entity it is interested in, e.g. created or a component was added to it.
 * @param e the entity that was added to this system.
 */
method void Inserted(ECSEntityProcessingSystem* this, ECSEntity* e) { 
    this->overload->Inserted(this, e); 
}

/**
 * Called if a entity was removed from this system, e.g. deleted or had one of it's components removed.
 * @param e the entity that was removed from this system.
 */
method void Removed(ECSEntityProcessingSystem* this, ECSEntity* e) { 
    this->overload->Removed(this, e); 
}

/**
 * Will Check if the entity is of interest to this system.
 * @param e entity to Check
 */
method void Check(ECSEntityProcessingSystem* this, ECSEntity* e) { 
    Check(this->overload, e);
}

method void RemoveFromSystem(ECSEntityProcessingSystem* this, ECSEntity* e) {
    RemoveFromSystem(this->overload, e);
}

method void InsertToSystem(ECSEntityProcessingSystem* this, ECSEntity* e) {
    InsertToSystem(this->overload, e);
}

method void Added(ECSEntityProcessingSystem* this, ECSEntity* entity) { }

method void Changed(ECSEntityProcessingSystem* this, ECSEntity* e) {
    Changed(this->overload, e);
}

method void Deleted(ECSEntityProcessingSystem* this, ECSEntity* e) {
    Deleted(this->overload, e);
}

method void Disabled(ECSEntityProcessingSystem* this, ECSEntity* e) {
    Disabled(this->overload, e);
}

method void Enabled(ECSEntityProcessingSystem* this, ECSEntity* e) {
    Enabled(this->overload, e);
}

method void SetWorld(ECSEntityProcessingSystem* this, ECSWorld* world) {
    SetWorld(this->overload, world);
}

method bool IsPassive(ECSEntityProcessingSystem* this) {
    return IsPassive(this->overload);
}

method void SetPassive(ECSEntityProcessingSystem* this, bool passive) {
    SetPassive(this->overload, passive);
}

method CFWArray* GetActive(ECSEntityProcessingSystem* this) {
    return GetActive(this->overload);
}

/**
 * Process a entity this system is interested in.
 * @param e the entity to process.
 */
method void ProcessEach(ECSEntityProcessingSystem* this, ECSEntity* e) { 
    this->overload->Begin(this); 
}

