#ifndef EMITTER_H
#define EMITTER_H

#include <iostream>
#include <vector>
#include "Particle.h"

/// \author Moira Shooter
/// \version 1.0
/// \date Last Revision

/// \class Emitter
/// \brief This creates an Emitter with its number of particles and position, updates the emitter, and draws it
/// You can apply a force to it for example wind
/// \todo add a partice pseudo code:
/// check in the list if the their is a dead particle if there is reset partcile
/// to its default values if there is no dead particle add a new particle to the list


class Emitter
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief constructor for the emitter
    /// @param[in] _numberOfParticles the number of particles in the container(emitter)
    /// @param[in] _position the position of the emitter
    //--------------------------------------------------------------------------------------------------------------------
    Emitter(int _numberOfParticles, glm::vec3 _positionE);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief default destructor for the emitter
    //--------------------------------------------------------------------------------------------------------------------
    ~Emitter(){;}
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief virtual upddate method (it's different in every derived class)
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    virtual void update(float _deltaTime)=0;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that draws the emitter
    //--------------------------------------------------------------------------------------------------------------------
    void draw();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief funtion that runs the emitter
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    void run(float _deltaTime);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief add force to the particle system
    //--------------------------------------------------------------------------------------------------------------------
    void applyWind();

protected:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief number of particles that the emitter has
    //--------------------------------------------------------------------------------------------------------------------
    int m_numberOfParticles;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief Emitter's position
    //--------------------------------------------------------------------------------------------------------------------
    glm::vec3 m_positionEmitter;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief a vector where you store the particles in
    //--------------------------------------------------------------------------------------------------------------------
    std::vector<Particle> m_listOfParticles;

};

#endif // EMITTER_H
