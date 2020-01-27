#ifndef ACTOR
#define ACTOR

#include "mesh.h"
#include "shader.h"
#include "transform.h"

#include <glm/glm.hpp>

namespace core
{
    constexpr glm::vec4     DEFAULT_COLOR               = glm::vec4{ 1.0f };
    constexpr const char*   SHADER_PROPERTY_COLOR       = "color";
    constexpr const char*   SHADER_PROPERTY_TRANSFORM   = "transform";

    class Actor
    {
    private:
        Mesh*       m_mesh{};
        Shader*     m_shader{};
        Transform   m_transform{};
        glm::vec4   m_color{ DEFAULT_COLOR };

    public:
        Actor();
        Actor(Mesh* mesh, Shader* shader);

        Transform getTransform();

        void setMesh(Mesh* mesh);
        void setShader(Shader* shader);
        void setColor(glm::vec4 color);

        glm::vec3 getPosition();
        glm::vec3 getRotation();
        glm::vec3 getScale();

        void setPosition(glm::vec3 position);
        void setRotation(glm::vec3 rotation);
        void setScale(glm::vec3 scale);        

        void draw();
    };
}

#endif