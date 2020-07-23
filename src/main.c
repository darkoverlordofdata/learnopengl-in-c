#include <stdio.h>
#include <dna.h>
// #include "triangle.h"
#include "shmupwarz.h"
#include "shmupwarz-private.h"
#include "cfw.h"

int main(int argc, char *argv[])
{

	CFWRefPool *pool = cfw_new(cfw_refpool);

	Run((Shmupwarz *)new(Shmupwarz, "Shmupwarz", 720, 480));

	// Shmupwarz *game = new(Shmupwarz, "Shmupwarz", 720, 480);

	// Run(game);

	// cfw_unref(game);
	cfw_unref(pool);

	return 0;
}

