/// @file WaterFall.h
/// @brief This makes a waterfall emitter, when it touches the ground it will make splatter effect

#include "WaterFall.h"

Waterfall::Waterfall(int _numberOfParticles, glm::vec3 _position) : Emitter(_numberOfParticles, _position)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        m_listOfParticles.push_back(Particle());
    }
    m_numberOfParticles = _numberOfParticles;
    m_positionEmitter = _position;
}
//--------------------------------------------------------------------------------------------------------------------
void Waterfall::update(float _deltaTime)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        if(m_listOfParticles[i].isDead()==0)
        {
            m_listOfParticles[i].update(_deltaTime);
            if(m_listOfParticles[i].getYPosition()<-99)
            {
                m_listOfParticles[i].setVelocity((glm::vec3((float)rand()/(float)RAND_MAX*3.0f-1.5f,(float)rand()/(float)RAND_MAX*3.0+1.5f,(float)rand()/(float)RAND_MAX*3.0f-1.5f)));
            }
        }
        else
        {
            m_listOfParticles[i].setPosition(glm::vec3((float)rand()/(float)RAND_MAX*50.0f-25.0f,(float)rand()/(float)RAND_MAX*50-10.0f,(float)rand()/(float)RAND_MAX*25.0f-10.0f)+m_positionEmitter);
            m_listOfParticles[i].setAcceleration(glm::vec3(0,-0.6,0));
            m_listOfParticles[i].setVelocity(glm::vec3(0,-((float)rand()/(float)RAND_MAX*2.0f+1.0f),0));
            m_listOfParticles[i].setColour(glm::vec3(0,0.35,1));
            m_listOfParticles[i].setDeltaColour(glm::vec3(-0.02,-0.02,0));
            m_listOfParticles[i].setSize((float)rand()/(float)RAND_MAX*2.0f+1.0f);
            m_listOfParticles[i].setDeltaSize(0.002);
            m_listOfParticles[i].setLifeSpan(0);
            m_listOfParticles[i].setDeltaLifeSpan(0.02);
            m_listOfParticles[i].setLifeLimit(2);
            m_listOfParticles[i].setTransparency(2);
            m_listOfParticles[i].setDeltaTransparency(0.05);
        }
    }
}

