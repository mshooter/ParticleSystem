#ifndef FIRE_H
#define FIRE_H
#include "emitter.h"

class Fire : public Emitter
{
public:
    Fire(int _numberOfParticles, glm::vec3 _positionEmitter);
    void update() override;
};

#endif // FIRE_H
