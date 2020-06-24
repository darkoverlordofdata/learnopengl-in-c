#include <stdio.h>
#include <corefw/refpool.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <dna.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	const CFWRefPool *pool = cfw_new(cfw_refpool);
    const DNAResourceManager *rm = DNA_ResourceManager();

    printf("Hello, world!\n");
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    const GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // load and create a texture                                                                                                                              
    // -------------------------
    const CFWString* path1 = DNA_FileSystem.getPath("data/images/background.png");
    const DNATexture2D* bg = DNA_ResourceManagerLoadTexture(rm, cfw_string_c(path1), true, "bg");

    const CFWString* path2 = DNA_FileSystem.getPath("data/images/spaceshipspr.png");
    const DNATexture2D* ss = DNA_ResourceManagerLoadTexture(rm, cfw_string_c(path2), true, "ss");

    const Mat projection = glm_ortho(0.0f, (float)WIDTH, (float)HEIGHT, 0.0f, -1.0f, 1.0f);

    // build and compile our shader program
    // ------------------------------------
    const DNAShader* shader = DNA_Shader("elementrender.vs", "elementrender.fs");
    const DNAElementRenderer* render = DNA_ElementRenderer(shader);

    DNA_ShaderUse(shader);
    DNA_ShaderSetInteger(shader, "image", 0, true);
    DNA_ShaderSetMatrix(shader, "projection", &projection, true);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        // processInput(window);
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        DNA_ElementRendererDraw(render, bg, 
                (DNARect){ WIDTH/2, HEIGHT/2, WIDTH, HEIGHT }, 
                0.0f, 
                (Vec3){ 0, 0, 0 });

        DNA_ElementRendererDraw(render, ss,
                (DNARect){ 100, 100, 108, 172 }, 
                0.0f, 
                (Vec3){ 0, 0, 0 });

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
	cfw_unref(render);
	cfw_unref(shader);
	cfw_unref(rm);
    cfw_unref(ss);
    cfw_unref(bg);
	cfw_unref(pool);
    return 0;
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}