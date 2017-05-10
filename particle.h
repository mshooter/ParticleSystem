#ifndef PARTICLE_H
#define PARTICLE_H
#include "glm/glm.hpp"

/// We should make delta-members so we can change when update for different particle effects
/// and set methods to set the delta-members

class Particle
{
public:

    /// @brief constructor
    Particle();

    /// @brief method to update the particle's position
    void update();

    /// @brief method to draw the particle
    void draw();

    /// @brief method that checks if the particle is dead
    int isDead();

    /// @brief set method: position
    /// @param _position, the position of the particle
    void setPosition(glm::vec3 _position);

    /// @brief get method: position
    float getYPosition() const;

    /// @brief set method: velocity
    /// @param _velocity, the velocity of the particle
    void setVelocity(glm::vec3 _velocity);

    /// @brief get velocidy method
    float getVelocity_Y() const;

    /// @brief set method: colour
    /// @param _colour, the colour of the particle
    void setColour(glm::vec3 _colour);

    /// @brief set method: delta Colour
    void setDeltaColour(glm::vec3 _deltaColour);

    /// @brief set method: transparency
    /// @param _transparency, the transparancy of the particle
    void setTransparency(float _transparency);

    /// @brief set method: size
    /// @param _size, the size of the particle
    void setSize(float _size);

    /// @brief set method: deltaSize
    void setDeltaSize(float _deltaSize);

    /// @brief set method: lifespan
    /// @param _lifespan, the lifespan of the particle
    void setLifeSpan(float _lifeSpan);

    /// @brief set method: lifelimit
    /// @param _lifelimit, the lifelimit of the particle
    void setLifeLimit(float _lifeLimit);

    /// @brief set method: set life
    void setLife(int _alive);

    /// @brief get method; returns if the particle is alive or not
    int getLife() const;

    /// @brief set acceleration
    void setAcceleration(glm::vec3 _acceleration);


private:

    /// @brief Particles currents position
    glm::vec3 m_position;
    glm::vec3 m_oldPosition;
    /// @brief Particle's current velocity
    glm::vec3 m_velocity;
    /// @brief Particle's acceleration
    glm::vec3 m_acceleration;
    /// @brief Particle's colour+transperency
    glm::vec3 m_colour;
    /// @brief Particl's deltaColour
    glm::vec3 m_deltaColour;
    /// @brief Particles's Transparancy
    float m_transparency;
    /// @brief Particle's size
    float m_size;
    /// @brief Particle's deltaSize
    float m_deltaSize;
    /// @brief Particle's lifeSpan (how long the particle has been alive)
    float m_lifeSpan;
    /// @brief Particle's lifeLimit
    float m_lifeLimit;
    /// @brief Particle alive or not
    int m_alive=0;




    /// @brief Particle's mass to play with forces?
    /// float m_mass;
};

#endif // PARTICLE_H
