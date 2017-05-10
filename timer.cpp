#include "timer.h"

Timer::Timer()
{
    m_startTime = SDL_GetTicks();
    m_endTime = 0;
    m_pauseTime = 0;
    m_cameraTime = (m_startTime - m_endTime)/2500;
    m_deltaTime =  (m_startTime - m_endTime)/2500;

}

float Timer::getCameraTime() const
{
    return m_cameraTime;
}

float Timer::getDeltaTime() const
{
    return m_deltaTime;
}

void Timer::setDeltaTime(float _deltaTime)
{
    m_deltaTime = _deltaTime;
}

void Timer::setEndTime(float _endTime)
{
    m_endTime = _endTime;
}

void Timer::pauseTimer()
{
    setDeltaTime(0);
}

void Timer::unPauseTimer()
{
    setDeltaTime(getCameraTime());
}
