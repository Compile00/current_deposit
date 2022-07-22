#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <fstream>
#define MAXSIZE 1000   //���������1000���˻���Ϣ
#define OVERFLOW -2     //״̬��
#define ERROR 0         //״̬��
#define OK 1           //״̬��

typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
using namespace std;

typedef struct node_log//��ȡ��¼���
{
   string DataTime; //��ȡʱ��
   char W_D;    //��ȡ��־, "W"ȡ��, "D"���
   float balance;   //��ȡ���
   struct node_log *next;  //ָ����һ����ȡ��¼���
}node_log, *p_node_log;

typedef struct node_account
{
   int ID;  //�˺�
   string Name; //����
   float balance;  //���
   struct node_log *first_node_log;  //ָ���˻���һ����ȡ��¼���
}node_account;


typedef struct account  //�˻���¼���
{
    node_account *elem;      //���˻������ַ
    int length;       //���˻���ĵ�ǰ����
}accountList;

