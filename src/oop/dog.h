#pragma once
#include "animal.h"

extern const CFWClass* DogClass;

typedef struct Dog Dog;

struct Dog {
    CFWObject obj;
    IAnimal* vptr;
    CFWString* name;
};

extern method void* New(Dog* this, char* name);
extern method void Initialize(Dog* this, char* name);
extern method void Talk(Dog* this);
extern method void Eat(Dog* this);
