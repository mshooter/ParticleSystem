/// @file Emitter.h
/// @brief Creates the constructor, the update, draw, run and applyforce function.

#include "Emitter.h"

Emitter::Emitter(int _numberOfParticles, glm::vec3 _positionE)
{
    // set the position of the emitter as the position for you particles (pointer)
    for(int i=0; i<_numberOfParticles; ++i)
    {
        m_listOfParticles.push_back(Particle());
    }
    // number of particles
    m_numberOfParticles = _numberOfParticles;
    m_positionEmitter = _positionE;

}
//--------------------------------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------------------------------
void Emitter::run(float _deltaTime)
{
    update(_deltaTime);
    draw();
}

//--------------------------------------------------------------------------------------------------------------------
void Emitter::applyForce(glm::vec3 _acceleration)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        m_listOfParticles[i].setAcceleration(_acceleration);
    }
}
