//�۰���Һ�ɾ��˳����е�ĳ��Ԫ��
#include "headersfile.h"
extern string getTime();

int Search_Bin(accountList ST,int ID)
{  //ͨ���˺��ҵ����˻�,�������ST���۰������ؼ��ֵ���ID������Ԫ�ء���Ԫ���ڱ��е�λ�ã�����Ϊ0
   int low=1,high=ST.length;							//�ò��������ֵ
   int  mid;
   while(low<=high) {
	   mid=(low+high) / 2;
      if (ID==ST.elem[mid].ID)  return mid;      		//�ҵ�����Ԫ��
      else if (ID<ST.elem[mid].ID)  high = mid -1;		//������ǰһ�ӱ���в���
      else  low =mid +1;                       			//�����ں�һ�ӱ���в���
   }//while
   return -1;										//���в����ڴ���Ԫ��
}//�۰��������˻�

Status ListDelete(accountList &L, int i)
{ //��˳���L��ɾ����i��Ԫ��
    if ((i < 1) || (i > L.length))
		return ERROR; //iֵ���Ϸ�

	for (int j = i; j <= L.length; j++)
		L.elem[j ] = L.elem[j + 1]; //��ɾ��Ԫ��֮���Ԫ��ǰ��

	--L.length; //����1
	return OK;
}//ɾ���˻�


