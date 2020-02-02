#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "game_time.h"
#include "actor.h"
#include "mesh.h"
#include "shader.h"

#include <iostream>
#include <vector>

constexpr glm::vec4 GREEN_COLOR{ 0.65, 0.84, 0.65, 1.0 };
constexpr glm::vec4 ORANGE_COLOR{ 0.98, 0.55, 0.0, 1.0 };

core::Actor     actor{};
core::Mesh      mesh{};
core::Shader*   shader{};

core::Actor     actor2{};

void init()
{
    std::cout << "-------- INIT --------" << '\n';
    std::vector<float> vertices
    {
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };
    shader = new core::Shader("src/shaders/vertex.vert", "src/shaders/fragment.frag");

    mesh.setVertices(vertices);

    actor.setMesh(&mesh);
    actor.setShader(shader);
    actor.setPosition(glm::vec3{ 0.5f, -0.5f, 0.0f });
    actor.setColor(ORANGE_COLOR);

    actor2.setMesh(&mesh);
    actor2.setShader(shader);
    actor2.setPosition(glm::vec3{ -0.5f, 0.5f, 0.0f });
    actor2.setColor(GREEN_COLOR);
}

void tick()
{
    std::cout << "-------- TICK: " << utils::GameTime::getDeltaTime() << " --------" << '\n';

    glm::vec3 actorRotation = actor.getRotation();
    actorRotation.z += utils::GameTime::getDeltaTime() * 75.0f;
    actor.setRotation(actorRotation);
    actor.draw();

    float scale = static_cast<float>(sin(utils::GameTime::getCurrentTime() * 3.0f) + 1.0f) / 2.0f;
    actor2.setScale(glm::vec3{ scale, scale, 0.5f });
    actor2.draw();
    
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

    std::vector<float> vertices
    {
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    unsigned int VBO;
    unsigned int VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void*>(0));
    glEnableVertexAttribArray(0);
};