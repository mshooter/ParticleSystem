#ifndef FIRE_H
#define FIRE_H
#include "emitter.h"

class Fire : public Emitter
{
public:
    /// @build fire constructor
    /// @param _numberOfParticles: the number of particles in the emitter
    /// @param _positionEmitter: the position of the Emitter
    Fire(int _numberOfParticles, glm::vec3 _positionEmitter);
    /// @build update function for fire emitter
    void update() override;
};

#endif // FIRE_H
