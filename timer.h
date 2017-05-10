#ifndef TIMER_H
#define TIMER_H

#include "SDL2/SDL.h"


class Timer
{
public:
    /// @build constructor
    Timer();

    /// @build get method: gets the value of the time for the animation camera
    float getCameraTime() const;
    /// @build get method: gets the delta time for the animation of particle system
    float getDeltaTime() const;

    /// @build set method: sets the timer when the animation end particle system
    void setEndTime(float _endTime);
    /// @build set method: sets the delta time
    void setDeltaTime(float _deltaTime);

    /// @build pause the timer
    void pauseTimer();
    /// @build restarts the timer
    void unPauseTimer();

private:
    float m_startTime;
    float m_endTime;
    float m_pauseTime;
    float m_cameraTime;
    float m_deltaTime;

};

#endif // TIMER_H
