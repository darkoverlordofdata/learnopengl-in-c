#include "unit.h"
#include "cfw.h"


#include "oop/animal.h"
#include "oop/cat.h"
#include "oop/dog.h"

int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);

    Animal* a = new(Cat, "Frodo");
    Animal* b = new(Dog, "Fido");

    Describe("Properties", ^{ 
        It("name is Frodo", ^{ 
            Expect(0 == strcmp(ToString(a->name), "Frodo"));
        });

        It("class name is Cat", ^{ 
            Expect(0 == strcmp(a->obj.cls->name, "Cat"));
        });

        It("name is Fido", ^{ 
            Expect(0 == strcmp(ToString(b->name), "Fido"));
        });

        It("class name is Dog", ^{ 
            Expect(0 == strcmp(b->obj.cls->name, "Dog"));
        });
    });

    Describe("Polymorphic behaviour", ^{ 
        It("Frodo is a Cat", ^{
            Expect(0 == strcmp(cstr(Talk(a)), "(Frodo: Cat)"));
        });

        It("Fido is a Dog", ^{
            Expect(0 == strcmp(cstr(Talk(b)), "(Fido: Dog)"));
        });

    });

    // Cat* a1 = (Cat*)a;
    // Dog* b1 = (Dog*)b;

    // printf("Eat(a1) = %s", cstr(Eat(a1)));
    // printf("Eat(b1) = %s", cstr(Eat(b1)));

    cfw_unref(pool);
	exit(tests.failed);

}