#pragma once

static inline void test_cfw()
{

    var index = cfw_create(cfw_int, 10);

    var array = cfw_create(cfw_array,
	    cfw_create(cfw_string, "this"),
	    cfw_create(cfw_string, " is"),
	    cfw_create(cfw_string, " a"), 
	    cfw_create(cfw_string, " test"), 
        (void*)NULL);

	var str = cfw_create(cfw_string, (void*)NULL);

    var table = cfw_create(cfw_map,
        cfw_create(cfw_string, "a"), cfw_create(cfw_int, 4),
        cfw_create(cfw_string, "b"), cfw_create(cfw_int, 2),
        cfw_create(cfw_string, "c"), cfw_create(cfw_int, 0),
        (void*)NULL);

	for (var i = 0; i < cfw_array_size(array); i++)
		cfw_string_append(str, cfw_array_get(array, i));

    ForEach(table, ^(void* k, void* i) {
        printf("ForEach: %s = %i\n", cfw_string_c(k), cfw_int_value(i));

    });


    Describe("CFW Tests", ^{

        It("Should: value be 10", ^{
			printf("Int = %ji\n", cfw_int_value(index));
			Expect(cfw_int_value(index) == 10);
        });

        It("Should: be greater than ''", ^{
	        printf("%s\n", cfw_string_c(str));
            Expect(cfw_string_length(str) > 0);
        });

		

	});

}