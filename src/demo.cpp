#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_time.h"
#include "actor.h"

#include <iostream>

float           vertices[]
{
    -0.50f, -0.50f, 0.0f,
    -0.50f,  0.50f, 0.0f,
    -0.25f,  0.50f, 0.0f
};

core::Actor actor;

void init()
{
    std::cout << "-------- INIT --------" << '\n';
    actor = core::Actor(vertices, sizeof(vertices), sizeof(vertices) / 3);
}

void tick()
{
    std::cout << "-------- TICK: " << utils::GameTime::getDeltaTime() << " --------" << '\n';
    actor.draw();
}

void dispose()
{
    std::cout << "-------- DISPOSE --------" << '\n';
    actor.dispose();
};

void processKeyboardInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
};