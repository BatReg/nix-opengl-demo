#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include "time.h"

#include <iostream>

void init()
{
    std::cout << "-------- INIT --------" << '\n';
}

void tick()
{
    std::cout << "-------- TICK: " << utils::Time::getDeltaTime() << " --------" << '\n';
}

void terminate()
{
    std::cout << "-------- TERMINATE --------" << '\n';
};

void processKeyboardInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
};