#ifndef __SERVER_COMMON_HPP__
#define __SERVER_COMMON_HPP__

#include "timemanager.hpp"

// 颜色
#define NONE            "\033[m"
#define RED             "\033[0:32:31m"
#define GREEN           "\033[0:32:32m"
#define LIGHT_GREEN     "\033[1:32:32m"

// #define DEBUG_PRINT(format, ...) \
//     printf(LIGHT_GREEN"[%s] " format NONE"\n", TimeManager::Instance().GetCurTimeFormat(), ##__VA_ARGS__);

#define DEBUG_PRINT(format, ...) \
    printf(LIGHT_GREEN"[%s] " format NONE"\n", TimeManager::Instance().GetCurTimeFormat(), __VA_ARGS__);

#define ARRAY_REAL_SIZE(a) (static_cast<int>(sizeof(a) / sizeof(*a)));

class ServerCommon
{
public:
    
};

#endif