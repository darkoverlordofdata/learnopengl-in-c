#include <stdio.h>
#include <dna.h>
#include "triangle.h"

int main(int argc, char *argv[])
{

	printf("main:1\n");
	CFWRefPool *pool = cfw_new(cfw_refpool);
	printf("main:2\n");
	Triangle *game = Triangle_New("Triangle", 720, 480);
	printf("main:3\n");

	printf("hash = %x\n", cfw_hash(game));

	Triangle_Run(game);

	cfw_unref(game);
	cfw_unref(pool);

	return 0;
}

