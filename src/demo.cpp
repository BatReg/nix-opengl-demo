#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_time.h"

#include <iostream>

float           vertices[]
{
    // left side of N
    -0.50f, -0.50f, 0.0f, // left bot 0
    -0.50f,  0.50f, 0.0f, // left top 1
    -0.25f,  0.50f, 0.0f, // right top center left top 2
    -0.25f, -0.50f, 0.0f,  // right bot 3

    // center of N
     0.00f, -0.50f, 0.0f,
    -0.25f,  0.00f, 0.0f,
     0.00f,  0.00f, 0.0f,

    // right side of N
     0.00f,  0.50f, 0.0f, 
     0.25f,  0.50f, 0.0f, 
     0.25f, -0.50f, 0.0f 
};

unsigned int    indices[]
{
    0, 1, 3,
    1, 2, 3,
    2, 4, 5,
    2, 6, 4,
    4, 7, 9,
    7, 8, 9
};

unsigned int    VAO{};
unsigned int    VBO{};
unsigned int    EBO{};

void init()
{
    std::cout << "-------- INIT --------" << '\n';
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast < void*>(0));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);    

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void tick()
{
    std::cout << "-------- TICK: " << utils::GameTime::getDeltaTime() << " --------" << '\n';
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void dispose()
{
    std::cout << "-------- DISPOSE --------" << '\n';
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
};

void processKeyboardInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
};