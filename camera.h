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

    /// @build constructor
    Camera();

    /// @build: looks at the target
    void lookAtTgt(glm::vec3 _position, glm::vec3 _eye, glm::vec3 _target);
    /// @build: camera perspective
    void camPerspective(float _fovy, float _aspect, float _zFar, float _zNear);
    /// @build: loads the modelview
    void loadModelView(glm::mat4 _matrix);
    /// @build: loads the projection
    void loadProjection(glm::mat4 _matrix);
};

#endif // CAMERA_H
