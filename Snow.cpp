/// @file Snow.h
/// @brief idem as in the fire file

#include "Snow.h"

Snow::Snow(int _numberOfParticles, glm::vec3 _positionSnow) : Emitter(_numberOfParticles, _positionSnow)
{
    m_numberOfParticles = _numberOfParticles;
    m_positionEmitter = _positionSnow;
}
//--------------------------------------------------------------------------------------------------------------------
void Snow::update(float _deltaTime)
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        if(m_listOfParticles[i].isDead()==0)
        {
            m_listOfParticles[i].update(_deltaTime);
            if(m_listOfParticles[i].getYPosition()<-99)
            {
                m_listOfParticles[i].setVelocity(glm::vec3(0,0,0));
            }
        }
        else
        {
            m_listOfParticles[i].setPosition(glm::vec3((float)rand()/(float)RAND_MAX*200.0-100.0,99,(float)rand()/(float)RAND_MAX*200.0-100.0));
            m_listOfParticles[i].setAcceleration(glm::vec3((float)rand()/(float)RAND_MAX*0.002-0.001,0,(float)rand()/(float)RAND_MAX*0.001-0.0005));
            m_listOfParticles[i].setVelocity((glm::vec3(0,-((float)rand()/RAND_MAX*0.5+0.05),0)));
            m_listOfParticles[i].setColour(glm::vec3(1,0.95,0.95));
            m_listOfParticles[i].setSize((float)rand()/(float)RAND_MAX*2.75+0.5);
            m_listOfParticles[i].setDeltaSize(0.002);
            m_listOfParticles[i].setLifeSpan((float)rand()/(float)RAND_MAX*5.0-2.5);
            m_listOfParticles[i].setDeltaLifeSpan(0.02);
            m_listOfParticles[i].setLifeLimit((float)rand()/(float)RAND_MAX*10.0f+5.0f);
            m_listOfParticles[i].setTransparency((float)rand()/(float)RAND_MAX*15.0+7.5f);
            m_listOfParticles[i].setDeltaTransparency(0.02);
        }
    }
}
