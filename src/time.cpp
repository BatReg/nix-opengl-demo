#include "time.h"

namespace utils 
{
    double  Time::s_currentTime = 0.0;
    double  Time::s_lastTime = 0.0;
    float   Time::s_deltaTime = 0.0f;

    Time::Time(double currentTime)
    {        
        UpdateTime(currentTime);
    }

    void Time::UpdateTime(double currentTime) 
    {
        s_lastTime = s_currentTime;
        s_currentTime = currentTime;
        s_deltaTime = static_cast<float>(s_currentTime - s_lastTime);
    }
}