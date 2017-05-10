#ifndef CAMERA_H
#define CAMERA_H
#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera
{
public:
    Camera();

    void lookAtTgt(glm::vec3 _position, glm::vec3 _eye, glm::vec3 _target);
    void camPerspective(float _fovy, float _aspect, float _zFar, float _zNear);
    void loadModelView(glm::mat4 _matrix);
    void loadProjection(glm::mat4 _matrix);
};

#endif // CAMERA_H
