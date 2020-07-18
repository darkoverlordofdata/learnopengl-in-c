#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdint.h>
#include <dna.h>
#include "unit.h"
#include "cfw.h"

int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);

	CFWRandom* rnd = new(CFWRandom);

	unsigned long l = NextLong();
	double d = NextDouble();

    Describe("CFWRandom Tests", ^{

        It("Should: be not 0\n", ^{
			// printf("l = %lu\n", l);
			Expect(l != 0);
        });
		
        It("Should: be not 0.0f\n", ^{
			// printf("d = %f\n", d);
			Expect(d != 0.0f);
        });

	});

    cfw_unref(pool);

}