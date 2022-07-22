//存取款账户功能
#include "headersfile.h"
extern string getTime();
float  putinmoney(accountList &L, float money, int i )//存款
{
    p_node_log p;
    p = new node_log;
    p->DataTime = getTime(); //存取时间
    p->W_D = 'D';    //存取标志, "W"取款, "D"存款
    p->balance = money;
	p->next = L.elem[i].first_node_log;
	L.elem[i].first_node_log = p;
	L.elem[i].balance += money;
	return L.elem[i].balance;

}

float  putoutmoney(accountList &L, float money, int i ) //取款
{


	if(L.elem[i].balance - money<0){
        cout<<"取款失败,取出金额大于余额";
	}else{
        p_node_log p;
        p = new node_log;
        p->DataTime=getTime(); //存取时间
        p->W_D = 'W';          //存取标志, "W"取款, "D"存款
        p->balance = money;
        p->next = L.elem[i].first_node_log;
        L.elem[i].first_node_log = p;
        L.elem[i].balance -= money;
        cout<<"取款成功! 取出金额为: "<<money;
	}

	return L.elem[i].balance;//返回计算后的余额

}
