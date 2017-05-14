/// @file Timer.h
/// @brief set the constructor, set and get methods

#include "Timer.h"

/// back in time negative delta time
Timer::Timer()
{
    m_startTime = SDL_GetTicks();
    m_endTime = 0;
    m_cameraTime = (m_startTime - m_endTime)/2500;
    m_deltaTime =  (m_startTime - m_endTime)/2500;
    m_reverseTime = -(4*m_cameraTime);

}
//--------------------------------------------------------------------------------------------------------------------
float Timer::CameraTime() const
{
    return m_cameraTime;
}
//--------------------------------------------------------------------------------------------------------------------
float Timer::DeltaTime() const
{
    return m_deltaTime;
}
//--------------------------------------------------------------------------------------------------------------------
float Timer::ReverseTime() const
{
    return m_reverseTime;
}
//--------------------------------------------------------------------------------------------------------------------
void Timer::setDeltaTime(float _deltaTime)
{
    m_deltaTime = _deltaTime;
}
//--------------------------------------------------------------------------------------------------------------------
void Timer::setEndTime(float _endTime)
{
    m_endTime = _endTime;
}
//--------------------------------------------------------------------------------------------------------------------
void Timer::pauseTimer()
{
    setDeltaTime(0);
}
//--------------------------------------------------------------------------------------------------------------------
void Timer::unPauseTimer()
{
    setDeltaTime(CameraTime());
}


