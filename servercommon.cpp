#include "servercommon.hpp"

ServerCommon& ServerCommon::Instance()
{
    static ServerCommon instance;
    return instance;
}

ServerCommon::ServerCommon()
{
    m_rand.seed(time(nullptr));
}

int ServerCommon::RandomNum(int min_num, int max_num)
{
    if(min_num > max_num)
    {
        int tmp = min_num;
        min_num = max_num;
        max_num = tmp;
    }

    unsigned short low_bit = m_rand();
    unsigned short high_bit = m_rand();
    int i = low_bit;
    i |= (high_bit << 15);

    i = i % (max_num - min_num) + min_num;

    return i;
}

int ServerCommon::RandomNum(int max_num)
{
    return this->RandomNum(0, max_num);
}