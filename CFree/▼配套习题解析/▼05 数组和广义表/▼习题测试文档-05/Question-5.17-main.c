#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��02 ���Ա�/01 SequenceList/SequenceList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
int Algo_5_17_1(SqList L, int len);
int Algo_5_17_2(SqList L, int len);
int Algo_5_17_3(SqList L, int len);
int Algo_5_17_4(SqList L, int len);
float Algo_5_17_5(SqList L, int len);

int main(int argc, char *argv[])
{
	SqList L;
	int i;
	
	InitList_Sq(&L);
	
	for(i=1; i<=5; i++)
		ListInsert_Sq(&L, i, i);
	
	printf("˳����е����ֵΪ�� %d \n", Algo_5_17_1(L, L.length));
	printf("˳����е���СֵΪ�� %d \n", Algo_5_17_2(L, L.length));
	printf("˳����еĺ�Ϊ�� %d \n", Algo_5_17_3(L, L.length));
	printf("˳����еĻ�Ϊ�� %d \n", Algo_5_17_4(L, L.length));
	printf("˳����е�ƽ��ֵΪ�� %f \n", Algo_5_17_5(L, L.length));
	printf("\n");

	return 0;
}

/*����������������������
����5.17-(1)�������ֵ��
����������������������*/
int Algo_5_17_1(SqList L, int len)
{
	int max, tmp;
	
	max = L.elem[len-1];
	
	if(len>1)
	{
		tmp = Algo_5_17_1(L, --len);
		if(tmp>max)
			max = tmp;
	}
	
	return max;
}

/*����������������������
����5.17-(2)������Сֵ��
����������������������*/
int Algo_5_17_2(SqList L, int len)
{
	int max, tmp;
	
	max = L.elem[len-1];
	
	if(len>1)
	{
		tmp = Algo_5_17_1(L, --len);
		if(tmp<max)
			max = tmp;
	}
	
	return max;
}

/*������������������
����5.17-(3)����ͩ�
������������������*/
int Algo_5_17_3(SqList L, int len)
{
	int sum;
	
	sum = L.elem[len-1];
	
	if(len>1)
		sum += L.elem[--len-1];
	
	return sum;
}

/*������������������
����5.17-(4)�������
������������������*/
int Algo_5_17_4(SqList L, int len)
{
	int pro;
	
	pro = L.elem[len-1];
	
	if(len>1)
		pro *= L.elem[--len-1];
	
	return pro;
}

/*����������������������
����5.17-(5)����ƽ��ֵ��
����������������������*/
float Algo_5_17_5(SqList L, int len)
{
	float ave;
	
	ave = L.elem[len-1];
	
	if(len>1)
		ave = (ave+(len-1)*Algo_5_17_5(L, len-1))/len;
	
	return ave;
}
