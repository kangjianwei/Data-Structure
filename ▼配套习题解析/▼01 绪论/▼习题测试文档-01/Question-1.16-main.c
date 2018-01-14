#include <stdio.h>

/* 函数原型 */
void Algo_1_16(int i, int j, int k);

int main(int argc, char *argv[])
{
	int i, j, k;
	
	i = 3;
	j = 7;
	k = 1;
	
	printf("作为示范，设定依次读入的三个整数为：%d %d %d...\n", i, j, k);
	printf("这三个数从大到小的顺序为：");
	
	Algo_1_16(i, j, k);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━┓
┃题1.16：将3个整数按从大到小顺序输出 ┃
┗━━━━━━━━━━━━━━━━━━*/
void Algo_1_16(int i, int j, int k)
{
	int tmp;
	
	if(i<j)
	{
		tmp = i;
		i = j;
		j = tmp;
	}
	
	if(j<k)
	{
		tmp = j;
		j = k;
		k = tmp;	
	}
	
	if(i<j)
	{
		tmp = i;
		i = j;
		j = tmp;
	}	
	
	printf("%d %d %d\n", i, j, k);
}
