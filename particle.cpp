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
#include "SDL2/SDL.h"


/// @brief constructor
Particle::Particle()
{
}

/// @brief method that updates the particle
void Particle::update()
{

    // makes weird shapes
   // m_velocity += glm::vec3(0,-cos(45)*0.1,0);
    m_velocity +=m_acceleration;
    // new position
    m_position += m_velocity;

   // m_oldPosition = m_position;
    // lifeSpan update, USE IT AS ALPHA?
   m_lifeSpan += 0.02;

    // updates the alpha channel for the particle
    m_transparency -= 0.02;

    //firework
    m_colour -= m_deltaColour;
    /// there is a problem when you set it to 0.1 it grows bigger
    /// it is probably because you use the size in the drawing of the particle
   m_size -= m_deltaSize;

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
    if( m_lifeSpan >= m_lifeLimit || m_size < 0 || m_transparency<=0  )
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

float Particle::getVelocity_Y() const
{
    return m_velocity.y;
}

/// @brief method that sets the colour of particle
void Particle::setColour(glm::vec3 _colour)
{
    m_colour = _colour;
}

/// @brief method that sets the delta colour of particle
void Particle::setDeltaColour(glm::vec3 _deltaColour)
{
    m_deltaColour = _deltaColour;
}

/// @brief method that sets the size of the particle
void Particle::setSize(float _size)
{
    m_size = _size;
}

/// @brief method that sets the deltasize of the particle
void Particle::setDeltaSize(float _deltaSize)
{
    m_deltaSize = _deltaSize;
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

/// @brief method that set the life of the particle
void Particle::setLife(int _alive)
{
    m_alive = _alive;
}

/// @brief method to get life
int Particle::getLife() const
{
    return m_alive;
}

/// @brief set acceleration
void Particle::setAcceleration(glm::vec3 _acceleration)
{
    m_acceleration = _acceleration;
}
