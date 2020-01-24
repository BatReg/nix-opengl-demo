#ifndef MESH
#define MESH

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
        Mesh(float vertices[], unsigned int verticesSize, unsigned int verticesNumber);

        ~Mesh();

        void setVertices(float vertices[], unsigned int verticesSize, unsigned int verticesNumber);
        void draw();

    private:
        void dispose();
    };
}
#endif