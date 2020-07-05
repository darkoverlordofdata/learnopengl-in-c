#include <stdio.h>
#include <string.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "object.h"
#include "dna.h"

/**
 *  class DNAResourceManager
 */
struct DNAResourceManager {
	CFWObject obj;
    CFWMap* Shaders;
    CFWMap* Textures;
    CFWMap* Fonts;
};

