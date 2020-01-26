#ifndef TRANSFORM
#define TRANSFORM

#include <glm/glm.hpp>

namespace core
{
    struct Transform
    {
    public:
        glm::vec3 pos;
        glm::vec3 rot;
        glm::vec3 scale;

        Transform();
        Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scaling);

        glm::mat4 getTransformMatrix();
    };
}

#endif