#include "actor.h"

#include <glad/glad.h>

namespace core
{
    inline constexpr unsigned int DEFAULT_BUFFER_PTR = 0;

    Actor::Actor()
    {
        m_vao       = DEFAULT_BUFFER_PTR;
        m_vbo       = DEFAULT_BUFFER_PTR;
        m_vertices  = 0;
    }

    Actor::Actor(float vertices[], unsigned int verticesSize, unsigned int verticesNumber)
    {
        m_vao = 0;
        m_vbo = 0;
        m_vertices = verticesNumber;

        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);

        glBindVertexArray(m_vao);

        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void*>(0));
        glEnableVertexAttribArray(0);

        glBindVertexArray(DEFAULT_BUFFER_PTR);
        glBindBuffer(GL_ARRAY_BUFFER, DEFAULT_BUFFER_PTR);
    }

    Actor::~Actor()
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);

        m_vao = m_vbo = DEFAULT_BUFFER_PTR;
    }

    void Actor::draw()
    {
        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, m_vertices);
        glBindVertexArray(DEFAULT_BUFFER_PTR);
    }
}
