#ifndef __SERVER_COMMON_HPP__
#define __SERVER_COMMON_HPP__

#include "timemanager.hpp"
#include <random>

// 颜色
#define NONE            "\033[m"
#define LIGHT_RED       "\033[1;31m" 
#define GREEN           "\033[0;32m"
#define LIGHT_GREEN     "\033[1;32m"

// #define DEBUG_PRINT(format, ...) \
//     printf(LIGHT_GREEN"[%s] " format NONE"\n", TimeManager::Instance().GetCurTimeFormat(), ##__VA_ARGS__);\

#define DEBUG_PRINT(format, ...) \
    printf(LIGHT_RED"[%s] " format NONE"\n", TimeManager::Instance().GetCurTimeFormat(), __VA_ARGS__);\

#define ARRAY_REAL_SIZE(a) (static_cast<int>(sizeof(a) / sizeof(*a)));

#define SERVERCOMMON ServerCommon::Instance()

class ServerCommon
{
public:
    static ServerCommon& Instance();

    int RandomNum(int min_num, int max_num);
    int RandomNum(int max_num);

private:
    ServerCommon();
    ServerCommon(const ServerCommon& other) = delete;
    ServerCommon& operator=(const ServerCommon& other) = delete;

private:
    std::mt19937 m_rand;
};

#endif