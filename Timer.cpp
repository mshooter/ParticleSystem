/// @file Timer.h
/// @brief set the constructor, set and get methods

#include "Timer.h"

/// back in time negative delta time
Timer::Timer()
{
    m_startTime = SDL_GetTicks();
    m_endTime = 0;
    // for computers at uni devide by 1000
    // for my personal pc devide by 2500
    m_cameraTime = (m_startTime - m_endTime)/2500;
    m_deltaTime =  (m_startTime - m_endTime)/2500;
    m_pause = false;
    m_slowMotion = m_cameraTime/4;
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
float Timer::getSlowMow() const
{
    return m_slowMotion;
}
//--------------------------------------------------------------------------------------------------------------------
bool Timer::getPause() const
{
    return m_pause;
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
    // sets back the pause button to false
    m_pause = true;
    setDeltaTime(0);
}
//--------------------------------------------------------------------------------------------------------------------
void Timer::unPauseTimer()
{
    // sets back the pause button to true
    m_pause = false;
    setDeltaTime(CameraTime());
}
