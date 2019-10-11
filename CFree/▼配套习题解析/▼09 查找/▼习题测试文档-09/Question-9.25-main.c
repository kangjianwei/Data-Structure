#include <stdio.h>
#include "../../../▲课本算法实现/▲09 查找/00 Base/Base.c" //**▲09 查找**//

/* 宏定义 */
#define MAX 20						//关键字个数 

/* 函数原型 */
int Algo_9_25(Table T, KeyType key);

int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T;
	KeyType key = 15;
	int i;
		
	printf("创建并输出一个查找表（自大至小）...\n");
	fp = fopen("Data/Algo_9_25.txt", "r");	
	Create(fp, &T, MAX+1);			//多开辟一个单位 
	Traverse(T, PrintKey);	
	printf("\n");
	
	i = Algo_9_25(T, key);
	if(i==MAX+1)
		printf("关键字 %d 未找到！！\n", key);
	else
		printf("关键字 %d 在第 %d 个位置。\n", key, i);
	printf("\n");
		
	return 0;
}

int Algo_9_25(Table T, KeyType key)
{
	int i;
	
	T.elem[MAX+1].key = key;
	
	for(i=1; T.elem[i].key!=key; ++i)
		;
	
	return i;
}
