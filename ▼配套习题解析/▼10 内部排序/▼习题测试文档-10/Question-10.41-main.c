#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"//**▲01 绪论**//


/* 宏定义 */
#define MAXNUM 10000					//整数上限(关键字均小于此数) 

/* 函数原型 */
void Algo_10_41(int keys[], int maxnum);

int main(int argc, char *argv[])
{
	FILE *fp;
	int keys[1001];
	int tmp, i, j;
	
	fp = fopen("Data/Algo_10_41.txt", "r");
	keys[0] = 0;	
	while(Scanf(fp, "%d", &tmp)==1)
		keys[++keys[0]] = tmp;
	fclose(fp);
	
	Algo_10_41(keys, MAXNUM);
	
	for(i=1; i<=1000; i++)
	{
		printf("%4d ", keys[i]);
		
		if(i%10==0)
			printf("\n");
	}

	return 0;
}

void Algo_10_41(int keys[], int maxnum)
{
	int hash[maxnum];
	int i, j, k;
	
	for(i=0; i<maxnum; i++)			//初始化计数数组 
		hash[i] = 0;
	
	for(i=1; i<=keys[0]; i++)		//统计各整数出现次数 
		hash[keys[i]]++;
	
	for(i=0,k=0; i<maxnum; i++)		//按增序将排序后的内容导入keys 
	{
		for(j=1; j<=hash[i]; j++)
			keys[++k] = i;
	}
}
