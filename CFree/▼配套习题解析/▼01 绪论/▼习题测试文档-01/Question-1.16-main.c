#include <stdio.h>

/* 函数原型 */
void Algo_1_16(int i, int j, int k);

int main(int argc, char *argv[])
{
	int i, j, k;
	
	i = 1;
	j = 2;
	k = 3;
	
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
	
	// 1.确保i>=j
	if(i<j)
	{
		tmp = i;
		i = j;
		j = tmp;
	}
	
	// 2.确保j>=k，这里如果j是小于k的，那么会对j和k的值进行交换
	if(j<k)
	{
		tmp = j;
		j = k;
		k = tmp;	
	}
	
	// 3.如果第2步中发现j<k，则会对j和k的值进行交换，这会导致j的值被更新。
	//   如果j的值发生了更新，这可能会破坏第1步中i>=j的保证，所以此处需要再次验证i与j的关系。
	if(i<j)
	{
		tmp = i;
		i = j;
		j = tmp;
	}	
	
	printf("%d %d %d\n", i, j, k);
}
