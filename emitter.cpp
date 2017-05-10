#include "emitter.h"
#include <iostream>

///
///
/// COMMENTS:
///
/// constructors are not inherited
/// use keyword virtual (=0 := pure functions) to override the base class functions

/// @build constructor
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
///

void Emitter::run(float _deltaTime)
{
    update(_deltaTime);
    draw();
}


//void Emitter::run()
//{
//    for(int i=0; i<m_numberOfParticles; ++i)
//    {
//        if(m_listOfParticles[i].isDead() == 0)
//        {
//            m_listOfParticles[i].update();
//            m_listOfParticles[i].draw();
//        }
//        else
//        {
//            // resetting the particles
//            // firecurtain settings
//            m_listOfParticles[i].setPosition((glm::vec3(((float)rand()/RAND_MAX*101.0-50),0,(float)rand()/RAND_MAX*101.0-50))+m_positionEmitter);
//            m_listOfParticles[i].setVelocity(glm::vec3(0,(float)rand()/RAND_MAX*2.0+0.1,0));
//            m_listOfParticles[i].setColour(glm::vec3(1,0.5,0));
//            m_listOfParticles[i].setSize((float)rand()/RAND_MAX*3);
//            m_listOfParticles[i].setLifeSpan((float)rand()/RAND_MAX*2+1.0);
//            m_listOfParticles[i].setLifeLimit(2);
//            m_listOfParticles[i].setTransparency(1);

//            // firework settings
//            /*m_listOfParticles[i].setPosition(m_positionEmitter);
//            m_listOfParticles[i].setVelocity(glm::normalize(glm::vec3((float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0)));
//            m_listOfParticles[i].setColour(glm::vec3(1,0,0.2));
//            m_listOfParticles[i].setSize((float)rand()/RAND_MAX*0.6);
//            m_listOfParticles[i].setLifeSpan(0);
//            m_listOfParticles[i].setLifeLimit(1);
//            m_listOfParticles[i].setTransparency(1);*/

//            // heavy rain settings
//            m_listOfParticles[i].setPosition((glm::vec3(((float)rand()/RAND_MAX*101.0-50),100,(float)rand()/RAND_MAX*101.0-50))+m_positionEmitter);
//            m_listOfParticles[i].setVelocity(glm::vec3(0,-(double)rand()/RAND_MAX*2-0.1,0));
//            m_listOfParticles[i].setColour(glm::vec3(0,0.5,1));
//            m_listOfParticles[i].setSize((float)rand()/RAND_MAX*0.6);
//            m_listOfParticles[i].setLifeSpan((float)rand()/RAND_MAX*2+1.0);
//            m_listOfParticles[i].setLifeLimit(2);
//            m_listOfParticles[i].setTransparency(1);



//        }
//    }
//}


