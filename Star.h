#ifndef STAR_H
#define STAR_H

#include "Emitter.h"

class Star : public Emitter
{
public:
    Star(int _numberOfParticles, glm::vec3 _position);
    void update(float _deltaTime) override;
    void generateParticles(glm::vec3 _originalPosition);
};

#endif // STAR_H
