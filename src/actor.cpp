#include "actor.h"

#include <glad/glad.h>
#include <iostream>

namespace core
{
    Actor::Actor()
    {
        m_mesh = nullptr;
    }

    Actor::Actor(Mesh* mesh)
    {
        m_mesh = mesh;
    }

    void Actor::setMesh(Mesh* mesh)
    {
        m_mesh = mesh;
    }

    void Actor::draw()
    {
        if(m_mesh == nullptr)
        {
            std::cout << "ERROR: Mesh has not been set.\n";
        }

        m_mesh->draw();
    }
}
