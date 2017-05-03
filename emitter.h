#ifndef EMITTER_H
#define EMITTER_H
#include "particle.h"
#include <vector>

/// The emitter should generate each particle one by one.
/// Check formula
/// We should have a std::vector <Particle>::iterator ? and then swap the particle vector and the iterator vector: std::particle vector is the particles that zre alive

class Emitter
{
public:
    /// @brief constructor for the emitter
    /// @param _numberOfParticles the number of particles in the container(emitter)
    /// @param _position the position of the emitter
    Emitter(int _numberOfParticles, glm::vec3 _positionE);
    /// @brief update method
    virtual void update()=0;
    /// @brief draw method
    void draw();
    /// @brief method to run the program
    void run();

protected:
    /// @brief number of particles that the system has
    int m_numberOfParticles;
    /// @brief Emitter's position
    glm::vec3 m_positionEmitter;
    /// @brief store the particles in a list
    std::vector<Particle> m_listOfParticles;

};

#endif // EMITTER_H
