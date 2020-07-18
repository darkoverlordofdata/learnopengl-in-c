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
method void Talk(Cat* this)
{
    printf("(%s): meow\n", cstr(this->name));
}
method void Eat(Cat* this)
{
    printf("Cat Eats: ");
    Eat((super*)this);
}

#undef super
