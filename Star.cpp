#include "Star.h"

Star::Star(int _numberOfParticles, glm::vec3 _position) : Emitter (_numberOfParticles, _position)
{
    m_numberOfParticles = _numberOfParticles;
    m_positionEmitter = _position;
}

void Star::update(float _deltaTime)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
       if(m_listOfParticles[i].isDead() == 0)
       {
           m_listOfParticles[i].update(_deltaTime);
           if(m_listOfParticles[i].getYPosition()>=10)
           {
               m_listOfParticles[i].setColour(glm::vec3(1,0,0));
               m_listOfParticles[i].setAcceleration(glm::vec3(0,-0.4,0));
               m_listOfParticles[i].setTransparency(5);
           }
           if(m_listOfParticles[i].getYPosition()<-95)
           {
               m_listOfParticles[i].setVelocity(glm::vec3(0,0,0));
           }
       }
    }
}


void Star::generateParticles(glm::vec3 _originalPosition)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        m_listOfParticles[i].setPosition((_originalPosition)+m_positionEmitter);
        m_listOfParticles[i].setVelocity(glm::normalize(glm::vec3((float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0,0)));
        m_listOfParticles[i].setColour(glm::vec3(1,1,0));
        m_listOfParticles[i].setAcceleration(glm::vec3(0,0,0));
        m_listOfParticles[i].setLifeLimit(1);
        m_listOfParticles[i].setLifeSpan((float)rand()/RAND_MAX*2.0-1.0);
        m_listOfParticles[i].setDeltaLifeSpan(0.02);
        m_listOfParticles[i].setSize(2);
        m_listOfParticles[i].setTransparency(1);
        m_listOfParticles[i].setDeltaTransparency(0.02);
        m_listOfParticles.push_back(Particle());
    }
}
