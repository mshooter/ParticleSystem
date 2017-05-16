//--------------------------------------------------------------------------------------------------------------------
/// @file Particle.h
/// @brief constructor, udpates the particles, draws the particles, set and get methods are available
//--------------------------------------------------------------------------------------------------------------------
#include "Particle.h"

void Particle::update(float _deltaTime)
{
        m_velocity +=m_acceleration*_deltaTime;     // set the velocity of the particle
        m_position += m_velocity*_deltaTime;        // set the position of the particle
        m_lifeSpan += m_deltaLifeSpan*_deltaTime;   // set the lifespan of the particle
        m_transparency -= m_deltaTransparency*_deltaTime; // set the transparancy of the particle
        m_colour -= m_deltaColour*_deltaTime;       // set the colour of the particle
        m_size -= m_deltaSize*_deltaTime;           // set the size ofthe particle
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::draw()
{
    // enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //enables that the the transparency of the particle can change
    // colour for the particle
    glColor4f(m_colour.x, m_colour.y, m_colour.z, m_transparency);

    // shape of particle
     glEnable(GL_POINT_SMOOTH); // smooth the particles so they are not little squares
     glPointSize(m_size);
     glBegin(GL_POINTS);
     glVertex3f(m_position.x, m_position.y, m_position.z);
     glEnd();
}
//--------------------------------------------------------------------------------------------------------------------
int Particle::isDead()
{
    if( m_lifeSpan >= m_lifeLimit   || // if the lifespan is greater than the life limit; die
        m_position.x > 100          || // if the x-position is greater than 100; die ( the value 100 is the size of the cube)
        m_position.x < -100         || // idem for the y-, and z-position
        m_position.y > 100          ||
        m_position.y < -100         ||
        m_position.z > 100          ||
        m_position.z < -100         ||
        m_size <= 0                 || // if the size is zero or less; die
        m_transparency <= 0)           // if the transparancey is zero or less; die
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
void Particle::setTransparency(float _transparency)
{
    m_transparency = _transparency;
}
//--------------------------------------------------------------------------------------------------------------------
void Particle::setDeltaTransparency(float _deltaTransparency)
{
    m_deltaTransparency = _deltaTransparency;
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
void Particle::setDeltaLifeSpan(float _deltaLifeSpan)
{
    m_deltaLifeSpan = _deltaLifeSpan;
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
//--------------------------------------------------------------------------------------------------------------------
float Particle::getYPosition() const
{
    return m_position.y;
}
