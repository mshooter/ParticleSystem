#ifndef WATERFALL_H
#define WATERFALL_H
/// @file WaterFall.h
/// @brief A Emitter class called Waterall, generates a simple waterfall
#include "Emitter.h"

/// \author Moira Shooter
/// \version
/// \date Last Revision 16 MAY 2017

/// \class Waterfall
/// \brief Creates a waterfall emitter, with its constructor, destructor, and update function
/// \todo make a double leveled waterfall

class Waterfall : public Emitter
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief constructor for the Waterfall emitter
    /// @param[in] _numberOfParticles the number of particles in the emitter
    /// @param[in] _position the position of the emitter
    //--------------------------------------------------------------------------------------------------------------------
    Waterfall(int _numberOfParticles, glm::vec3 _position);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief destructor for the Waterfall emitter
    //--------------------------------------------------------------------------------------------------------------------
    ~Waterfall(){;}
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the override function update for the waterfall emitter
    /// @param[in] _deltaTime the elapsed time that updated the last frame
    //--------------------------------------------------------------------------------------------------------------------
    void update(float _deltaTime) override;

};

#endif // WATERFALL_H
