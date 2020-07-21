#include "unit.h"
#include "cfw.h"

int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);

	CFWRandom* rnd = new(CFWRandom);

	unsigned long l = NextLong();
	double d = NextDouble();

    Describe("CFWRandom Tests", ^{

        It("is not 0", ^{
			Expect(l != 0);
        });
		
        It("is not 0.0f", ^{
			Expect(d != 0.0f);
        });

	});

    cfw_unref(pool);
	exit(tests.failed);

}