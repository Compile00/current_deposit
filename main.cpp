#include "headersfile.h"
#include "extern.h"

int main()
{
    int s, i, id, num;
    float d, money;
    accountList L;
    L.elem = new node_account[MAXSIZE]; //����һ���յ��˻���
    L.length = 0;
    node_account e;
    string DataTime;

    input_str(L);//������Ϣ

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|            ���ڴ�����Ŀ����ϵͳ                |"<<endl;
    cout<<"|  1.����                                        |"<<endl;
    cout<<"|  2.����                                        |"<<endl;
    cout<<"|  3.��ĳ�˻����                                |"<<endl;
    cout<<"|  4.��ĳ�˻�ȡ��                                |"<<endl;
    cout<<"|  5.��ʾ�����˺���Ϣ                            |"<<endl;
    cout<<"|  6.��ѯĳ�˻����                              |"<<endl;
    cout<<"|  7.��ѯĳ�˻����׼�¼                          |"<<endl;
    cout<<"|  0.�˳�����(���±����¼)                      |"<<endl;
    cout<<"|================================================|"<<endl;
    cout<<"����ѡ���";
    cin>>s;
    while(s!=0){
         switch(s){
            case 1:
                i = L.length + 1;
                cout<<"��ѡ�����ĿΪ:����"<<endl;
                cout<<"����������: ";
                cin>>e.Name;
                ListInsert(L, i, e);
                cout<<"�˻������ɹ�!������ɿ�������,���ס�����˺�"<<endl;
                DataTime = getTime();
                cout<<"��ǰʱ��Ϊ:"<<DataTime<<endl;
                cout<<endl;
                break;
            case 2:
                cout<<"��ѡ�����ĿΪ:����"<<endl;
                cout<<"������Ҫ���ҵ��˺�:";
                cin>>id;
                i = Search_Bin(L, id);//���۰���Ҷ�λ��������λ��
                if(i == -1){
                    cout<<"��������˺Ų�����,�����������"<<endl;
                }else if(L.elem[i].balance != 0){
                    cout<<"���˻���Ϊ0,��������!"<<endl;
                }else{
                    ListDelete(L, i);
                    cout<<"�����ɹ�!"<<endl;
                }
                cout<<endl;
                break;

            case 3:
                cout<<"��ѡ�����ĿΪ:��ĳ�˻����"<<endl;
                cout<<"������Ҫ�����˺�:";
                cin>>id;
                i = Search_Bin(L, id);//���۰���Ҷ�λ��������λ��
                if(i== -1){
                    cout<<"��������˺Ų�����,�����������"<<endl;
                }else{
                    cout<<"������Ҫ���Ľ��:";
                    cin>>money;
                    while(money<=0){
                        cout<<"���������, �����������0"<<endl;
                        cout<<"����������:";
                        cin>>money;
                    }
                    d = putinmoney(L, money, i );
                    cout<<"���ɹ�! ������Ϊ: "<<money<<"  �������Ϊ:"<<d<<endl;
                }
                DataTime = getTime();
                cout<<"��ǰʱ��Ϊ:"<<DataTime<<endl;
                cout<<endl;
                break;
            case 4:
                cout<<"��ѡ�����ĿΪ:��ĳ�˻�ȡ��"<<endl;
                cout<<"������Ҫ�����˺�:";
                cin>>id;
                i = Search_Bin(L, id);//���۰���Ҷ�λ������±�
                if(i== -1){
                    cout<<"��������˺Ų�����,�����������"<<endl;
                }else{
                    cout<<"������Ҫȡ��Ľ��:";
                    cin>>money;
                    while(money<=0){
                        cout<<"���������, ȡ����������0"<<endl;
                        cout<<"����������:";
                        cin>>money;
                    }
                    d = putoutmoney(L, money, i );
                    cout<<"  �������Ϊ:"<<d<<endl;
                }
                DataTime = getTime();
                cout<<"��ǰʱ��Ϊ:"<<DataTime<<endl;
                break;

            case 5:
                cout<<"��ѡ�����ĿΪ:��ʾ�����˺���Ϣ"<<endl;
                information(L);
                break;
            case 6:
                cout<<"��ѡ�����ĿΪ:��ѯĳ�˻����"<<endl;
                cout<<"������Ҫ��ѯ���˺�:";
                cin>>id;
                i = Search_Bin(L, id);//���۰���Ҷ�λ������±�
                if(i== -1){
                    cout<<"��������˺Ų�����,�����������"<<endl;
                }else{
                    balance_inquiry(L, i);
                    cout<<"�˻�����ѯ�ɹ�!"<<endl;
                }
                break;
            case 7:
                cout<<"��ѡ�����ĿΪ:��ѯĳ�˻����׼�¼  "<<endl;
                cout<<"������Ҫ��ѯ���˺�:";
                cin>>id;
                i = Search_Bin(L, id);//���۰���Ҷ�λ������±�
                if(i== -1){
                    cout<<"��������˺Ų�����,�����������"<<endl;
                }else{
                    record(L, i);
                    cout<<"�˻����׼�¼��ѯ�ɹ�!"<<endl;
                }
                break;
            default:
                output_str(L);//����Ϣд���ļ���;���±�����Ϣ
                break;
        }
        cout<<endl;
        cout<<"����ѡ���";
        cin>>s;
    }

    output_str(L);//����Ϣд���ļ���;���±�����Ϣ
    cout<<"�Ѿ��˳�����!"<<endl;

    return 0;
}
