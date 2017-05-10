#ifndef EMITTER_H
#define EMITTER_H
#include "particle.h"
#include <vector>


class Emitter
{
public:
    /// @brief constructor for the emitter
    /// @param _numberOfParticles the number of particles in the container(emitter)
    /// @param _position the position of the emitter
    Emitter(int _numberOfParticles, glm::vec3 _positionE);
    /// @brief update method
    virtual void update(float _deltaTime)=0;
    /// @brief generate particles
//    virtual void generateParticles() = 0;
    /// @brief kill particles
    void killParticles();
    /// @brief draw method
    void draw();
    /// @brief method to run the program
    void run(float _deltaTime);



protected:
    /// @brief number of particles that the system has
    int m_numberOfParticles;
    /// @brief Emitter's position
    glm::vec3 m_positionEmitter;
    /// @brief store the particles in a list
    std::vector<Particle> m_listOfParticles;


};

#endif // EMITTER_H
