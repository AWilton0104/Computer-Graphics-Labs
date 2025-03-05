#include <common/camera.hpp>

Camera::Camera(const glm::vec3 Eye, const glm::vec3 Target)
{
    eye = Eye;
    target = Target;
}

void Camera::calculateMatrices()
{
    view = glm::lookAt(eye, target, worldUp);
    projection = glm::perspective(fov, aspect, near, far);
}
