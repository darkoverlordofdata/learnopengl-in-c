#pragma once

static inline void test_bitvector()
{

	CFWBitVector* b = new(CFWBitVector, 16);
	Set(b, 0, true);
	Set(b, 8, true);

    Describe("CFWBitVector Tests", ^{

        It("Should: be 0 set:", ^{
			Expect(Get(b, 0) == true);
        });
		
        It("Should: be 8 set:", ^{
			Expect(Get(b, 8) == true);
        });

	});

}