#include "transform.h"

#include <glm/gtc/matrix_transform.hpp>

namespace core
{
    Transform::Transform()
    {
        pos     = glm::vec3{ 0.0f };
        rot     = glm::vec3{ 0.0f };
        scale   = glm::vec3{ 1.0f };
    }

    Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scaling)
    {
        pos     = glm::vec3{ position };
        rot     = glm::vec3{ rotation };
        scale   = glm::vec3{ scaling };
    }

    glm::mat4 Transform::getTransformMatrix()
    {
        glm::mat4 result = glm::mat4{ 1.0f };

        result = glm::translate(result, pos);
        result = glm::rotate(result, glm::radians(rot.x), AXIS_X);
        result = glm::rotate(result, glm::radians(rot.y), AXIS_Y);
        result = glm::rotate(result, glm::radians(rot.z), AXIS_Z);
        result = glm::scale(result, scale);

        return result;
    }
}
