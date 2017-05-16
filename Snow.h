#ifndef SNOW_H
#define SNOW_H
/// @file Snow.h
/// @brief A Emitter class called Snow that generates a snow
#include "Emitter.h"

/// \author Moira Shooter
/// \version
/// \date Last Revision 16 MAY 2017

/// \class Snow
/// \brief This is a derived class of Emitter
/// \todo if inital state dont make it move

class Snow : public Emitter
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief constructor for the emitter, snow
    /// @param[in] _numberOfParticles is the number of particle in the snow emitter
    /// @param[in] _positionis the position of the snow emitter
    //--------------------------------------------------------------------------------------------------------------------
    Snow(int _numberOfParticles,  glm::vec3 _position);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief destructor fot the emitter, snow
    //--------------------------------------------------------------------------------------------------------------------
    ~Snow(){;}
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the update function that overrides the update function of base emitter
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    void update(float _deltaTime) override;
};

#endif // SNOW_H
