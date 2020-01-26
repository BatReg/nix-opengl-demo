#ifndef TRANSFORM
#define TRANSFORM

#include <glm/glm.hpp>

namespace core
{
    inline constexpr glm::vec3 AXIS_X = glm::vec3{ 1.0f, 0.0f, 0.0f };
    inline constexpr glm::vec3 AXIS_Y = glm::vec3{ 0.0f, 1.0f, 0.0f };
    inline constexpr glm::vec3 AXIS_Z = glm::vec3{ 0.0f, 0.0f, 1.0f };

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