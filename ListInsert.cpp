#include "headersfile.h"
int tempnum = 100000;//���ó�ʼ�˺�Ϊ100000
int ListInsert(accountList &L, int i, node_account e)
{

    if (L.length == MAXSIZE ||  L.length > MAXSIZE){
        return ERROR; //��ǰ�洢�ռ�����
    }

    e.ID = tempnum + 1;
    e.balance = 0.00;
    cout<<"����6λ���ʺ���:"<<e.ID<<endl;
    cout<<"��������Ϊ:"<<e.Name<<endl;
    cout<<"���˻����Ϊ"<<e.balance<<"Ԫ"<<endl;
    L.elem[i] = e;
    L.elem[i].first_node_log = NULL;
    ++L.length;
    return tempnum ++;

}//����ʱ�����˻�
