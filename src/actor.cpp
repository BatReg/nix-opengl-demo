#include "actor.h"

#include <iostream>

namespace core
{
    Actor::Actor()
    {
        m_mesh      = nullptr;
        m_shader    = nullptr;        
    }

    Actor::Actor(Mesh* mesh, Shader* shader)
    {
        m_mesh      = mesh;
        m_shader    = shader;
    }

    Transform Actor::getTransform()
    {
        return m_transform;
    }

    void Actor::setMesh(Mesh* mesh)
    {
        std::cout << "TRANSFORM::X:" << m_transform.pos.x << "::Y:" << m_transform.pos.y << "::Z:" << m_transform.pos.z << std::endl;
        std::cout << "ROTATION::X:" << m_transform.rot.x << "::Y:" << m_transform.rot.y << "::Z:" << m_transform.rot.z << std::endl;
        std::cout << "SCALE::X:" << m_transform.scale.x << "::Y:" << m_transform.scale.y << "::Z:" << m_transform.scale.z << std::endl;
        m_mesh = mesh;
    }

    void Actor::setShader(Shader* shader)
    {
        m_shader = shader;
    }

    void Actor::setPosition(glm::vec3 position)
    {
        m_transform.pos = position;
    }

    void Actor::setRotation(glm::vec3 rotation)
    {
        m_transform.rot = rotation;
    }

    void Actor::setScale(glm::vec3 scale)
    {
        m_transform.scale = scale;
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
        m_shader->setMat4("transform", m_transform.getTransformMatrix());

        m_mesh->draw();

        m_shader->deActivate();
    }
}
