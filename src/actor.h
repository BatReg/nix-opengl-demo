#ifndef ACTOR
#define ACTOR

namespace core
{
    class Actor
    {
    private:
        unsigned int m_vao;
        unsigned int m_vbo;
        unsigned int m_vertices;

    public:
        Actor();
        Actor(float vertices[], unsigned int verticesSize, unsigned int verticesNumber);

        ~Actor();

        void draw();
    };
}

#endif