#ifndef MESH
#define MESH

#include <vector>

namespace core
{
    inline constexpr unsigned int NULL_BUFFER_IDX = 0;

    class Mesh
    {
    private:
        unsigned int m_vao;
        unsigned int m_vbo;
        unsigned int m_vertices;

    public:
        Mesh();

        ~Mesh();

        void setVertices(std::vector<float> vertices);
        void draw();

    private:
        void dispose();
    };
}
#endif