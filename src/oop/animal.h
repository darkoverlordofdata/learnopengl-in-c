#pragma once
#include <stdio.h>
#include "cfw.h"

typedef struct IAnimal IAnimal;
typedef struct Animal Animal;
extern const CFWClass *AnimalClass;

struct IAnimal {
    void(*Talk)(void* this);
};

struct IAnimal;
struct Animal {
    CFWObject obj;
    struct IAnimal* vptr;
    CFWString* name;

};

extern method void* New(Animal* this, IAnimal* vptr);
extern method void Initialize(Animal* this);
extern method void Talk(Animal* this);
extern method void Eat(Animal* this);

