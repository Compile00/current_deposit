#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <fstream>
#define MAXSIZE 1000   //最多允许存放1000个账户信息
#define OVERFLOW -2     //状态字
#define ERROR 0         //状态字
#define OK 1           //状态字

typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
using namespace std;

typedef struct node_log//存取记录结点
{
   string DataTime; //存取时间
   char W_D;    //存取标志, "W"取款, "D"存款
   float balance;   //存取金额
   struct node_log *next;  //指向下一个存取记录结点
}node_log, *p_node_log;

typedef struct node_account
{
   int ID;  //账号
   string Name; //姓名
   float balance;  //余额
   struct node_log *first_node_log;  //指向本账户第一个存取记录结点
}node_account;


typedef struct account  //账户记录结点
{
    node_account *elem;      //存账户表基地址
    int length;       //存账户表的当前长度
}accountList;

