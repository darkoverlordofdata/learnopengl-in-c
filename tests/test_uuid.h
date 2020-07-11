#pragma once

static inline void test_uuid()
{

	UUID* uid = UUID_New();

    Describe("Run Tests", ^{

        It("Should: len is 36", ^{
			printf("uid = %s\n", ToString(uid));
			Expect(strlen(ToString(uid)) == 36);
        });
		

	});

}