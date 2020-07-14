#include "core/entitysystem.h"
#include "cfw.h"
#include "core/aspect.h"
#include "core/entitysystem-private.h"
#include "ecs.h"

// method bool CheckProcessing(ECSEntitySystem* this);
/**
 * Used to generate a unique bit for each system.
 * Only used internally in EntitySystem.
 */

method int GetIndexFor(CFWObject es)
{
    static bool first = true;
    if (first) {
        first = false;
        ECSSystemIndexManager.Index = 0;
        ECSSystemIndexManager.Indices = cfw_new(cfw_map, NULL);
    }

    var index = 0;
    if (cfw_map_get(ECSSystemIndexManager.Indices, es.cls.name) == NULL) {
        index = ECSSystemIndexManager.Index++;
        cfw_map_set(ECSSystemIndexManager.Indices, es.cls.name, cfw_new(cfw_int, index));
    } else {
        index = cfw_int_value(cfw_map_get(ECSSystemIndexManager.Indices, es.cls.name));
    }
    return index;
}

/**
 * Creates an entity system that uses the specified aspect as a matcher against entities.
 * @param aspect to match against entities
 */
method void* New(ECSEntitySystem* this, ECSAspect* aspect)
{
    this->Actives = cfw_new(cfw_array, NULL);
    this->Aspect = aspect;
    this->SystemIndex = GetIndexFor(this->obj);
    this->AllSet = GetAllSet(this->Aspect);
    this->AllSet = GetExclusionSet(this->Aspect);
    this->AllSet = GetOneSet(this->Aspect);
    this->IsDummy = IsEmpty(this->AllSet) && IsEmpty(this->OneSet);
    return this;
}

/**
 * Called before processing of entities begins. 
 */
method void Begin(ECSEntitySystem* this) { this->override->Begin(this); }

method void Process(ECSEntitySystem* this)
{
    if (CheckProcessing(this)) {
        Begin(this);
        ProcessEntities(this, this->Actives);
        End(this);
    }
}

/**
 * Called after the processing of entities ends.
 */
method void End(ECSEntitySystem* this) { this->override->End(this); }

/**
 * Any implementing entity system must implement this method and the logic
 * to process the given entities of the system.
 * 
 * @param entities the entities this system contains.
 */
method void ProcessEntities(ECSEntitySystem* this, CFWArray* entities)
{
    this->override->ProcessEntities(this->override, entities);
}

/**
 * 
 * @return true if the system should be processed, false if not.
 */
method bool CheckProcessing(ECSEntitySystem* this)
{
    return true;
}

/**
 * Override to implement code that gets executed when systems are initialized.
 */
method void Initialize(ECSEntitySystem* this) { this->override->Initialize(this); }

/**
 * Called if the system has received a entity it is interested in, e.g. created or a component was added to it.
 * @param e the entity that was added to this system.
 */
method void Inserted(ECSEntitySystem* this, ECSEntity* e)
{
    this->override->Inserted(this, e);
}

/**
 * Called if a entity was removed from this system, e.g. deleted or had one of it's components removed.
 * @param e the entity that was removed from this system.
 */
method void Removed(ECSEntitySystem* this, ECSEntity* e)
{
    this->override->Removed(this, e);
}

/**
 * Will Check if the entity is of interest to this system.
 * @param e entity to Check
 */
method void Check(ECSEntitySystem* this, ECSEntity* e)
{
    if (this->IsDummy)
        return;

    var contains = Get(GetSystemBits(e), this->SystemIndex);
    var interested = true; // possibly interested, let's try to prove it wrong.

    var componentBits = e->ComponentBits;
    // Check if the entity possesses ALL of the components defined in the aspect.
    if (!IsEmpty(this->AllSet)) {
        for (var i = NextSetBit(this->AllSet, 0); i >= 0; NextSetBit(this->AllSet, i + 1)) {
            if (!Get(componentBits, i)) {
                interested = false;
                break;
            }
        }
    }

    // Check if the entity possesses ANY of the exclusion components, if it does then the system is not interested.
    if (!IsEmpty(this->ExclusionSet) && interested) {
        interested = !Intersects(this->ExclusionSet, componentBits);
    }

    // Check if the entity possesses ANY of the components in the oneSet. If so, the system is interested.
    if (!IsEmpty(this->OneSet)) {
        interested = Intersects(this->OneSet, componentBits);
    }

    if (interested && !contains) {
        InsertToSystem(this, e);
    } else if (!interested && contains) {
        RemoveFromSystem(this, e);
    }
}

method void RemoveFromSystem(ECSEntitySystem* this, ECSEntity* e)
{
    Remove(this->Actives, e);
    Clear(e->SystemBits, this->SystemIndex);
    Removed(this, e);
}

method void InsertToSystem(ECSEntitySystem* this, ECSEntity* e)
{
    Add(this->Actives, e);
    Set(GetSystemBits(e), this->SystemIndex, true);
    Inserted(this, e);
}

method void Added(ECSEntitySystem* this, ECSEntity* entity) {}

method void Changed(ECSEntitySystem* this, ECSEntity* e)
{
    Check(this, e);
}

method void Deleted(ECSEntitySystem* this, ECSEntity* e)
{
    if (Get(GetSystemBits(e), this->SystemIndex)) {
        RemoveFromSystem(this, e);
    }
}

method void Disabled(ECSEntitySystem* this, ECSEntity* e)
{
    if (Get(GetSystemBits(e), this->SystemIndex)) {
        RemoveFromSystem(this, e);
    }
}

method void Enabled(ECSEntitySystem* this, ECSEntity* e)
{
    Check(this, e);
}

method void SetWorld(ECSEntitySystem* this, ECSWorld* world)
{
    this->World = world;
}

method bool IsPassive(ECSEntitySystem* this)
{
    return this->Passive;
}

method void SetPassive(ECSEntitySystem* this, bool passive)
{
    this->Passive = passive;
}

method CFWArray* GetActive(ECSEntitySystem* this)
{
    return this->Actives;
}