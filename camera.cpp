#include "camera.h"

Camera::Camera()
{

}

void Camera::lookAtTgt(glm::vec3 _position, glm::vec3 _eye, glm::vec3 _target)
{
    _eye = _position;
    loadModelView(glm::lookAt(_eye, _target, glm::vec3(0,1,0)));
}

void Camera::camPerspective(float _fovy, float _aspect, float _zNear, float _zFar)
{
    loadProjection(glm::perspective(_fovy, _aspect, _zNear, _zFar));
}

void Camera::loadModelView(glm::mat4 _matrix)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMultMatrixf((const float*)glm::value_ptr(_matrix));
}

void Camera::loadProjection(glm::mat4 _matrix)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMultMatrixf((const float*)glm::value_ptr(_matrix));
    glMatrixMode(GL_MODELVIEW);
}
