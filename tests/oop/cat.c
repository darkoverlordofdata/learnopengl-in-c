#include "cat.h"
/**
 * Create new game
 */
static bool ctor(void* self, va_list args) { return true; }
static bool equal(void* ptr1, void* ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void* self) { return (uint32_t)self; }
static void* copy(void* self) { return NULL; }
static void dtor(void* self) {}

corefw(Cat);

#define super Animal

method void* New(Cat* this, char* name)
{
    static IAnimal vtable = {
        .Talk = abstract(Cat, Talk)
    };
    this->vptr = &vtable;
    Initialize(this, name);
    return this;
}
method void Initialize(Cat* this, char* name)
{
    this->name = cfw_new(cfw_string, name);
}
method void* Talk(Cat* this)
{
	var str = cfw_create(cfw_string, (void*)NULL);
    
	CFWRefPool *pool = cfw_new(cfw_refpool);
    var array = cfw_create(cfw_array,
	    cfw_create(cfw_string, "("),
	    cfw_create(cfw_string, cstr(this->name)),
	    cfw_create(cfw_string, ": Cat)"), 
        (void*)NULL);


	for (var i = 0; i < cfw_array_size(array); i++)
		cfw_string_append(str, cfw_array_get(array, i));

	cfw_unref(pool);
    return str;
}
method void* Eat(Cat* this)
{
    Eat((super*)this);
    return cfw_create(cfw_string, "Cat Eats: ");
}

#undef super
