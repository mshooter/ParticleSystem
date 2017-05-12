/// @file Particle.h
/// @brief constructor, udpates the particles, draws the particles, set and get methods are available

#include "Particle.h"

Particle::Particle()
{
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::update(float _deltaTime)
{

    // makes weird shapes
   // m_velocity += glm::vec3(0,-cos(45)*0.1,0);
    m_velocity +=m_acceleration*_deltaTime;

    // new position
    m_position += m_velocity*_deltaTime;

   // m_oldPosition = m_position;
    // lifeSpan update, USE IT AS ALPHA?
   m_lifeSpan += 0.02*_deltaTime;

    // updates the alpha channel for the particle
    m_transparency -= 0.02*_deltaTime;

//    //firework
    m_colour -= m_deltaColour*_deltaTime;
//    /// there is a problem when you set it to 0.1 it grows bigger
//    /// it is probably because you use the size in the drawing of the particle
   m_size -= m_deltaSize*_deltaTime;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::draw()
{
    // enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // colour for the particle
    glColor4f(m_colour.x, m_colour.y, m_colour.z, m_transparency);

    // shape of particle
     glEnable(GL_POINT_SMOOTH);

     glPointSize(m_size);
     glBegin(GL_POINTS);
     glVertex3f(m_position.x, m_position.y, m_position.z);
     glEnd();

}

//--------------------------------------------------------------------------------------------------------------------
/// @brief checks if the particle is dead or not
/// SOMETHING IS WRONG WITH THE DEAD METHOD
int Particle::isDead()
{
    if( m_lifeSpan >= m_lifeLimit ||m_position.y>100|| m_size < 0 || m_transparency<=0  )
    {

        return 1;
    }
    else
    {


        return 0;
    }
}

//--------------------------------------------------------------------------------------------------------------------
void Particle::setPosition(glm::vec3 _position)
{
    m_position = _position;
}
//--------------------------------------------------------------------------------------------------------------------

void Particle::setVelocity(glm::vec3 _velocity)
{
    m_velocity = _velocity;
}

//--------------------------------------------------------------------------------------------------------------------
void Particle::setColour(glm::vec3 _colour)
{
    m_colour = _colour;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::setDeltaColour(glm::vec3 _deltaColour)
{
    m_deltaColour = _deltaColour;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::setSize(float _size)
{
    m_size = _size;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::setDeltaSize(float _deltaSize)
{
    m_deltaSize = _deltaSize;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::setLifeSpan(float _lifeSpan)
{
    m_lifeSpan=_lifeSpan;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::setTransparency(float _transparency)
{
    m_transparency = _transparency;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::setLifeLimit(float _lifeLimit)
{
    m_lifeLimit = _lifeLimit;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::setAcceleration(glm::vec3 _acceleration)
{
    m_acceleration = _acceleration;
}
