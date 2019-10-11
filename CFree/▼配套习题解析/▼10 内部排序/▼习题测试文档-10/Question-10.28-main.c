#include <stdio.h>
#include "../../../▲课本算法实现/▲10 内部排序/00 SequenceListType/SequenceListType.c"//**▲10 内部排序**//

/* 函数原型 */
void Algo_10_28(SqList_sort *L);
void PrintKey(KeyType e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	SqList_sort L;
			
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_28.txt", "r");
	CreateSortList(fp, &L);
	Traverse(L, PrintKey);
	printf("\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_28(&L); 
	Traverse(L, PrintKey);
	printf("\n");	
		
	return 0;
}

/*━━━━━━━━━━━┓
┃题10.28：双向起泡排序 ┃
┗━━━━━━━━━━━*/
void Algo_10_28(SqList_sort *L)
{
	int k, start, end, cache, dir;
	RcdType tmp;
	Status tag;
	
	dir = 1; 
	
	start = 1;
	end = (*L).length;
	
	while(1)
	{
		tag = FALSE;
							
		for(k=start; k!=end; k=k+dir)
		{
			if(LT((*L).r[k+1].key, (*L).r[k].key))
			{
				tmp = (*L).r[k+1];
				(*L).r[k+1] = (*L).r[k];
				(*L).r[k] = tmp;
				
				tag = TRUE;							 
			} 
		}
		
		if(!tag)								//若遍历不发生交换，说明序列已经有序
			break;		
		
		dir = -dir;								//改变方向
		
		cache = start;
		start = end + 2*dir;					//当前遍历起点与上次遍历终点的关系 
		end = cache + dir; 						//当前遍历终点与上次遍历起点的关系
	}
}

void PrintKey(KeyType e)
{
	printf("%d ", e);
}
