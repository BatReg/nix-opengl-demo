#include "game_time.h"

namespace utils 
{
    double  GameTime::s_currentTime = 0.0;
    double  GameTime::s_lastTime    = 0.0;
    float   GameTime::s_deltaTime   = 0.0f;

    GameTime::GameTime(double currentTime)
    {        
        updateTime(currentTime);
    }

    void GameTime::updateTime(double currentTime) 
    {
        s_lastTime = s_currentTime;
        s_currentTime = currentTime;
        s_deltaTime = static_cast<float>(s_currentTime - s_lastTime);
    }
}