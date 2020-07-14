#include "cfw.h"
#include "core/componenttypefactory-private.h"
#include "core/componenttypefactory.h"
#include "ecs.h"

/**
 * Contains all generated component types, newly generated component types
 * will be stored here.
 */
method void* New(ECSComponentTypeFactory* this)
{
    this->ComponentTypes = cfw_new (cfw_map, NULL);
    this->Types = cfw_new (cfw_array, NULL);
    SetTypeFactory(this);
    return this;
}

/**
 * Gets the component type for the given component class.
 * <p>
 * If no component type exists yet, a new one will be created and stored
 * for later retrieval.
 * </p>
 *
 * @param c
 *			the component's class to get the type for
*
* @return the component's {@link ComponentType}l
*/
method ECSComponentType* GetTypeFor(ECSComponentTypeFactory* this, CFWClass* c)
{

    var type = Get(this->ComponentTypes, c->name);

    if (type == NULL) {
        var index = this->ComponentTypeCount++;
        type = new (ECSComponentType, c, index);
        cfw_map_set(this->ComponentTypes, c->name, type);
        cfw_array_set(this->Types, index, type);
    }
    return type;
}

/**
 * Get the index of the component type of given component class.
 *
 * @param c
 *			the component class to get the type index for
 *
 * @return the component type's index
 */
method int GetIndexFor(ECSComponentTypeFactory* this, CFWClass* c)
{
    return GetIndex(GetTypeFor(this, c));
}
