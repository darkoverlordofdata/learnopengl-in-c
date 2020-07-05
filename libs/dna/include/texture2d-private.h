#include <stdio.h>
#include <string.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "dna.h"
#include "object.h"

/**
 *  object DNATexture2D
 */
struct DNATexture2D {
	CFWObject obj;          // CoreFW interface
    GLuint Id;              // Holds the ID of the texture object, used for all texture operations to reference to self particlar texture
    GLuint Width, Height;   // Width and height of loaded image in pixels
    GLuint InternalFormat;  // Format of texture object
    GLuint ImageFormat;     // Format of loaded image
    GLuint wrapS;           // Wrapping mode on S axis
    GLuint wrapT;           // Wrapping mode on T axis
    GLuint filterMin;       // Filtering mode if texture pixels < screen pixels
    GLuint filterMag;       // Filtering mode if texture pixels > screen pixels
    char* path;
};

