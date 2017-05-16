#ifndef PARTICLE_H
#define PARTICLE_H
/// @file Particle.h
/// @brief A Particle class, with all its variables and mutator/accessor functions
#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include <iostream>
#include <cmath>
#include "glm/glm.hpp"
#include "SDL2/SDL.h"

/// \author Moira Shooter
/// \version
/// \date Last Revision 16 MAY 2017

/// \class Particle
/// \brief Creates the particle, has an update function and a draw functions, and get and sets methods
/// \todo


class Particle
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the default constructor for particle
    //--------------------------------------------------------------------------------------------------------------------
    Particle(){;}
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function to update the particle's position
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    void update(float _deltaTime);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function to draw the particle
    //--------------------------------------------------------------------------------------------------------------------
    void draw();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that checks if the particle is dead
    //--------------------------------------------------------------------------------------------------------------------
    int isDead();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that set the position of the particle
    /// @param[in] _position the position of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setPosition(glm::vec3 _position);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the velocity of the particle
    /// @param[in] _velocity the velocity of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setVelocity(glm::vec3 _velocity);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the colour of the particle
    /// @param[in] _colour the colour of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setColour(glm::vec3 _colour);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the delta colour of the particle
    /// @param[in] _deltaColour the delta colour of of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setDeltaColour(glm::vec3 _deltaColour);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the transparency of the particle
    /// @param[in] _transparency the transparancy of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setTransparency(float _transparency);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the delta transparency of the particle
    /// @param[in] _deltaTransparency the delta transparancy of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setDeltaTransparency(float _deltaTransparency);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the size of the particle
    /// @param[in] _size the size of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setSize(float _size);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the delta size of the particle
    /// @param[in] _deltaSize the delta size of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setDeltaSize(float _deltaSize);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the lifespan of the particle
    /// @param[in] _lifespan the lifespan of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setLifeSpan(float _lifeSpan);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the delta lifespan of the particle
    /// @param[in] _deltaLifespan the delta lifespan of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setDeltaLifeSpan(float _deltaLifeSpan);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief funciton that sets the life limit of the particle
    /// @param[in] _lifelimit the lifelimit of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setLifeLimit(float _lifeLimit);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that sets the acceleration of the particle
    /// @param[in] _acceleration the acceleration of the particle
    //--------------------------------------------------------------------------------------------------------------------
    void setAcceleration(glm::vec3 _acceleration);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief accessor function that access the y position of the particles
    //--------------------------------------------------------------------------------------------------------------------
    float getYPosition() const;


private:

    //--------------------------------------------------------------------------------------------------------------------
    /// @brief position of the particle
    //--------------------------------------------------------------------------------------------------------------------
    glm::vec3 m_position;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief velocity of the particle
    //--------------------------------------------------------------------------------------------------------------------
    glm::vec3 m_velocity;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief acceleration of the particle
    //--------------------------------------------------------------------------------------------------------------------
    glm::vec3 m_acceleration;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief colour of the particle
    //--------------------------------------------------------------------------------------------------------------------
    glm::vec3 m_colour;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief delta colour of the particle
    //--------------------------------------------------------------------------------------------------------------------
    glm::vec3 m_deltaColour;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief alpha channel of the particle (transparency)
    //--------------------------------------------------------------------------------------------------------------------
    float m_transparency;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief delta alpha channel of the particle
    //--------------------------------------------------------------------------------------------------------------------
    float m_deltaTransparency;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the size of the particle
    //--------------------------------------------------------------------------------------------------------------------
    float m_size;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the change of size of the particle
    //--------------------------------------------------------------------------------------------------------------------
    float m_deltaSize;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the lifespan of the particle; shows how long the particle has been alive
    //--------------------------------------------------------------------------------------------------------------------
    float m_lifeSpan;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the delta lifespan of the particle; shows how long the particle has been alive
    //--------------------------------------------------------------------------------------------------------------------
    float m_deltaLifeSpan;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the life limit of the particle; till when the particle can be alive
    //--------------------------------------------------------------------------------------------------------------------
    float m_lifeLimit;


};

#endif // PARTICLE_H