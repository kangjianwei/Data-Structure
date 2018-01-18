#include <stdio.h>	
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲02 线性表/01 SequenceList/SequenceList.c"	//**▲02 线性表**//

/* 函数原型 */
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
	
	printf("顺序表中的最大值为： %d \n", Algo_5_17_1(L, L.length));
	printf("顺序表中的最小值为： %d \n", Algo_5_17_2(L, L.length));
	printf("顺序表中的和为： %d \n", Algo_5_17_3(L, L.length));
	printf("顺序表中的积为： %d \n", Algo_5_17_4(L, L.length));
	printf("顺序表中的平均值为： %f \n", Algo_5_17_5(L, L.length));
	printf("\n");

	return 0;
}

/*━━━━━━━━━━┓
┃题5.17-(1)：求最大值┃
┗━━━━━━━━━━*/
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

/*━━━━━━━━━━┓
┃题5.17-(2)：求最小值┃
┗━━━━━━━━━━*/
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

/*━━━━━━━━┓
┃题5.17-(3)：求和┃
┗━━━━━━━━*/
int Algo_5_17_3(SqList L, int len)
{
	int sum;
	
	sum = L.elem[len-1];
	
	if(len>1)
		sum += L.elem[--len-1];
	
	return sum;
}

/*━━━━━━━━┓
┃题5.17-(4)：求积┃
┗━━━━━━━━*/
int Algo_5_17_4(SqList L, int len)
{
	int pro;
	
	pro = L.elem[len-1];
	
	if(len>1)
		pro *= L.elem[--len-1];
	
	return pro;
}

/*━━━━━━━━━━┓
┃题5.17-(5)：求平均值┃
┗━━━━━━━━━━*/
float Algo_5_17_5(SqList L, int len)
{
	float ave;
	
	ave = L.elem[len-1];
	
	if(len>1)
		ave = (ave+(len-1)*Algo_5_17_5(L, len-1))/len;
	
	return ave;
}
