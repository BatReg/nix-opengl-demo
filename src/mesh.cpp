#include "mesh.h"

#include <glad/glad.h>

namespace core
{
    Mesh::Mesh() : m_vao{ NULL_BUFFER_IDX }, m_vbo{ NULL_BUFFER_IDX }, m_vertices{ 0 }
    {
    }

    Mesh::~Mesh()
    {
        dispose();
    }

    void Mesh::setVertices(std::vector<float> vertices)
    {
        dispose();

        m_vertices = vertices.size() / 3;

        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);

        glBindVertexArray(m_vao);

        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void*>(0));
        glEnableVertexAttribArray(0);

        glBindVertexArray(NULL_BUFFER_IDX);
        glBindBuffer(GL_ARRAY_BUFFER, NULL_BUFFER_IDX);
    }

    void Mesh::draw()
    {
        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, m_vertices);
        glBindVertexArray(NULL_BUFFER_IDX);
    }

    void Mesh::dispose()
    {
        glDeleteVertexArrays(1, &m_vao);
        glDeleteBuffers(1, &m_vbo);

        m_vao = m_vbo = NULL_BUFFER_IDX;
        m_vertices = 0;
    }
}
