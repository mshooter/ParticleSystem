#include "emitter.h"
#include <iostream>

///
///
/// COMMENTS:
/* sort of fire
* m_position = glm::vec3((float)rand()/RAND_MAX*101.0-50,-100,(float)rand()/RAND_MAX*101.0-50);
m_velocity = glm::vec3(0,((float)rand()/RAND_MAX*2.0+0.1),0);
m_colour = glm::vec3(1,0.5,0);
m_size = (float)rand()/RAND_MAX*0.6;
m_lifeLimit = 2;
m_lifeSpan = (float)rand()/RAND_MAX*2+1.0;
m_transparency = 1;*/

/* m_position = m_oldPosition;
m_velocity = (glm::vec3((float)rand()/RAND_MAX*0.5f-0.4,((float)rand()/RAND_MAX*2+1.0),(float)rand()/RAND_MAX*2-0.4));
m_colour = glm::vec3(1,0.5,0);
m_size = 1;
m_lifeLimit = 3;
m_lifeSpan = (float)rand()/RAND_MAX*2+1.0;
m_transparency = 1;*/
///
///
///

/// @build constructor
Emitter::Emitter(int _numberOfParticles, glm::vec3 _positionE)
{
    // set the position of the emitter as the position for you particles (pointer)
    for(int i=0; i<_numberOfParticles; ++i)
    {
        m_listOfParticles.push_back(Particle(_positionE));
    }
    // number of particles
    m_numberOfParticles = _numberOfParticles;

}


/*/// @brief a method to update each of the particles contained in the system
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

}*/


/// add a partice pseudo code:
/// check in the list if the their is a dead particle if there is reset partcile
/// to its default values if there is no dead particle add a new particle to the list

void Emitter::run()
{
    for(int i=0; i<m_numberOfParticles; ++i)
    {
        if(m_listOfParticles[i].isDead() == 0)
        {
            m_listOfParticles[i].update();
            m_listOfParticles[i].draw();
        }
        else
        {
            // resetting the particles
            m_listOfParticles[i].setPosition(glm::vec3(0,0,0));
            m_listOfParticles[i].setVelocity( glm::normalize(glm::vec3((float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0)));
            m_listOfParticles[i].setColour(glm::vec3((double)rand()/RAND_MAX*2.0-1,0,0));
            m_listOfParticles[i].setSize(0.3);
            m_listOfParticles[i].setLifeSpan(0);
            m_listOfParticles[i].setTransparency(1);

        }
    }
}

