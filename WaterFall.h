#ifndef EXPLOSIONS_H
#define EXPLOSIONS_H

#include "Emitter.h"


/// \author Moira Shooter
/// \version 1.0
/// \date Last Revision

/// \class Waterfall
/// \brief This creates an Emitter with its number of particles and position, updates the emitter, and draws it
/// You can apply a force to it for example wind
/// \todo add a partice pseudo code:
/// check in the list if the their is a dead particle if there is reset partcile
/// to its default values if there is no dead particle add a new particle to the list

class Waterfall : public Emitter
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief constructor for the emitter
    /// @param[in] _numberOfParticles the number of particles in the emitter
    /// @param[in] _position the position of the emitter
    //--------------------------------------------------------------------------------------------------------------------
    Waterfall(int _numberOfParticles, glm::vec3 _position);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the override function update for the waterfall emitter
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    void update(float _deltaTime) override;

};

#endif // EXPLOSIONS_H
