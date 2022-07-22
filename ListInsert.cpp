#include "headersfile.h"
int tempnum = 100000;//设置初始账号为100000
int ListInsert(accountList &L, int i, node_account e)
{

    if (L.length == MAXSIZE ||  L.length > MAXSIZE){
        return ERROR; //当前存储空间已满
    }

    e.ID = tempnum + 1;
    e.balance = 0.00;
    cout<<"您的6位数帐号是:"<<e.ID<<endl;
    cout<<"您的姓名为:"<<e.Name<<endl;
    cout<<"您账户余额为"<<e.balance<<"元"<<endl;
    L.elem[i] = e;
    L.elem[i].first_node_log = NULL;
    ++L.length;
    return tempnum ++;

}//开户时插入账户
