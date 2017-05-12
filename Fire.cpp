/// @file Fire.h
/// @brief Constructor and update function, the update function overrides the virtual update function of the emitter

#include "Fire.h"


Fire::Fire(int _numberOfParticles, glm::vec3 _positionFire) : Emitter(_numberOfParticles, _positionFire)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        m_listOfParticles.push_back(Particle());
    }
    m_numberOfParticles = _numberOfParticles;
    m_positionEmitter = _positionFire;
}
//--------------------------------------------------------------------------------------------------------------------
void Fire::update(float _deltaTime)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
       if(m_listOfParticles[i].isDead() == 0)
       {
           m_listOfParticles[i].update(_deltaTime);
       }
       else
       {
           m_listOfParticles[i].setPosition((glm::vec3(sin((float)rand()/RAND_MAX*10.0-4.5f), 0, sin((float)rand()/RAND_MAX*10.0f-4.0f))*(glm::vec3((float)rand()/RAND_MAX*25.0-13.0f, 0, (float)rand()/RAND_MAX*25.0f-13.0f)))+m_positionEmitter);
           m_listOfParticles[i].setVelocity(glm::vec3(0,(float)rand()/(float)RAND_MAX*2.0+0.5,0));
           m_listOfParticles[i].setColour(glm::vec3(1,0.5,0));
           m_listOfParticles[i].setDeltaColour(glm::vec3(0,0.02,0));
           m_listOfParticles[i].setSize((float)rand()/RAND_MAX*5.0+2.5);
           m_listOfParticles[i].setDeltaSize(0.1);
           m_listOfParticles[i].setLifeSpan((float)rand()/RAND_MAX*2.0-0.5);
           m_listOfParticles[i].setLifeLimit(1);
           m_listOfParticles[i].setTransparency(1);

       }
    }
}

