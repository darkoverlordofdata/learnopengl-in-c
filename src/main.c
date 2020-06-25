#include <stdio.h>
#include <corefw/object.h>
#include <corefw/refpool.h>
#include <corefw/string.h>
#include <corefw/int.h>
#include <corefw/array.h>
#include <corefw/map.h>
#include <dna.h>
#include "shmupwarz.h"

#define var __auto_type



int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);
	// struct Shmupwarz *game = cfw_new(shmupwarz, "Shmupwarz", 720, 480);
	struct Shmupwarz *game = Shmupwarz_New("Shmupwarz", 720, 480);
	Shmupwarz_Run(game);


	cfw_unref(game);
	cfw_unref(pool);

	return 0;
}

