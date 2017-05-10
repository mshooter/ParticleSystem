#ifndef FIREWORKS_H
#define FIREWORKS_H
#include "emitter.h"

class Fireworks : public Emitter
{
public:
    /// @build constructor
    Fireworks(int _numberOfParticles,  glm::vec3 _positionfFireworks);
    /// @build udpate function
    void update(float _deltaTime) override;
    /// @build explode method
    void explode();
};

#endif // FIREWORKS_H
