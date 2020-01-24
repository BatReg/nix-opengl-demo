#ifndef ACTOR
#define ACTOR

#include "mesh.h"

namespace core
{
    class Actor
    {
    private:
        Mesh* m_mesh;

    public:
        Actor();
        Actor(Mesh* mesh);

        void setMesh(Mesh* mesh);
        void draw();
    };
}

#endif