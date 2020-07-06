#include <stdio.h>
#include <dna.h>
#include "shmupwarz.h"

int main(int argc, char *argv[])
{
	CFWRefPool *pool = cfw_new(cfw_refpool);
	Shmupwarz *game = Shmupwarz_New("Shmupwarz", 720, 480);

	printf("hash = %x\n", cfw_hash(game));

	Shmupwarz_Run(game);

	cfw_unref(game);
	cfw_unref(pool);

	return 0;
}

