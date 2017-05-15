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

/// \author Moira Shooter
/// \version 1.0
/// \date Last Revision

/// \class Camera
/// \brief This creates a camera, with the functions: where the camera looks at and its position
/// \todo need a fucntion for when we change the position of the camera and the look at target
/// (change the world coordinates when move camera from a different angle)

class Camera
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the default constructor for the camera
    //--------------------------------------------------------------------------------------------------------------------
    Camera();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the default destructor for the camera
    //--------------------------------------------------------------------------------------------------------------------
    ~Camera(){;}
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief looks at the target
    /// @param[in] _eye the position of the camera
    /// @param[in] _target the position where the camera is looking at
    //--------------------------------------------------------------------------------------------------------------------
    void lookAtTarget(glm::vec3 _eye, glm::vec3 _target);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief camera perspective
    /// @param[in] _fovy the field of view of the camera
    /// @param[in] _aspect the aspect ration of the camera
    /// @param[in] _zFar the far clipping plane
    /// @param[in] _zNear the near clipping plane
    //--------------------------------------------------------------------------------------------------------------------
    void camPerspective(float _fovy, float _aspect, float _zFar, float _zNear);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief loads the modelview
    /// @param[in] _matrix the matrix that you are loading to load the model
    //--------------------------------------------------------------------------------------------------------------------
    void loadModelView(glm::mat4 _matrix);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief loads the projection
    /// @param[in] _matrix the matrix that you are loading for the projection
    //--------------------------------------------------------------------------------------------------------------------
    void loadProjection(glm::mat4 _matrix);

};

#endif // CAMERA_H
