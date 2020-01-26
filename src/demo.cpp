#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "game_time.h"
#include "actor.h"
#include "mesh.h"
#include "shader.h"

#include <iostream>
#include <cmath>

core::Actor     actor{};
core::Mesh      mesh{};
core::Shader*   shader{};
core::Actor     actor2{};
core::Shader* shader2{};

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

    shader2 = new core::Shader("src/shaders/vertex.vert", "src/shaders/fragment.frag");
    shader2->setColor(glm::vec4{ 0.65, 0.84, 0.65, 1.0 });

    mesh.setVertices(vertices, sizeof(vertices), sizeof(vertices) / sizeof(vertices[0]) / 3);

    actor.setMesh(&mesh);
    actor.setShader(shader);
    actor.setPosition(glm::vec3{ 0.5f, -0.5f, 0.0f });

    actor2.setMesh(&mesh);
    actor2.setShader(shader2);
    actor2.setPosition(glm::vec3{ -0.5f, 0.5f, 0.0f });
}

void tick()
{
    std::cout << "-------- TICK: " << utils::GameTime::getDeltaTime() << " --------" << '\n';

    glm::vec3 actorRotation = actor.getRotation();
    actorRotation.z += utils::GameTime::getDeltaTime() * 50.0f;
    actor.setRotation(actorRotation);
    actor.draw();

    float scale = static_cast<float>(sin(utils::GameTime::getCurrentTime() * 1.5f) + 1.0f) / 2.0f;
    actor2.setScale(glm::vec3{ scale, scale, 0.5f });
    actor2.draw();
    
}

void dispose()
{
    std::cout << "-------- DISPOSE --------" << '\n';
    delete shader;
    delete shader2;
};

void processKeyboardInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
};