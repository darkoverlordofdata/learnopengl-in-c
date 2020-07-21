#include "animal.h"
#include <assert.h>
/**
 * Create new game
 */
static bool ctor(void* self, va_list args) { return true; }
static bool equal(void* ptr1, void* ptr2) { return ptr1 == ptr2; }
static uint32_t hash(void* self) { return (uint32_t)self; }
static void* copy(void* self) { return NULL; }
static void dtor(void* self) {}

corefw(Animal);

method void* New(Animal* this, IAnimal* vptr)
{
    this->vptr = vptr;
    return this;
}

method void* Talk(Animal* this)
{
    return this->vptr->Talk(this);
}
method void* Eat(Animal* this)
{
    return Talk(this);
}
