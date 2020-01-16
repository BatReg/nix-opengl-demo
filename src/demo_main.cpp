#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include "settings.h"
#include "time.h";

#include <iostream>

void init();
void tick();
void terminate();
void processKeyboardInput(GLFWwindow* window);

static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(Settings::SCREEN_WIDTH, Settings::SCRREN_HEIGHT, "N-iX OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    init();

    
    utils::Time time(glfwGetTime());
    while (!glfwWindowShouldClose(window)) 
    {
        // Update delta time
        // -----------------
        time.UpdateTime(glfwGetTime());

        // Get input
        // ---------
        processKeyboardInput(window);

        // Update
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        tick();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    terminate();
    glfwTerminate();

    return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebufferSizeCallback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}
