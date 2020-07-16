#ifndef __TIME_MANAGER_HPP__
#define __TIME_MANAGER_HPP__

#include <ctime>

class TimeManager
{
private:
    struct tm m_tm;
    char m_time_buff[128];
public:
    static TimeManager& Instance();

    time_t GetTime();
    unsigned int GetUTime();
    const tm* GetTimeOfTM(unsigned int timestamp = 0);

    char* GetCurTimeFormat();
private:
    TimeManager();
    TimeManager(const TimeManager& tmp) = delete;
    TimeManager& operator=(const TimeManager& tmp) = delete;
};

#endif