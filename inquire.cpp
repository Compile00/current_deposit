//��ѯ�����˻���Ϣ��ĳ�˻����ͽ��׼�¼�Ĺ���
#include "headersfile.h"
void information(accountList L)
{
    int i;
    for (i = 1; i <= L.length; i++){
        cout <<"�˺�:"<<L.elem[i].ID << " ����:"<<L.elem[i].Name<<" ���:"<<L.elem[i].balance<<" "<<endl;
    }//��������˻���Ϣ
    cout<<"һ����"<<L.length<<"���˻�."<<endl;
	cout << endl;
}//���������˻���Ϣ


void balance_inquiry(accountList L, int i)
{
    cout<<"��Ҫ��ѯ���˺�:"<<L.elem[i].ID<<" ����:"<<L.elem[i].Name<<" ���:"<<L.elem[i].balance<<endl;
}//����ĳ�˻����

void record(accountList &L, int i)
{
    p_node_log p;
	p = L.elem[i].first_node_log;
	if (p == NULL){
        cout<<"���˻����׼�¼Ϊ��"<<endl;
	}else{
        while (p != NULL) {
		cout <<"����ʱ��:"<< p->DataTime <<"  ��ȡ��־(WΪȡ��, DΪ���):"<< p->W_D <<"  ���׽��:"<< p->balance <<endl;
		p = p->next;
        }
	}

}//��ѯ���˻��Ľ��׼�¼
