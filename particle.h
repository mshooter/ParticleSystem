#ifndef PARTICLE_H
#define PARTICLE_H
#include "glm/glm.hpp"


class Particle
{
public:
    // constructor
    Particle(glm::vec3 _position);


    /// @brief method to update the particle's position
    void update();

    /// @brief method to draw the particle
    void draw();

    /// @brief method that checks if the particle is dead
    int isDead();

    /// @brief set method: position
    /// @param _position, the position of the particle
    void setPosition(glm::vec3 _position);

    /// @brief set method: velocity
    /// @param _velocity, the velocity of the particle
    void setVelocity(glm::vec3 _velocity);

    /// @brief set method: colour
    /// @param _colour, the colour of the particle
    void setColour(glm::vec3 _colour);

    /// @brief set method: transparency
    /// @param _transparency, the transparancy of the particle
    void setTransparency(float _transparency);

    /// @brief set method: size
    /// @param _size, the size of the particle
    void setSize(float _size);

    /// @brief set method: lifespan
    /// @param _lifespan, the lifespan of the particle
    void setLifeSpan(float _lifeSpan);

    /// @brief set method: lifelimit
    /// @param _lifelimit, the lifelimit of the particle
    void setLifeLimit(float _lifeLimit);

    /// @brief get method: gets the position
    glm::vec3 getPosition() const;


private:

    /// @brief Particles currents position
    glm::vec3 m_position;
    /// @brief Particle's current velocity
    glm::vec3 m_velocity;
    /// @brief Particle's colour+transperency
    glm::vec3 m_colour;
    /// @brief Particles's Transparancy
    float m_transparency;
    /// @brief Particle's size
    float m_size;
    /// @brief Particle's lifeSpan (how long the particle has been alive)
    float m_lifeSpan;
    /// @brief Particle's lifeLimit
    float m_lifeLimit;

    /// @brief Particle's mass to play with forces?
    /// float m_mass;
};

#endif // PARTICLE_H
