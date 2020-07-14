#include "cfw.h"

// Initialize((EcsManager*)cfw_map_get(this->ManagersBag, i));

method void* Get(CFWArray* this, int i)
{
    return cfw_array_get(this, i);
}

method void* Get(CFWMap* this, char* key)
{
    return cfw_map_get(this, key);
}

method void Add(CFWArray* this, void* item)
{
    cfw_array_push(this, item);
}

method void Remove(CFWMap* this, char* key)
{
    cfw_map_set(this, key, NULL);
}

method void Put(CFWMap* this, char* key, void* object)
{
    cfw_map_set(this, key, object);
}

method void Put(CFWArray* this, int index, void* object)
{
    cfw_array_set(this, index, object);
}

// method void ForEach(CFWMap* this, void(*func)(void* item))
method void ForEach(CFWMap* this, void(*func)(void* key, void* item))
{
   cfw_map_iter_t iter;

    cfw_map_iter(this, &iter);
    while (iter.key != NULL) {
        func(iter.key, iter.obj);
        cfw_map_iter_next(&iter);
    }
}
method void ForEach(CFWMap* this, void(^func)(void* key, void* item))
{
    cfw_map_iter_t iter;

    cfw_map_iter(this, &iter);
    while (iter.key != NULL) {
        func(iter.key, iter.obj);
        cfw_map_iter_next(&iter);
    }
}
