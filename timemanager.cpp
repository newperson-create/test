#include "timemanager.hpp"
#include "memory.h"

TimeManager::TimeManager()
{
    memset(m_time_buff, 0, sizeof(m_time_buff));
}

TimeManager & TimeManager::Instance()
{
    static TimeManager tmp;
    return tmp;
}

time_t TimeManager::GetTime()
{
    return time(nullptr);
}

 unsigned int TimeManager::GetUTime()
 {
     return static_cast<unsigned int>(this->GetTime());
 }

const tm* TimeManager::GetTimeOfTM(unsigned int timestamp)
 {
    time_t now_time = this->GetTime();
    if(0 != timestamp)
    {
        now_time = static_cast<time_t>(timestamp);
    }

#ifdef _WIN32
    ::localtime_s(&m_tm, &now_time);
#else
    ::localtime_r(&now_time, &m_tm);
#endif

    return &m_tm;
 }

 char* TimeManager::GetCurTimeFormat()
 {
     strftime(m_time_buff, sizeof(m_time_buff), "%Y-%m-%d %H:%M:%S", this->GetTimeOfTM());
     return m_time_buff;
 }