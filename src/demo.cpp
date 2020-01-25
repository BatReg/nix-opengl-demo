#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_time.h"
#include "actor.h"
#include "mesh.h"
#include "shader.h"

#include <iostream>

core::Actor actor{};
core::Mesh mesh{};
core::Shader* shader{};

void init()
{
    std::cout << "-------- INIT --------" << '\n';
    float vertices[]
    {
        -0.50f, -0.50f, 0.0f,
         0.00f,  0.50f, 0.0f,
         0.50f, -0.50f, 0.0f
    };
    shader = new core::Shader("src/shaders/vertex.vert", "src/shaders/fragment.frag");
    mesh.setVertices(vertices, sizeof(vertices), sizeof(vertices) / sizeof(vertices[0]) / 3);
    actor.setMesh(&mesh);
    actor.setShader(shader);
}

void tick()
{
    std::cout << "-------- TICK: " << utils::GameTime::getDeltaTime() << " --------" << '\n';
    actor.draw();
}

void dispose()
{
    std::cout << "-------- DISPOSE --------" << '\n';
    delete shader;
};

void processKeyboardInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
};