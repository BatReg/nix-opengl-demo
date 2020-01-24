#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_time.h"
#include "actor.h"

#include <iostream>

core::Actor actor{};
core::Mesh mesh{};

void init()
{
    std::cout << "-------- INIT --------" << '\n';
    float vertices[]
    {
        -0.50f, -0.50f, 0.0f,
         0.00f,  0.50f, 0.0f,
         0.50f, -0.50f, 0.0f
    };
    mesh.setVertices(vertices, sizeof(vertices), sizeof(vertices) / sizeof(vertices[0]) / 3);
    actor.setMesh(&mesh);
}

void tick()
{
    std::cout << "-------- TICK: " << utils::GameTime::getDeltaTime() << " --------" << '\n';
    actor.draw();
}

void dispose()
{
    std::cout << "-------- DISPOSE --------" << '\n';
};

void processKeyboardInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
};