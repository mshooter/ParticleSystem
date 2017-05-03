#ifndef FIREWORKS_H
#define FIREWORKS_H
#include "emitter.h"

class Fireworks : public Emitter
{
public:
    Fireworks(int _numberOfParticles,  glm::vec3 _positionfFireworks);
    void update() override;
};

#endif // FIREWORKS_H
