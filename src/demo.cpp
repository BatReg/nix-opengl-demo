#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <iostream>

void init() 
{
    std::cout << "-------- INIT --------" << '\n';
}

void tick() 
{
    std::cout << "-------- TICK --------" << '\n';
}

void terminate()
{
    std::cout << "-------- TERMINATE --------" << '\n';
};

void framebufferSizeCallback(GLFWwindow* window, int width, int height) 
{

};

void processKeyboardInput(GLFWwindow* window) 
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
    {
        glfwSetWindowShouldClose(window, true);
    }
};