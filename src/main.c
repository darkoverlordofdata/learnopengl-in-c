#include <stdio.h>
#include <dna.h>
// #include "triangle.h"
#include "shmupwarz.h"
#include "cfw.h"

int main(int argc, char *argv[])
{
	RefPool *pool = cfw_new(cfw_refpool);
	Shmupwarz *game = Shmupwarz_New("Shmupwarz", 720, 480);

	Run(game);

	cfw_unref(game);
	cfw_unref(pool);

	return 0;
}

