#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_29(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_29.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_29(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━┓
┃题10.29：奇偶交替排序 ┃
┗━━━━━━━━━━━*/
void Algo_10_29(SqList_sort *L)
{
	int k, start;
	RcdType tmp;
	Status preTag, curTag;
	
	start = 1;
	preTag = TRUE;				//记录上次遍历是否发生交换 
		
	while(1)
	{							
		for(k=start,curTag=FALSE; k+1<=(*L).length; k+=2)
		{
			if(LT((*L).r[k+1].key, (*L).r[k].key))
			{
				tmp = (*L).r[k+1];
				(*L).r[k+1] = (*L).r[k];
				(*L).r[k] = tmp;
				
				curTag = TRUE;	//记录本次遍历是否发生交换						 
			} 
		}
		
		if(!preTag && !curTag)	//相邻两次遍历无交换行为，说明序列已有序 
			break;
		else
		{
			preTag = curTag;
			start = start%2 + 1;//起点（奇偶）不断交替		
		}
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}
