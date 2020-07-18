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

	CFWUuid* uid = new(CFWUuid);

    Describe("CFWUuid Tests", ^{

        It("Should: length be 36 0\n", ^{
			Expect(strlen(ToString(uid)) == 36);
        });
	});

    cfw_unref(pool);


}