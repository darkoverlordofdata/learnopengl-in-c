#pragma once

static inline void test_random()
{

	CFWRandom* rnd = new(CFWRandom);

	unsigned long l = NextLong();
	double d = NextDouble();

    Describe("CFWRandom Tests", ^{

        It("Should: be not 0", ^{
			printf("l = %lu\n", l);
			Expect(l != 0);
        });
		
        It("Should: be not 0.0f", ^{
			printf("d = %f\n", d);
			Expect(d != 0.0f);
        });

	});

}