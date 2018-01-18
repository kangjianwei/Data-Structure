#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲05 数组和广义表/04 CrossList/CrossList.c"   //**▲05 数组和广义表**//

/* 函数原型 */
Status Algo_5_26(CrossList M);

int main(int argc, char *argv[])
{
	CrossList M;
	FILE *fp;
	
	printf("创建十字链表 M...\n");
	fp = fopen("Data/Algo_5_26.txt", "r");	
	CreateSMatrix_OL(fp, 1, &M);
	fclose(fp);	
	printf("M = \n");
	PrintSMatrix_OL(M);
	printf("\n");

	printf("按三元组形式输出 M...\n");
	printf(" 行 列  值\n");	
	Algo_5_26(M);
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━┓
┃题5.26：以三元组形式输出十字链表┃
┗━━━━━━━━━━━━━━━━*/ 
Status Algo_5_26(CrossList M)
{
	int i, j;
	OLNode *p;
	
	if(!M.tu)
		return ERROR;
	
	for(i=1; i<=M.mu; ++i)
	{
		p = M.rhead[i];
		for(j=1; j<=M.nu; ++j)
		{
			if(p && p->j==j)
			{
				printf("(%2d %2d %3d)\n", i, j, p->e);
				p = p->right;
			}
		}
	}
	
	return OK;
}
