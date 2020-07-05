#include <stdio.h>
#include <string.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "object.h"
#include "dna.h"


/**
 *  class DNAArrayRenderer
 */
struct DNAArrayRenderer 
{
	CFWObject obj;
    struct DNAShader* shader; 
    GLuint VBO;
    GLuint VAO;
};

