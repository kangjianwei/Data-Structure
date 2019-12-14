#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_26(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_26.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_26(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━━┓
┃题10.26：起泡排序(改动) ┃
┗━━━━━━━━━━━━*/
void Algo_10_26(SqList_sort *L)
{
	int i, j;
	RcdType tmp;
	int change;							//change指示每一趟排序中进行交换的最后一个记录的位置
	
	for(i=(*L).length; i>=1; i=change-1)
	{		
		for(j=1; j<=i-1; j++)
		{
			if(LT((*L).r[j+1].key, (*L).r[j].key))
			{
				tmp = (*L).r[j+1];
				(*L).r[j+1] = (*L).r[j];
				(*L).r[j] = tmp;
				
				change = j+1;			//从change起往后的元素均有序			 
			} 
		}
		
		if(change==j+1)					//若遍历不发生交换，说明序列已经有序
			break;
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}
