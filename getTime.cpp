//��ȡʱ�亯��
#include "headersfile.h"
string getTime()
{
    time_t t;
    time(&t);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d_%H:%M:%S", localtime(&t));

    return tmp;

}//��ȡ��ǰʱ�亯��
