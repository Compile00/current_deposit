//�洢��ϢΪtxt�ı�,������������Ϣ
#include "headersfile.h"
extern int Search_Bin(accountList ST,int ID);
extern int tempnum;//�ⲿ�������tempnum
string head_1,head_2, head_3, head_4, head_5, head_6;


Status input_str(accountList &L)//���뺯��,��txt�ļ�����Ϣ�������Ա���
{
    int a;
    int i =  1;

    if (!L.elem)
        exit(OVERFLOW);
    fstream infile;
    fstream infile_2;

    infile.open("record.txt");
    if (!infile) {
        cout <<"����δ�ҵ��ļ�!"<< endl;
        exit(ERROR);
    }//�򿪵�һ���ļ�

    infile_2.open("record2.txt");
    if (!infile_2) {
        cout <<"����δ�ҵ��ļ�!"<< endl;
        exit(ERROR);
    }//�򿪵ڶ����ļ�

    infile >> head_1 >> head_2 >> head_3;  //�Ƚ�"record.txt"�ļ���һ�еı����ַ�������������ݴ�

    while (!infile.eof()){
        infile >> L.elem[i].ID >> L.elem[i].Name >> L.elem[i].balance;

        L.elem[i].first_node_log = NULL;
        i++;
    } //�ӵ�һ���ļ��ĵڶ��п�ʼ�����˺���Ϣ��������˳�������ÿ���˻��ļ�¼����Ϊ��


    L.length = i-2;//���Ա�ĳ���


    infile_2>>head_1>>head_4>>head_5>>head_6;  //�Ƚ�"record2.txt"�ļ���һ�еı����ַ�������������ݴ�

    while(!infile_2.eof()){

        p_node_log p;
        p = new node_log;
        infile_2>>a>>p->DataTime>>p->W_D>>p->balance;
        int num = Search_Bin(L, a); //ͨ���۰����, �ҵ���Ӧ�˻��Ľ��׼�¼
        p->next = L.elem[num].first_node_log;
        L.elem[num].first_node_log = p;
        a = 0;//����a��ֵΪ0

    }//�ӵڶ����ļ��ĵڶ��п�ʼ����"���׼�¼"��Ϣ

    cout <<"������Ϣ���!"<<endl;

    infile.close();
    infile_2.close(); //�ر�infile�������Ĵ����ļ�
    if(L.length != 0){
        tempnum =  L.elem[i-2].ID;
    }//����������Ϣ�ǿ�, �ͼ����õ�����Ϣ�˺ŵ���һ���˻�,����ԭ�����˺��ϼ�1����,��֤�˺��Ǵ�С������.
    return OK;
}


Status output_str( accountList &L)//����Ϣ���浽txt�ļ���, ͬʱҲ���Ը���txt�ļ��е���Ϣ
{



    ofstream outfile("record.txt", ios::out);//�����ļ������󣬴������߸��ǵ�record.txt�ļ�; record����û���Ϣ
    ofstream outfile_2("record2.txt", ios::out);//record2�ļ���Ž�����Ϣ��¼


    if(!outfile){
        cerr <<"record.txt�򿪳���!"<<endl;
        exit(0);
    }

    if(!outfile_2){
        cerr <<"record2.txt�򿪳���!"<<endl;
        exit(0);
    }


    head_1 = "�˺�\t";
    head_2 = "����\t";
    head_3 = "���\t";
    outfile<<head_1<<head_2<<head_3<<endl; //���txt�ļ��Ĵ����Ϣ��Ӧ�ı���

    head_4 = "����ʱ��\t";
    head_5 = "��ȡ��־\t";
    head_6 = "���׽��\t";

    outfile_2<<head_1<<head_4<<head_5<<head_6<<endl;//���txt�ļ��Ĵ����Ϣ��Ӧ�ı���

    for(int i=1;i<=L.length; i++ ){
        outfile<<L.elem[i].ID<<"\t"<<L.elem[i].Name<<"\t"<<L.elem[i].balance<<"\t";

        outfile<<endl;
        p_node_log p;
        p = L.elem[i].first_node_log;

        while (p != NULL) {
                    outfile_2 <<L.elem[i].ID<<"\t"<< p->DataTime<<"\t"<< p->W_D <<"\t"<< p->balance<<"\t";
                    p = p->next;
                    outfile_2<<endl;
        }

    }

    outfile.close();
    outfile_2.close();
    cout<<"�����¼�ɹ�!"<<endl;
    return OK;

}
