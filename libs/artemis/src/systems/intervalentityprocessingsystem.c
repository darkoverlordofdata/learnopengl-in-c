#include "systems/entityprocessingsystem.h"
#include "cfw.h"
#include "systems/entityprocessingsystem-private.h"
#include "ecs.h"


/**
 * Creates an entity system that uses the specified aspect as a matcher against entities.
 * @param aspect to match against entities
 */
method void* New(ECSIntervalEntityProcessingSystem* self, ECSAspect* aspect, float interval)
{
    return self;
}

/**
 * Called before processing of entities begins. 
 */
method void Begin(ECSIntervalEntityProcessingSystem* self) { virtual(ECSIntervalEntityProcessingSystem)->Begin(self); }

method void Process(ECSIntervalEntityProcessingSystem* self)
{   
    Process(self->base);
}

/**
 * Called after the processing of entities ends.
 */
method void End(ECSIntervalEntityProcessingSystem* self) { virtual(ECSIntervalEntityProcessingSystem)->End(self); }

/**
 * Any implementing entity system must implement this method and the logic
 * to process the given entities of the system.
 * 
 * @param entities the entities this system contains.
 */
method void ProcessEntities(ECSIntervalEntityProcessingSystem* self, Array* entities) { 
    for (var i=0; i<entities->length; i++) {
        ProcessEach(self, Get(entities, i));
    } 
}

/**
 * 
 * @return true if the system should be processed, false if not.
 */
method bool CheckProcessing(ECSIntervalEntityProcessingSystem* self) { 
    if ((self->Acc += GetDelta(self->World)) >= self->Interval) {
        self->Acc -= self->Interval;
        return true;
    }
    return false;
}

/**
 * Override to implement code that gets executed when systems are initialized.
 */
method void Initialize(ECSIntervalEntityProcessingSystem* self) { virtual(ECSIntervalEntityProcessingSystem)->Initialize(self); }

/**
 * Called if the system has received a entity it is interested in, e.g. created or a component was added to it.
 * @param e the entity that was added to this system.
 */
method void Inserted(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) { 
    virtual(ECSIntervalEntityProcessingSystem)->Inserted(self, e); 
}

/**
 * Called if a entity was removed from this system, e.g. deleted or had one of it's components removed.
 * @param e the entity that was removed from this system.
 */
method void Removed(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) { 
    virtual(ECSIntervalEntityProcessingSystem)->Removed(self, e); 
}

/**
 * Will Check if the entity is of interest to this system.
 * @param e entity to Check
 */
method void Check(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) { 
    Check(self->base, e);
}

method void RemoveFromSystem(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) 
{
    RemoveFromSystem(self->base, e);
}

method void InsertToSystem(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) 
{
    InsertToSystem(self->base, e);
}

method void Added(ECSIntervalEntityProcessingSystem* self, ECSEntity* entity) { }

method void Changed(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) {
    Check(self, e);
}

method void Deleted(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) {
    Deleted(self->base, e);
}

method void Disabled(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) {
    Disabled(self->base, e);
}

method void Enabled(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) {
    Enabled(self->base, e);
}

method void SetWorld(ECSIntervalEntityProcessingSystem* self, ECSWorld* world) {
    SetWorld(self->base, world);
}

method bool IsPassive(ECSIntervalEntityProcessingSystem* self) {
    return IsPassive(self->base);
}

method void SetPassive(ECSIntervalEntityProcessingSystem* self, bool passive) {
    SetPassive(self->base, passive);
}

method Array* GetActive(ECSIntervalEntityProcessingSystem* self) {
    return GetActive(self);
}

/**
 * Process a entity this system is interested in.
 * @param e the entity to process.
 */
method void ProcessEach(ECSIntervalEntityProcessingSystem* self, ECSEntity* e) { 
    virtual(ECSIntervalEntityProcessingSystem)->ProcessEach(self, e); 
}

