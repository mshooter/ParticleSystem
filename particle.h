#ifndef PARTICLE_H
#define PARTICLE_H
#include "glm/glm.hpp"

class Particle
{
public:
    // constructor
    Particle(glm::vec3 _position/*, glm::vec3 _velocity, glm::vec3 _colour*/, float _size, float _lifeLimit);

    /// @brief method to update the particle's position
    void update();

    /// @brief method to draw the particle
    void draw();

    /// @brief method that checks if the particle is dead
    int isDead();

    /// @reset mode
    void reset();


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
