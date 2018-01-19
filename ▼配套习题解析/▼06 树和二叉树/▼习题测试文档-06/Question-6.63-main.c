#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/06 ChildTree/ChildTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
int Algo_6_63_1(CTree T);
int Algo_6_63_2(CTree T);

int main(int argc, char *argv[])
{
	CTree T;
	int depth_1, depth_2;
	FILE *fp;
	
	fp = fopen("Data/Algo_6_63.txt", "r");	
	InitTree_C(fp, &T);	
	CreateTree_C(fp, &T);
	fclose(fp);
	printf("\n");

	printf("构建的树为：\n");	
	Print_C_1(T);
	printf("\n");
	
	depth_1 = Algo_6_63_1(T);

	depth_2 = Algo_6_63_2(T);
	
	printf("方法 1：此树的深度为： %d\n", depth_1);
	printf("方法 2：此树的深度为： %d\n", depth_2);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━┓
┃题6.63：计算孩子链表表示的树的深度┃
┗━━━━━━━━━━━━━━━━━*/
/* 方法1: 适用于带双亲的孩子链表 */
int Algo_6_63_1(CTree T)						 
{
	return TreeDepth_C_1(T);				//已定义 
}

/* 方法2: 通用于孩子链表，不带双亲也可以 */
int Algo_6_63_2(CTree T)
{
	return TreeDepth_C_2(T); 				//已定义 
}
