#include <stdio.h>
#include <dna.h>
// #include "triangle.h"
#include "shmupwarz.h"
#include "shmupwarz-private.h"
#include "cfw.h"
#include "../tests/tests.h"

int main(int argc, char *argv[])
{
	RefPool *pool = cfw_new(cfw_refpool);

	Shmupwarz *game = Shmupwarz_New("Shmupwarz", 720, 480);

	run_tests();
	Run(game);

	cfw_unref(game);
	cfw_unref(pool);

	return 0;
}

