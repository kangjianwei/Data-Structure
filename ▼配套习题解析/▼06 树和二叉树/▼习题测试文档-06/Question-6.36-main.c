#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
Status Algo_6_36(BiTree B1, BiTree B2);

int main(int argc, char *argv[])
{
	BiTree B1, B2, B3;
	FILE *fp;												//输入源 
	char tmp;
		
	InitBiTree(&B1); 
	InitBiTree(&B2);
	InitBiTree(&B3);
	
	printf("创建二叉树（先序序列）B1→ ABD^^E^^C^^...\n");
	printf("                      B2→ FGH^^I^^J^^...\n");
	printf("                      B3→ KLM^^N^^OP^^^...\n");
	fp = fopen("Data/Algo_6_36.txt", "r");
	CreateBiTree(fp, &B1);
	Scanf(fp, "%c", &tmp);			//跳过换行符 
	CreateBiTree(fp, &B2);
	Scanf(fp, "%c", &tmp);			//跳过换行符 
	CreateBiTree(fp, &B3);
	fclose(fp);
	printf("\n");
	
	printf("二叉树B1为：\n");
	PrintTree(B1);
	printf("\n");
	printf("二叉树B2为：\n");
	PrintTree(B2);
	printf("\n");
	printf("二叉树B3为：\n");
	PrintTree(B3);
	printf("\n");

	if(Algo_6_36(B1, B2))
		printf("B1与B2相似！\n");
	else
		printf("B1与B2不相似！！\n"); 

	if(Algo_6_36(B2, B3))
		printf("B2与B3相似！\n");
	else
		printf("B1与B3不相似！！\n");  
	
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题6.36：判断B1与B2是否相似┃
┗━━━━━━━━━━━━━*/
Status Algo_6_36(BiTree B1, BiTree B2)
{
	if(BiTreeEmpty(B1) && BiTreeEmpty(B2))			//都为空树 
		return TRUE;
	else
	{
		if(!BiTreeEmpty(B1) && !BiTreeEmpty(B2))	//都不为空树 
		{
			if(Algo_6_36(B1->lchild, B2->lchild) && Algo_6_36(B1->rchild, B2->rchild))	//判断左右子树 
				return TRUE;	
		}
	}
	
	return FALSE;
}
