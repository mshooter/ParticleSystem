#ifndef FIRE_H
#define FIRE_H
/// @file Fire.h
/// @brief A Emitter class called fire that generates a simpel fire
#include <iostream>
#include <cstdlib>
#include "SDL2/SDL.h"
#include "Emitter.h"

/// \author Moira Shooter
/// \version
/// \date Last Revision 16 MAY 2017

/// \class Fire
/// \brief This is a derived class of Emitter
/// \todo You have to resolve the generate particle and kill particle

class Fire : public Emitter
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief constructor for the emitter, fire
    /// @param[in] _numberOfParticles: the number of particles in the emitter
    /// @param[in] _positionEmitter: the position of the Emitter
    //--------------------------------------------------------------------------------------------------------------------
    Fire(int _numberOfParticles, glm::vec3 _positionEmitter);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief default destructor for the emitter, fire
    //--------------------------------------------------------------------------------------------------------------------
    ~Fire(){;}
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief update function for fire emitter it overriedes the update function of the emitter base class
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    void update(float _deltaTime) override;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that changes the acceleration of the fire when someone/soething causes wind
    //--------------------------------------------------------------------------------------------------------------------
    void blowOnFire();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief mutator function that resets the acceleration of the fire
    //--------------------------------------------------------------------------------------------------------------------
    void resetAcceleration();



};

#endif // FIRE_H
