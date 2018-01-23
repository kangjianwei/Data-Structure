#include <stdio.h>
#include <math.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 类型定义 */
typedef struct
{
	int gnum;		//>=当前关键字的其他关键字个数 
	int lnum;		//<=当前关键字的其他关键字个数 
}SNode;

/* 函数原型 */
RcdType Algo_10_42(SqList_sort L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
	RcdType R;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_42.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	R = Algo_10_42(L); 
	printf("此序列中值记录的关键字为：%d。\n", R.key);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━┓
┃题10.42：寻找中值记录 ┃
┗━━━━━━━━━━━*/
RcdType Algo_10_42(SqList_sort L)
{
	int i, j, k;
	SNode sign[L.length+1];			//存储大于和小于当前关键字的其他关键字个数 
	
	for(i=1; i<=L.length; i++)
	{
		sign[i].gnum = 0; 
		sign[i].lnum = 0;
	}
	
	for(i=1; i<=L.length-1; i++)
	{
		for(j=i+1; j<=L.length; j++)
		{
			if(L.r[i].key>L.r[j].key)
			{
				sign[i].lnum++;		//找到一个比i小的 
				sign[j].gnum++;		//找到一个比j大的 
			}
			else if(L.r[i].key<L.r[j].key)
			{
				sign[i].gnum++;
				sign[j].lnum++;				
			}
		}
	}
	
	for(i=1; i<=L.length; i++)
	{
		k = abs(sign[i].gnum-sign[i].lnum);

		if(k==0||k==1)
			return L.r[i];
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}
