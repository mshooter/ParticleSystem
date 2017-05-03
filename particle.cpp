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



/// @brief constructor
Particle::Particle()
{
}

/// @brief method that updates the particle
void Particle::update()
{
   // m_velocity += glm::vec3(0,-0.04,0);

    // new position
    m_position += m_velocity;


    // lifeSpan update, USE IT AS ALPHA?
    m_lifeSpan += 0.02;

    // updates the alpha channel for the particle
   // m_transparency -= 0.02;

    //firework
    //m_colour.x += 0.01;
    /// there is a problem when you set it to 0.1 it grows bigger
    /// it is probably because you use the size in the drawing of the particle
    //m_size -= 0.001;

}

/// @brief method that draws the particle
void Particle::draw()
{
    // enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // colour for the particle
    glColor4f(m_colour.x, m_colour.y, m_colour.z, m_transparency);
    // shape for the particle
//    glBegin(GL_QUADS);
//    {
//            // FRONT
//            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z - m_size );
//            glVertex3f( m_position.x + m_size, m_position.y + m_size, m_position.z - m_size );
//            glVertex3f( m_position.x - m_size, m_position.y + m_size, m_position.z - m_size );
//            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z - m_size );

//            // BACK
//            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z + m_size );
//            glVertex3f( m_position.x + m_size, m_position.y + m_size, m_position.z + m_size );
//            glVertex3f( m_position.x - m_size, m_position.y + m_size, m_position.z + m_size );
//            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z + m_size );

//            // RIGHT
//            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z - m_size );
//            glVertex3f( m_position.x + m_size, m_position.y + m_size, m_position.z - m_size );
//            glVertex3f( m_position.x + m_size, m_position.y + m_size, m_position.z + m_size );
//            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z + m_size );

//            // LEFT
//            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z + m_size );
//            glVertex3f( m_position.x - m_size, m_position.y + m_size, m_position.z + m_size );
//            glVertex3f( m_position.x - m_size, m_position.y + m_size, m_position.z - m_size );
//            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z - m_size );

//            // TOP
//            glVertex3f( m_position.x + m_size,  m_position.y + m_size, m_position.z + m_size );
//            glVertex3f( m_position.x + m_size,  m_position.y + m_size, m_position.z - m_size );
//            glVertex3f( m_position.x - m_size,  m_position.y + m_size, m_position.z - m_size );
//            glVertex3f( m_position.x - m_size,  m_position.y + m_size,  m_position.z + m_size);
//            //  BOTTOM
//            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z - m_size );
//            glVertex3f( m_position.x + m_size, m_position.y - m_size, m_position.z + m_size );
//            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z + m_size );
//            glVertex3f( m_position.x - m_size, m_position.y - m_size, m_position.z - m_size );



//       }
//        glEnd();

    glEnable(GL_POINT_SMOOTH);

     glPointSize(m_size);
     glBegin(GL_POINTS);
     glVertex3f(m_position.x, m_position.y, m_position.z);
     glEnd();
}


/// @brief checks if the particle is dead or not
/// SOMETHING IS WRONG WITH THE DEAD METHOD
int Particle::isDead()
{
    if(m_lifeSpan >= m_lifeLimit || m_size < 0 || m_transparency<=0 || m_position.x >= 80 || m_position.y >= 80)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/// @brief method that sets the position of particle
void Particle::setPosition(glm::vec3 _position)
{
    m_position = _position;
}

/// @brief method that sets the velocity of particle
void Particle::setVelocity(glm::vec3 _velocity)
{
    m_velocity = _velocity;
}

/// @brief method that sets the colour of particle
void Particle::setColour(glm::vec3 _colour)
{
    m_colour = _colour;
}

/// @brief method that sets the size of the particle
void Particle::setSize(float _size)
{
    m_size = _size;
}

/// @brief method that sets the lifespan of the particle
void Particle::setLifeSpan(float _lifeSpan)
{
    m_lifeSpan=_lifeSpan;
}

/// @brief method that sets the transparency of the particle
void Particle::setTransparency(float _transparency)
{
    m_transparency = _transparency;
}

/// @brief method that sets the lifelimit of the particle
void Particle::setLifeLimit(float _lifeLimit)
{
    m_lifeLimit = _lifeLimit;
}
