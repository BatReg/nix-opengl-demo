#ifndef ACTOR
#define ACTOR

#include "mesh.h"
#include "shader.h"

namespace core
{
    class Actor
    {
    private:
        Mesh* m_mesh;
        Shader* m_shader;

    public:
        Actor();
        Actor(Mesh* mesh, Shader* shader);

        void setMesh(Mesh* mesh);
        void setShader(Shader* shader);
        void draw();
    };
}

#endif