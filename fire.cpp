#include "fire.h"

Fire::Fire(int _numberOfParticles, glm::vec3 _positionFire) : Emitter(_numberOfParticles, _positionFire)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        m_listOfParticles.push_back(Particle());
    }
    m_numberOfParticles = _numberOfParticles;
    m_positionEmitter = _positionFire;
}

void Fire::update()
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
       if(m_listOfParticles[i].isDead() == 0)
       {
           m_listOfParticles[i].update();
       }
       else
       {
           m_listOfParticles[i].setPosition((glm::vec3((float)rand()/RAND_MAX*101.0-50, 0, (float)rand()/RAND_MAX*101-50))+m_positionEmitter);
           m_listOfParticles[i].setVelocity(glm::vec3(0,(float)rand()/RAND_MAX*2.0+0.1,0));
           m_listOfParticles[i].setColour(glm::vec3(1,0.5,0));
           m_listOfParticles[i].setSize((float)rand()/RAND_MAX*3);
           m_listOfParticles[i].setLifeSpan((float)rand()/RAND_MAX*2.0+0.5);
           m_listOfParticles[i].setLifeLimit(2);
           m_listOfParticles[i].setTransparency(1);
       }
    }
}
