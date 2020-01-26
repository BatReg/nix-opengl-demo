#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "game_time.h"
#include "actor.h"
#include "mesh.h"
#include "shader.h"

#include <iostream>
#include <math.h>

core::Actor     actor{};
core::Mesh      mesh{};
core::Shader*   shader{};

void init()
{
    std::cout << "-------- INIT --------" << '\n';
    float vertices[]
    {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f
    };
    shader = new core::Shader("src/shaders/vertex.vert", "src/shaders/fragment.frag");
    shader->setColor(glm::vec4{ 0.98, 0.55, 0.0, 1.0 });
    mesh.setVertices(vertices, sizeof(vertices), sizeof(vertices) / sizeof(vertices[0]) / 3);
    actor.setMesh(&mesh);
    actor.setShader(shader);
    actor.setPosition(glm::vec3{ 0.5f, -0.5f, 0.0f });    
}

void tick()
{
    std::cout << "-------- TICK: " << utils::GameTime::getDeltaTime() << " --------" << '\n';
    glm::vec3 actorRotation = actor.getRotation();
    actorRotation.z += utils::GameTime::getDeltaTime() * 50.0f;
    actor.setRotation(actorRotation);
    float scale = static_cast<float>(sin(utils::GameTime::getCurrentTime() * 1.5f) + 1.0f) / 2.0f;
    actor.setScale(glm::vec3{ scale, scale, 0.5f });
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