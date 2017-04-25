#include "emitter.h"
#include <iostream>


// the position of the emitter should be the same as the position of the particles origin
Emitter::Emitter(int _numberOfParticles, glm::vec3 _positionE)
{
    // set the position of the emitter as the position for you particles (pointer)
    for(int i=0; i<_numberOfParticles; ++i)
    {
        m_listOfParticles.push_back(Particle(_positionE,/*glm::vec3(0,-0.002,0), glm::vec3(1,0.3,0),*/0.6,1));
    }
    // number of particles
    m_numberOfParticles = _numberOfParticles;
}


/// @brief a method to update each of the particles contained in the system
void Emitter::update()
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
       if(m_listOfParticles[i].isDead() == 0)
       {
           m_listOfParticles[i].update();
       }
       else
       {
           m_listOfParticles[i].reset();
       }
    }
}

/// @brief a method to draw all the particles contained in the system
void Emitter::draw()
{

    for(int i=0; i<m_numberOfParticles; ++i)
    {
        if(m_listOfParticles[i].isDead() == 0)
        {
            m_listOfParticles[i].draw();
        }
    }

}


/// add a partice pseudo code:
/// check in the list if the their is a dead particle if there is reset partcile
/// to its default values if there is no dead particle add a new particle to the list
