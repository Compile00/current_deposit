//查询所有账户信息、某账户余额和交易记录的功能
#include "headersfile.h"
void information(accountList L)
{
    int i;
    for (i = 1; i <= L.length; i++){
        cout <<"账号:"<<L.elem[i].ID << " 姓名:"<<L.elem[i].Name<<" 余额:"<<L.elem[i].balance<<" "<<endl;
    }//遍历输出账户信息
    cout<<"一共有"<<L.length<<"个账户."<<endl;
	cout << endl;
}//查找所有账户信息


void balance_inquiry(accountList L, int i)
{
    cout<<"您要查询的账号:"<<L.elem[i].ID<<" 姓名:"<<L.elem[i].Name<<" 余额:"<<L.elem[i].balance<<endl;
}//查找某账户余额

void record(accountList &L, int i)
{
    p_node_log p;
	p = L.elem[i].first_node_log;
	if (p == NULL){
        cout<<"该账户交易记录为空"<<endl;
	}else{
        while (p != NULL) {
		cout <<"交易时间:"<< p->DataTime <<"  存取标志(W为取款, D为存款):"<< p->W_D <<"  交易金额:"<< p->balance <<endl;
		p = p->next;
        }
	}

}//查询该账户的交易记录
