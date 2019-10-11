#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_27(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_27.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_27(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━┓
┃题10.27：双向起泡排序 ┃
┗━━━━━━━━━━━*/
void Algo_10_27(SqList_sort *L)
{
	int i, j, k;
	RcdType tmp;
	Status tag;
	
	k = 1;											//每个交替周期的起点 
	
	do
	{					
		for(i=k,tag=FALSE; i<=(*L).length-k; i++)	//从前向后遍历 
		{
			if(LT((*L).r[i+1].key, (*L).r[i].key))
			{
				tmp = (*L).r[i+1];
				(*L).r[i+1] = (*L).r[i];
				(*L).r[i] = tmp;
				
				tag = TRUE;							 
			} 
		}
		
		if(!tag)									//若遍历不发生交换，说明序列已经有序
			break;
			
		for(j=i-1,tag=FALSE; j>=k+1; j--)			//从后向前排遍历					
		{
			if(LT((*L).r[j].key, (*L).r[j-1].key))
			{
				tmp = (*L).r[j];
				(*L).r[j] = (*L).r[j-1];
				(*L).r[j-1] = tmp;
				
				tag = TRUE; 
			}		
		}
		
		k++;
		
	}while(tag);
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}
