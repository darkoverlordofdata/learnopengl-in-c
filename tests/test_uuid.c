#include "unit.h"
#include "cfw.h"

int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);

	CFWUuid* uid = new(CFWUuid);

    Describe("CFWUuid Tests", ^{

        It("string length is 36", ^{
			Expect(strlen(ToString(uid)) == 36);
        });
	});

    cfw_unref(pool);
	exit(tests.failed);
}