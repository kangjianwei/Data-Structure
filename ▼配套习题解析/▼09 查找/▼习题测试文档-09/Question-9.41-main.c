#include <stdio.h>
#include "../../../▲课本算法实现/▲09 查找/09 B+Tree/B+Tree.c"

/* 宏定义 */
#define Max 15

/* 函数原型 */
Result Algo_9_41(B_Tree B_T, KeyType K);

int main(int argc, char *argv[])
{
	FILE *fp;
	Table T;
	B_Tree B_T;
	KeyType Key = 37;
	Result R;
	 
	printf("创建查找表...\n");
	fp = fopen("Data/Algo_9_41.txt", "r");	
	Create(fp, &T, Max);	
	Traverse(T, PrintKey);	
	printf("\n");

	printf("构造B+树...\n");
	CreateB_Tree(&B_T, T);
	PrintB_Tree(B_T);
	printf("\n");

	printf("查找关键字 %d ...\n", Key);	
	R = Algo_9_41(B_T, Key);
	if(R.tag)
		printf("已找到关键字 %d！", R.pt->key[R.i]); 
	else
		printf("未找到关键字！！");
	printf("\n\n");
		
	return 0;
}

Result Algo_9_41(B_Tree B_T, KeyType K)
{
	return SearchB_Tree(B_T, K);		//已定义 
}
