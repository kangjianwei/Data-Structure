#include <stdio.h>
#include "../../../▲课本算法实现/▲09 查找/00 Base/Base.c" //**▲09 查找**//

/* 宏定义 */
#define MAX 30			//关键字个数 

/* 类型定义 */
typedef struct
{
	int start;			//当前块起点 
	int min;			//当前块中元素最小值 
}Index; 
typedef struct
{
	Table T;			//所有块中元素 
	Index Block[MAX]; 
	int bnum;			//块的个数 
}Lookup;				//关键字递增的查找表 

/* 函数原型 */
int Algo_9_28(Lookup ST, KeyType key);
void CreateBlock_9_28(FILE* fp, Lookup *ST);

int main(int argc, char *argv[])
{	
	FILE *fp;
	Lookup ST;
	KeyType key = 89;
	int i;
		
	printf("创建并输出一个查找表...\n");
	fp = fopen("Data/Algo_9_28.txt", "r");	
	CreateBlock_9_28(fp, &ST); 
	Traverse(ST.T, PrintKey);	
	printf("\n");
	
	i = Algo_9_28(ST, key);
	if(!i)
		printf("关键字 %d 未找到！！\n", key);
	else
		printf("关键字 %d 在顺序表第 %d 个位置。\n", key, i);
	printf("\n");
		
	return 0;
}

int Algo_9_28(Lookup ST, KeyType key)
{
	int low, high, mid;
	
	if(key<ST.Block[1].min)						//先确定关键字在块中的位置 
		low = 0;
	else if (key>=ST.Block[ST.bnum].min)
		low = ST.bnum;
	else
	{
		low=1, high=ST.bnum;
		
		while(high-low>1)
		{
			mid = (low + high) / 2;
			
			if(ST.Block[mid].min<=key)
				low = mid;
			else
				high = mid; 
		}	
	}

	if(low) 								//找到其所属的块后，继续在顺序表T中查找
	{
		if(low==ST.bnum)
			high = ST.T.length;
		else
			high = ST.Block[high].start-1;
		
		while(low<=high)
		{
			mid = (low+high)/2;
			
			if(key<ST.T.elem[mid].key)
				high = mid - 1;
			else if(key>ST.T.elem[mid].key)
				low = mid + 1;
			else
				return mid;
		}
	}
	
	return 0;		//未找到 
}

void CreateBlock_9_28(FILE* fp, Lookup *ST)		//创建块查找表 
{
	int i;
	
	Create(fp, &ST->T, MAX);					//录入所有关键字创建顺序表
	
	for(i=1,ST->bnum=0; i<=ST->T.length; i+=5)				//设定最多5个元素构成一个块 
	{
		ST->bnum++;
		ST->Block[ST->bnum].start = i;
		ST->Block[ST->bnum].min = ST->T.elem[i].key;
	}
}
