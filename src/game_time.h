#ifndef GAME_TIME
#define GAME_TIME

namespace utils 
{
    class GameTime 
    {
    private:
        static double   s_lastTime;
        static double   s_currentTime;
        static float    s_deltaTime;

    public:
        GameTime(double currentTime);

        void updateTime(double currentTime);

        static double getLastTime()     {   return s_lastTime;    }
        static double getCurrentTime()  {   return s_currentTime; }
        static float getDeltaTime()     {   return s_deltaTime;   }
    };
}

#endif // !GAME_TIME
