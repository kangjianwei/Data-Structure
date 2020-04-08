#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
void Algo_6_51(BiTree T);
Status IsOperator_6_51(char c);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("创建二叉树（先序序列）T→ */*+a^^b^^-c^^d^^e^^-g^^h^^...\n");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_51.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("二叉树T为：\n");
	PrintTree(T);
	printf("\n");
	
	printf("输出算术表达式：");
	Algo_6_51(T);	
	printf("\n\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━┓
┃题6.51：输出算术表达式构成的二叉树┃
┗━━━━━━━━━━━━━━━━━*/
void Algo_6_51(BiTree T)
{
	if(T)
	{
		if(T->lchild)
		{	
			// 左子树是表达式，则添加括号			
			if(IsOperator_6_51(T->lchild->data))
			{
				printf("(");
				Algo_6_51(T->lchild);
				printf(")");
			}			
			else
				Algo_6_51(T->lchild);
		}
		
		printf("%c", T->data);
		
		if(T->rchild)
		{
			// 右子树是表达式，则添加括号
			if(IsOperator_6_51(T->rchild->data))
			{
				printf("(");
				Algo_6_51(T->rchild);
				printf(")");
			}			
			else
				Algo_6_51(T->rchild);		
		}
	} 
}

Status IsOperator_6_51(char c)				//判断字符c是否为操作符
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return TRUE;
	else
		return ERROR;
} 
