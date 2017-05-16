//--------------------------------------------------------------------------------------------------------------------
/// @file Emitter.h
/// @brief Creates the constructor, the update, draw, run and applyforce function.
//--------------------------------------------------------------------------------------------------------------------
#include "Emitter.h"

Emitter::Emitter(int _numberOfParticles, glm::vec3 _positionE)
{
    for(int i=0; i<_numberOfParticles; ++i)
    {
        m_listOfParticles.push_back(Particle());
    }

    m_numberOfParticles = _numberOfParticles;
    m_positionEmitter = _positionE;
}
//--------------------------------------------------------------------------------------------------------------------
void Emitter::draw()
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        // only draw if the particle is alive
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
void Emitter::applyWind()
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        m_listOfParticles[i].setAcceleration(glm::vec3(0,0,(float)rand()/(float)RAND_MAX*0.005));
    }
}
