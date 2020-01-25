#include "actor.h"

#include <iostream>

namespace core
{
    Actor::Actor()
    {
        m_mesh = nullptr;
        m_shader = nullptr;
    }

    Actor::Actor(Mesh* mesh, Shader* shader)
    {
        m_mesh = mesh;
        m_shader = shader;
    }

    void Actor::setMesh(Mesh* mesh)
    {
        m_mesh = mesh;
    }

    void Actor::setShader(Shader* shader)
    {
        m_shader = shader;
    }

    void Actor::draw()
    {
        if(m_mesh == nullptr)
        {
            std::cout << "ERROR: Mesh has not been set.\n";
            return;
        }

        if(m_shader == nullptr)
        {
            std::cout << "ERROR: Shader has not been set.\n";
            return;
        }

        m_shader->activate();
        m_mesh->draw();
        m_shader->deActivate();
    }
}
