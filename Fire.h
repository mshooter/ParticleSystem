#ifndef FIRE_H
#define FIRE_H

#include <iostream>
#include <cstdlib>
#include "SDL2/SDL.h"
#include "Emitter.h"

/// \author Moira Shooter
/// \version 1.0
/// \date Last Revision

/// \class Fire
/// \brief This is a derived class of Emitter
/// \todo

class Fire : public Emitter
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief fire constructor
    /// @param[in] _numberOfParticles: the number of particles in the emitter
    /// @param[in] _positionEmitter: the position of the Emitter
    //--------------------------------------------------------------------------------------------------------------------
    Fire(int _numberOfParticles, glm::vec3 _positionEmitter);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief update function for fire emitter it overriedes the update function of the emitter base class
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    void update(float _deltaTime) override;
};

#endif // FIRE_H
