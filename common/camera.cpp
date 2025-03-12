#include <common/camera.hpp>

Camera::Camera(const glm::vec3 Eye, const glm::vec3 Target)
{
    eye = Eye;
    target = Target;
}

void Camera::calculateMatrices(float deltaTime)
{
    calculateCameraVectors();
    if (!jumping) {
        eye.y = 0;
    }
    else {
        eye.y = jumpHeight * sin(3.14159f * jumpTimer);
        jumpTimer -= deltaTime;
        if (jumpTimer < 0) {
            jumping = false;
            jumpTimer = jumpTime;
        }
    }
    view = glm::lookAt(eye, eye+front , worldUp);
    projection = glm::perspective(fov, aspect, near, far);
}

void Camera::calculateCameraVectors()
{
    front = glm::vec3(cos(yaw) * cos(pitch), sin(pitch), sin(yaw) * cos(pitch)); 
    right = glm::normalize(glm::cross(front, worldUp)); 
    up = glm::cross(right, front); 
}

void Camera::jump() {
    jumping = true;
}