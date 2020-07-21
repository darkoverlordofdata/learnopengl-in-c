#include "unit.h"
#include "cfw.h"

int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);

    var index = cfw_create(cfw_int, 10);

    var array = cfw_create(cfw_array,
	    cfw_create(cfw_string, "this"),
	    cfw_create(cfw_string, " is"),
	    cfw_create(cfw_string, " a"), 
	    cfw_create(cfw_string, " test"), 
        (void*)NULL);

	var str = cfw_create(cfw_string, (void*)NULL);

	for (var i = 0; i < cfw_array_size(array); i++)
		cfw_string_append(str, cfw_array_get(array, i));

    // var table = cfw_create(cfw_map,
    //     cfw_create(cfw_string, "a"), cfw_create(cfw_int, 4),
    //     cfw_create(cfw_string, "b"), cfw_create(cfw_int, 2),
    //     cfw_create(cfw_string, "c"), cfw_create(cfw_int, 0),
    //     (void*)NULL);

    // ForEach(table, ^(void* k, void* i) {
    //     printf("ForEach: %s = %ji\n", cfw_string_c(k), cfw_int_value(i));
    // });


    Describe("Base CFW Tests", ^{

        It("value is 10", ^{
			Expect(cfw_int_value(index) == 10);
        });

        It("string length is > 0", ^{
			Expect(cfw_string_length(str) > 0);
        });
    });

    cfw_unref(pool);
	exit(tests.failed);

}