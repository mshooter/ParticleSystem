#ifndef SNOW_H
#define SNOW_H

#include "Emitter.h"

/// \author Moira Shooter
/// \version 1.0
/// \date Last Revision

/// \class Snow
/// \brief This is a derived class of Emitter
/// \todo

class Snow : public Emitter
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief snow constructor
    /// @param[in] _numberOfParticles is the number of particle in the snow emitter
    /// @param[in] _positionis the position of the snow emitter
    //--------------------------------------------------------------------------------------------------------------------
    Snow(int _numberOfParticles,  glm::vec3 _position);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the update function that overrides the update function of base emitter
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    void update(float _deltaTime) override;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that reverse the velocity of the snow emitter
    /// @param _velociy: the velocity of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void reverse(glm::vec3 _velocity);

};

#endif // SNOW_H
