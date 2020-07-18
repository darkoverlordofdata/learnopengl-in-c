#include "dog.h"
/**
 * Create new game
 */
static bool ctor(void* self, va_list args) { return true; }
static bool equal(void* ptr1, void* ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void* self) { return (uint32_t)self; }
static void* copy(void* self) { return NULL; }
static void dtor(void* self) {}

corefw(Dog);

#define super Animal

method void* New(Dog* this, char* name)
{
    static IAnimal vtable = {
        .Talk = abstract(Dog, Talk)
    };
    this->vptr = &vtable;
    Initialize(this, name);
    return this;
}
method void Initialize(Dog* this, char* name)
{
    this->name = cfw_new(cfw_string, name);
}
method void Talk(Dog* this)
{
    printf("(%s): bow wow\n", cfw_string_c(this->name));
}
method void Eat(Dog* this)
{
    printf("Dog Eats: ");
    Eat((super*)this);
}
#undef super
