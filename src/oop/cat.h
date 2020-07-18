#pragma once
#include "animal.h"

extern const CFWClass* CatClass;

typedef struct Cat Cat;

struct Cat {
    CFWObject obj;
    IAnimal* vptr;
    CFWString* name;
};

extern method void* New(Cat* this, char* name);
extern method void Initialize(Cat* this, char* name);
extern method void Talk(Cat* this);
extern method void Eat(Cat* this);
