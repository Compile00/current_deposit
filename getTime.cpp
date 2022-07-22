//获取时间函数
#include "headersfile.h"
string getTime()
{
    time_t t;
    time(&t);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d_%H:%M:%S", localtime(&t));

    return tmp;

}//获取当前时间函数
