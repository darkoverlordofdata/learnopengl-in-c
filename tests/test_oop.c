#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdint.h>
#include <dna.h>
#include "unit.h"
#include "cfw.h"


#include "../src/oop/animal.h"
#include "../src/oop/cat.h"
#include "../src/oop/dog.h"

int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);

    Animal* a = new(Cat, "Frodo");
    Animal* b = new(Dog, "Fido");

    // polymorphic behaviour

    Talk(a);
    Talk(b);

    Cat* a1 = (Cat*)a;
    Dog* b1 = (Dog*)b;

    Eat(a1);
    Eat(b1);

    cfw_unref(pool);

}