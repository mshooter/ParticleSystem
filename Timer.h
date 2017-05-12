#ifndef TIMER_H
#define TIMER_H

#include "SDL2/SDL.h"

/// \author Moira Shooter
/// \version 1.0
/// \date Last Revision

/// \class Timer
/// \brief This creates a timer, and calculates the elapsed time and has its set and get methos
/// \todo

class Timer
{
public:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the default constructor for timer
    //--------------------------------------------------------------------------------------------------------------------
    Timer();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief accessor function that access the elapsed time for the camera animation
    //--------------------------------------------------------------------------------------------------------------------
    float CameraTime() const;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief accessor function that access the elapsed time for the particle system animation
    //--------------------------------------------------------------------------------------------------------------------
    float DeltaTime() const;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief accessor function that acces the negative elapsed time forthe particle system animation
    //--------------------------------------------------------------------------------------------------------------------
    float ReverseTime() const;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief mutator function that sets the timer when the animation end particle system
    /// @param[in] _endTime the time when the updating is finished
    //--------------------------------------------------------------------------------------------------------------------
    void setEndTime(float _endTime);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief mutator function that sets the delta time (endTime-startTime)
    /// @param[in] _deltaTime the time difference of the finished timer and the start timer
    //--------------------------------------------------------------------------------------------------------------------
    void setDeltaTime(float _deltaTime);
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that pauses the time
    //--------------------------------------------------------------------------------------------------------------------
    void pauseTimer();
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief function that unpause the time
    //--------------------------------------------------------------------------------------------------------------------
    void unPauseTimer();

private:
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the value when the timer starts
    //--------------------------------------------------------------------------------------------------------------------
    float m_startTime;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the value when the timer ends
    //--------------------------------------------------------------------------------------------------------------------
    float m_endTime;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the elapsed time for the animation of the camera
    //--------------------------------------------------------------------------------------------------------------------
    float m_cameraTime;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the elapsed time for the animation of the particle system
    //--------------------------------------------------------------------------------------------------------------------
    float m_deltaTime;
    //--------------------------------------------------------------------------------------------------------------------
    /// @brief the negative value of the elapsed time for the animation of the particle system
    //--------------------------------------------------------------------------------------------------------------------
    float m_reverseTime;


};

#endif // TIMER_H
