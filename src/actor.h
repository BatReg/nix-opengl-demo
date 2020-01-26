#ifndef ACTOR
#define ACTOR

#include "mesh.h"
#include "shader.h"
#include "transform.h"

namespace core
{
    class Actor
    {
    private:
        Mesh*   m_mesh{};
        Shader* m_shader{};
        Transform m_transform{};

    public:
        Actor();
        Actor(Mesh* mesh, Shader* shader);

        Transform getTransform();

        void setMesh(Mesh* mesh);
        void setShader(Shader* shader);

        void setPosition(glm::vec3 position);
        void setRotation(glm::vec3 rotation);
        void setScale(glm::vec3 scale);

        void draw();
    };
}

#endif