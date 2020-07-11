#pragma once

static inline void test_random()
{

	Random* rnd = Random_New(time(NULL));

	unsigned long l = NextLong();
	double d = NextDouble();

    Describe("Run Tests", ^{

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