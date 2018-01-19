#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/05 ParentTree/ParentTree.c" 	//**▲06 数和二叉树**//

/* 函数原型 */
int Algo_6_64(PTree T);

int main(int argc, char *argv[])
{
	PTree T;
	int depth;
	FILE *fp;
	
	InitTree_P(&T);
	fp = fopen("Data/Algo_6_64.txt", "r");
	CreateTree_P(fp, &T);
	fclose(fp);
	printf("\n");

	printf("构建的树为：\n");
	Print_P(T);
	printf("\n");

	depth = Algo_6_64(T);
	
	printf("此树的深度为： %d\n", depth);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━┓
┃题6.63：计算孩子链表表示的树的深度┃
┗━━━━━━━━━━━━━━━━━*/
int Algo_6_64(PTree T)
{
	return TreeDepth_P(T); 				//已定义 
}
