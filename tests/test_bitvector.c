#include "unit.h"
#include "cfw.h"

int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);

	CFWBitVector* b = new(CFWBitVector, 128);
	Set(b, 0, true);
	Set(b, 88, true);

    Describe("CFWBitVector Tests", ^{

        It("bit 0 is set", ^{
			Expect(Get(b, 0) == true);
        });

        It("bit 1 is not set", ^{
			Expect(Get(b, 1) == false);
        });

        It("bit 88 is set", ^{
			Expect(Get(b, 88) == true);
        });

	});

    cfw_unref(pool);
	exit(tests.failed);
}