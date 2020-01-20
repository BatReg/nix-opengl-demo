#ifndef ACTOR
#define ACTOR

namespace core
{
    class Actor
    {
    private:
        unsigned int m_vao;
        unsigned int m_vbo;
        unsigned int m_triangles;

    public:
        Actor();
        Actor(float vertices[], unsigned int verticesSize, unsigned int triangles);

        ~Actor();

        void draw();
        void dispose();
    };
}

#endif