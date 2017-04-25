#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif
#include "particle.h"
#include "glm/glm.hpp"
#include <iostream>
#include <cmath>

// explosion: glm::vec3((float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0)

// constructor
Particle::Particle(glm::vec3 _position/*,glm::vec3 _velocity, glm::vec3 _colour*/, float _size, float _lifeLimit)
{
    m_position = _position;
    m_velocity = glm::normalize(glm::vec3((float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0));
    m_colour = glm::vec3((double)rand()/RAND_MAX*2.0-1.0,0,(double)rand()/RAND_MAX*2.0-1.0);
    m_size = _size;
    m_lifeLimit = _lifeLimit;
    m_lifeSpan = 0;
    m_transparency = 1;

}

// update the particle
void Particle::update()
{
    //m_velocity += glm::vec3(0,-0.098,0);

    // new position
    m_position += m_velocity;

    // lifeSpan update, USE IT AS ALPHA?
    m_lifeSpan += 0.02;

    // updates the alpha channel for the particle
    m_transparency -= 0.02;

    m_colour.x += 0.1;


}

// draw the particle
void Particle::draw()
{
    // enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // colour for the particle
    glColor4f(m_colour.x, m_colour.y, m_colour.z, m_transparency);
    // shape for the particle
    glBegin(GL_QUADS);
    {
            // FRONT
            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z - m_size );
            glVertex3f( m_position.x + m_size, m_position.y + m_size, m_position.z - m_size );
            glVertex3f( m_position.x - m_size, m_position.y + m_size, m_position.z - m_size );
            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z - m_size );

            // BACK
            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z + m_size );
            glVertex3f( m_position.x + m_size, m_position.y + m_size, m_position.z + m_size );
            glVertex3f( m_position.x - m_size, m_position.y + m_size, m_position.z + m_size );
            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z + m_size );

            // RIGHT
            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z - m_size );
            glVertex3f( m_position.x + m_size, m_position.y + m_size, m_position.z - m_size );
            glVertex3f( m_position.x + m_size, m_position.y + m_size, m_position.z + m_size );
            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z + m_size );

            // LEFT
            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z + m_size );
            glVertex3f( m_position.x - m_size, m_position.y + m_size, m_position.z + m_size );
            glVertex3f( m_position.x - m_size, m_position.y + m_size, m_position.z - m_size );
            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z - m_size );

            // TOP
            glVertex3f( m_position.x + m_size,  m_position.y + m_size, m_position.z + m_size );
            glVertex3f( m_position.x + m_size,  m_position.y + m_size, m_position.z - m_size );
            glVertex3f( m_position.x - m_size,  m_position.y + m_size, m_position.z - m_size );
            glVertex3f( m_position.x - m_size,  m_position.y + m_size,  m_position.z + m_size);

            //  BOTTOM
            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z - m_size );
            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z + m_size );
            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z + m_size );
            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z - m_size );



       }
        glEnd();
}


/// @brief checks if the particle is dead or not
int Particle::isDead()
{
    if(m_lifeSpan > m_lifeLimit)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void Particle::reset()
{
    m_position = glm::vec3(0,0,0);
    m_velocity = glm::normalize(glm::vec3((float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0,(float)rand()/RAND_MAX*2.0-1.0));
    m_colour = glm::vec3((double)rand()/RAND_MAX*2.0-1.0,0,(double)rand()/RAND_MAX*2.0-1.0);
    m_size = 0.6;
    m_lifeLimit = 1;
    m_lifeSpan = 0;
    m_transparency = 1;
}
