//存储信息为txt文本,并输入和输出信息
#include "headersfile.h"
extern int Search_Bin(accountList ST,int ID);
extern int tempnum;//外部导入变量tempnum
string head_1,head_2, head_3, head_4, head_5, head_6;


Status input_str(accountList &L)//读入函数,将txt文件的信息读到线性表中
{
    int a;
    int i =  1;

    if (!L.elem)
        exit(OVERFLOW);
    fstream infile;
    fstream infile_2;

    infile.open("record.txt");
    if (!infile) {
        cout <<"错误！未找到文件!"<< endl;
        exit(ERROR);
    }//打开第一个文件

    infile_2.open("record2.txt");
    if (!infile_2) {
        cout <<"错误！未找到文件!"<< endl;
        exit(ERROR);
    }//打开第二个文件

    infile >> head_1 >> head_2 >> head_3;  //先将"record.txt"文件第一行的标题字符串导入变量中暂存

    while (!infile.eof()){
        infile >> L.elem[i].ID >> L.elem[i].Name >> L.elem[i].balance;

        L.elem[i].first_node_log = NULL;
        i++;
    } //从第一个文件的第二行开始导入账号信息，创建好顺序表，并且每个账户的记录先设为空


    L.length = i-2;//线性表的长度


    infile_2>>head_1>>head_4>>head_5>>head_6;  //先将"record2.txt"文件第一行的标题字符串导入变量中暂存

    while(!infile_2.eof()){

        p_node_log p;
        p = new node_log;
        infile_2>>a>>p->DataTime>>p->W_D>>p->balance;
        int num = Search_Bin(L, a); //通过折半查找, 找到对应账户的交易记录
        p->next = L.elem[num].first_node_log;
        L.elem[num].first_node_log = p;
        a = 0;//重置a的值为0

    }//从第二个文件的第二行开始导入"交易记录"信息

    cout <<"导入信息完毕!"<<endl;

    infile.close();
    infile_2.close(); //关闭infile所关联的磁盘文件
    if(L.length != 0){
        tempnum =  L.elem[i-2].ID;
    }//如果导入的信息非空, 就继续用导入信息账号的下一个账户,即在原来的账号上加1操作,保证账号是大小递增的.
    return OK;
}


Status output_str( accountList &L)//将信息保存到txt文件中, 同时也可以更新txt文件中的信息
{



    ofstream outfile("record.txt", ios::out);//定义文件流对象，创建或者覆盖掉record.txt文件; record存放用户信息
    ofstream outfile_2("record2.txt", ios::out);//record2文件存放交易信息记录


    if(!outfile){
        cerr <<"record.txt打开出错!"<<endl;
        exit(0);
    }

    if(!outfile_2){
        cerr <<"record2.txt打开出错!"<<endl;
        exit(0);
    }


    head_1 = "账号\t";
    head_2 = "姓名\t";
    head_3 = "余额\t";
    outfile<<head_1<<head_2<<head_3<<endl; //输出txt文件的存放信息对应的标题

    head_4 = "交易时间\t";
    head_5 = "存取标志\t";
    head_6 = "交易金额\t";

    outfile_2<<head_1<<head_4<<head_5<<head_6<<endl;//输出txt文件的存放信息对应的标题

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
    cout<<"保存记录成功!"<<endl;
    return OK;

}
