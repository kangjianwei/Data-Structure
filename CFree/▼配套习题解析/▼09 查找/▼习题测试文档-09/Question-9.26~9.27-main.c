#include <stdio.h>
#include "../../../▲课本算法实现/▲09 查找/00 Base/Base.c" //**▲09 查找**//

/* 宏定义 */
#define MAX 20						//关键字个数 

/* 函数原型 */
int Algo_9_26(Table T, KeyType key, int low, int high);
int Algo_9_27(Table T, KeyType key);

int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T;
	KeyType key = 18;
	int i;
		
	printf("创建并输出一个查找表（自小至大）...\n");
	fp = fopen("Data/Algo_9_26-9_27.txt", "r");	
	Create(fp, &T, MAX);
	Traverse(T, PrintKey);	
	printf("\n");

	printf("███ 题 9.26 验证... ███\n");	
	i = Algo_9_26(T, key, 1, T.length);
	if(!i)
		printf("关键字 %d 未找到！！\n", key);
	else
		printf("关键字 %d 在第 %d 个位置。\n", key, i);
	printf("\n");

	printf("███ 题 9.27 验证... ███\n");	
	i = Algo_9_27(T, key);
	printf("关键字 %d 在第 %d 个区间。\n", key, i);
	printf("\n");
	
	return 0;
}

int Algo_9_26(Table T, KeyType key, int low, int high)
{
	int mid;
	
	if(low>high)				//未找到时返回0 
		return 0;

	mid = (low+high)/2;
	
	if(T.elem[mid].key==key)
		return mid;
	else if(T.elem[mid].key>key)
		return Algo_9_26(T, key, low, mid-1);
	else
		return Algo_9_26(T, key, mid+1, high);
}

int Algo_9_27(Table T, KeyType key)		//实际上是查询其所在的区间 
{
	int low, high, mid;
	
	if(key<T.elem[1].key)
		return 0;

	if(key>=T.elem[T.length].key)
		return T.length;

	low = 1;
	high = T.length;
	
	while(high-low>1)					//查找表元素大于1 
	{
		mid = (low + high) / 2;
		
		if(T.elem[mid].key<=key)
			low = mid;
		else
			high = mid; 
	}
	
	return low;
}
