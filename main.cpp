#include "headersfile.h"
#include "extern.h"

int main()
{
    int s, i, id, num;
    float d, money;
    accountList L;
    L.elem = new node_account[MAXSIZE]; //创建一个空的账户表
    L.length = 0;
    node_account e;
    string DataTime;

    input_str(L);//导入信息

    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|            活期储蓄账目管理系统                |"<<endl;
    cout<<"|  1.开户                                        |"<<endl;
    cout<<"|  2.销户                                        |"<<endl;
    cout<<"|  3.向某账户存款                                |"<<endl;
    cout<<"|  4.从某账户取款                                |"<<endl;
    cout<<"|  5.显示所有账号信息                            |"<<endl;
    cout<<"|  6.查询某账户余额                              |"<<endl;
    cout<<"|  7.查询某账户交易记录                          |"<<endl;
    cout<<"|  0.退出程序(更新保存记录)                      |"<<endl;
    cout<<"|================================================|"<<endl;
    cout<<"输入选择项：";
    cin>>s;
    while(s!=0){
         switch(s){
            case 1:
                i = L.length + 1;
                cout<<"您选择的项目为:开户"<<endl;
                cout<<"请输入姓名: ";
                cin>>e.Name;
                ListInsert(L, i, e);
                cout<<"账户创建成功!您已完成开户操作,请记住您的账号"<<endl;
                DataTime = getTime();
                cout<<"当前时间为:"<<DataTime<<endl;
                cout<<endl;
                break;
            case 2:
                cout<<"您选择的项目为:销户"<<endl;
                cout<<"请输入要查找的账号:";
                cin>>id;
                i = Search_Bin(L, id);//用折半查找定位在数组中位置
                if(i == -1){
                    cout<<"您输入的账号不存在,请查正后再输"<<endl;
                }else if(L.elem[i].balance != 0){
                    cout<<"该账户余额不为0,不能销户!"<<endl;
                }else{
                    ListDelete(L, i);
                    cout<<"销户成功!"<<endl;
                }
                cout<<endl;
                break;

            case 3:
                cout<<"您选择的项目为:向某账户存款"<<endl;
                cout<<"请输入要存款的账号:";
                cin>>id;
                i = Search_Bin(L, id);//用折半查找定位在数组中位置
                if(i== -1){
                    cout<<"您输入的账号不存在,请查正后再输"<<endl;
                }else{
                    cout<<"请输入要存款的金额:";
                    cin>>money;
                    while(money<=0){
                        cout<<"输入金额错误, 存款金额必须大于0"<<endl;
                        cout<<"请重新输入:";
                        cin>>money;
                    }
                    d = putinmoney(L, money, i );
                    cout<<"存款成功! 存入金额为: "<<money<<"  您的余额为:"<<d<<endl;
                }
                DataTime = getTime();
                cout<<"当前时间为:"<<DataTime<<endl;
                cout<<endl;
                break;
            case 4:
                cout<<"您选择的项目为:从某账户取款"<<endl;
                cout<<"请输入要存款的账号:";
                cin>>id;
                i = Search_Bin(L, id);//用折半查找定位数组的下标
                if(i== -1){
                    cout<<"您输入的账号不存在,请查正后再输"<<endl;
                }else{
                    cout<<"请输入要取款的金额:";
                    cin>>money;
                    while(money<=0){
                        cout<<"输入金额错误, 取款金额必须大于0"<<endl;
                        cout<<"请重新输入:";
                        cin>>money;
                    }
                    d = putoutmoney(L, money, i );
                    cout<<"  您的余额为:"<<d<<endl;
                }
                DataTime = getTime();
                cout<<"当前时间为:"<<DataTime<<endl;
                break;

            case 5:
                cout<<"您选择的项目为:显示所有账号信息"<<endl;
                information(L);
                break;
            case 6:
                cout<<"您选择的项目为:查询某账户余额"<<endl;
                cout<<"请输入要查询的账号:";
                cin>>id;
                i = Search_Bin(L, id);//用折半查找定位数组的下标
                if(i== -1){
                    cout<<"您输入的账号不存在,请查正后再输"<<endl;
                }else{
                    balance_inquiry(L, i);
                    cout<<"账户余额查询成功!"<<endl;
                }
                break;
            case 7:
                cout<<"您选择的项目为:查询某账户交易记录  "<<endl;
                cout<<"请输入要查询的账号:";
                cin>>id;
                i = Search_Bin(L, id);//用折半查找定位数组的下标
                if(i== -1){
                    cout<<"您输入的账号不存在,请查正后再输"<<endl;
                }else{
                    record(L, i);
                    cout<<"账户交易记录查询成功!"<<endl;
                }
                break;
            default:
                output_str(L);//将信息写入文件中;更新保存信息
                break;
        }
        cout<<endl;
        cout<<"输入选择项：";
        cin>>s;
    }

    output_str(L);//将信息写入文件中;更新保存信息
    cout<<"已经退出程序!"<<endl;

    return 0;
}
