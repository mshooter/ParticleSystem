#include "fireworks.h"
#include <iostream>
#include <cstdlib>

Fireworks::Fireworks(int _numberOfParticles, glm::vec3 _positionFireworks) : Emitter(_numberOfParticles, _positionFireworks)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        m_listOfParticles.push_back(Particle());
    }
    m_numberOfParticles = _numberOfParticles;
    m_positionEmitter = _positionFireworks;

}


/// COMMENT if it comes to a certain speed explode, bit first it should go up
void Fireworks::update(float _deltaTime)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        if(m_listOfParticles[i].isDead()==0)
        {
            m_listOfParticles[i].update(_deltaTime);
        }
        else
        {
//            m_listOfParticles[i].setPosition(glm::vec3(0,70,0)+m_positionEmitter);
//            m_listOfParticles[i].setVelocity(glm::normalize(glm::vec3((float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0)));
//            m_listOfParticles[i].setColour(glm::vec3(1,0,0.2));
//            m_listOfParticles[i].setSize(2);
//            m_listOfParticles[i].setDeltaSize(0);
//            m_listOfParticles[i].setLifeSpan(0);
//            m_listOfParticles[i].setLifeLimit(10);
//            m_listOfParticles[i].setTransparency(1);

            m_listOfParticles[i].setPosition(glm::vec3((float)rand()/RAND_MAX*200.0-100.0,100,(float)rand()/RAND_MAX*200.0-100.0));
            m_listOfParticles[i].setVelocity((glm::vec3(0,-((float)rand()/RAND_MAX*0.5+0.05),0)));
            m_listOfParticles[i].setColour(glm::vec3(1,1,1));
            m_listOfParticles[i].setDeltaColour(glm::vec3(0,0.02,0));
            m_listOfParticles[i].setSize((float)rand()/RAND_MAX*5.0);
            m_listOfParticles[i].setDeltaSize(0.1);
            m_listOfParticles[i].setLifeSpan((float)rand()/RAND_MAX*2.0-0.5);
            m_listOfParticles[i].setLifeLimit((float)rand()/(float)RAND_MAX*5+5.0f);
            m_listOfParticles[i].setTransparency((float)rand()/(float)RAND_MAX*5.0+3.0f);

        }
    }
}
