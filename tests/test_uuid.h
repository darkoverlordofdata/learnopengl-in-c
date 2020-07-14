#pragma once

static inline void test_uuid()
{


	CFWUuid* uid = new(CFWUuid);

    Describe("CFWUuid Tests", ^{

        It("Should: len is 36", ^{
			printf("uid = %s\n", ToString(uid));
			Expect(strlen(ToString(uid)) == 36);
        });
		

	});

}