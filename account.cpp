//��ȡ���˻�����
#include "headersfile.h"
extern string getTime();
float  putinmoney(accountList &L, float money, int i )//���
{
    p_node_log p;
    p = new node_log;
    p->DataTime = getTime(); //��ȡʱ��
    p->W_D = 'D';    //��ȡ��־, "W"ȡ��, "D"���
    p->balance = money;
	p->next = L.elem[i].first_node_log;
	L.elem[i].first_node_log = p;
	L.elem[i].balance += money;
	return L.elem[i].balance;

}

float  putoutmoney(accountList &L, float money, int i ) //ȡ��
{


	if(L.elem[i].balance - money<0){
        cout<<"ȡ��ʧ��,ȡ�����������";
	}else{
        p_node_log p;
        p = new node_log;
        p->DataTime=getTime(); //��ȡʱ��
        p->W_D = 'W';          //��ȡ��־, "W"ȡ��, "D"���
        p->balance = money;
        p->next = L.elem[i].first_node_log;
        L.elem[i].first_node_log = p;
        L.elem[i].balance -= money;
        cout<<"ȡ��ɹ�! ȡ�����Ϊ: "<<money;
	}

	return L.elem[i].balance;//���ؼ��������

}
