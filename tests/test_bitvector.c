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

	CFWBitVector* b = new(CFWBitVector, 16);
	Set(b, 0, true);
	Set(b, 8, true);

    Describe("CFWBitVector Tests", ^{

        It("Should: 0 be set\n", ^{
			// printf("l = %lu\n", l);
			Expect(Get(b, 0) == true);
        });

        It("Should: 8 be set\n", ^{
			// printf("l = %lu\n", l);
			Expect(Get(b, 8) == true);
        });

	});

    cfw_unref(pool);

}