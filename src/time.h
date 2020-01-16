#ifndef TIME
#define TIME

namespace utils 
{
    class Time 
    {
    private:
        static double   s_lastTime;
        static double   s_currentTime;
        static float    s_deltaTime;

    public:
        Time(double currentTime);

        void UpdateTime(double currentTime);

        static double getLastTime()     {   return Time::s_lastTime;    }
        static double getCurrentTime()  {   return Time::s_currentTime; }
        static float getDeltaTime()     {   return Time::s_deltaTime;   }
    };
}

#endif // !TIME
