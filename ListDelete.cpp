//折半查找和删除顺序表中的某个元素
#include "headersfile.h"
extern string getTime();

int Search_Bin(accountList ST,int ID)
{  //通过账号找到该账户,在有序表ST中折半查找其关键字等于ID的数据元素。该元素在表中的位置，否则为0
   int low=1,high=ST.length;							//置查找区间初值
   int  mid;
   while(low<=high) {
	   mid=(low+high) / 2;
      if (ID==ST.elem[mid].ID)  return mid;      		//找到待查元素
      else if (ID<ST.elem[mid].ID)  high = mid -1;		//继续在前一子表进行查找
      else  low =mid +1;                       			//继续在后一子表进行查找
   }//while
   return -1;										//表中不存在待查元素
}//折半查找相关账户

Status ListDelete(accountList &L, int i)
{ //在顺序表L中删除第i个元素
    if ((i < 1) || (i > L.length))
		return ERROR; //i值不合法

	for (int j = i; j <= L.length; j++)
		L.elem[j ] = L.elem[j + 1]; //被删除元素之后的元素前移

	--L.length; //表长减1
	return OK;
}//删除账户


