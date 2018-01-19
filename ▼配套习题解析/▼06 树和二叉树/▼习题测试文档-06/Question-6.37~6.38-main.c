#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"				//**01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**06 数和二叉树**//

/* 函数原型 */
void Algo_6_37(BiTree T);
void Algo_6_38(BiTree T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("创建二叉树（先序序列）T→ ABDG^^^EH^^I^^CF^J^^^...\n");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_37-6_38.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("二叉树T为：\n");
	PrintTree(T);
	printf("\n");

	printf("███题 6.37 验证...███\n");
	{
		printf("二叉树先序遍历序列为：");  
		Algo_6_37(T);
		printf("\n\n");	
	}
	
	printf("███题 6.38 验证...███\n");
	{
		printf("二叉树后序遍历序列为：");  
		Algo_6_38(T);
		printf("\n\n");	
	}
	
	return 0;
}
/*━━━━━━━━━━━━━━┓
┃题6.37：先序遍历的非递归形式┃
┗━━━━━━━━━━━━━━*/
void Algo_6_37(BiTree T)
{
	SqStack S;
	SElemType_Sq e;
	
	if(!BiTreeEmpty(T))
	{
		InitStack_Sq(&S);
		Push_Sq(&S, T);
		
		while(!StackEmpty_Sq(S))
		{
			GetTop_Sq(S, &e);
			printf("%c ", e->data);
			
			if(e->lchild)
				Push_Sq(&S, e->lchild);
			else
			{
				while(!StackEmpty_Sq(S))
				{
					Pop_Sq(&S, &e);
					
					if(e->rchild)
					{
						Push_Sq(&S, e->rchild);
						break;					
					}
				}
			}
		}
	}
}

/*━━━━━━━━━━━━━━┓
┃题6.38：后序遍历的非递归形式┃
┗━━━━━━━━━━━━━━*/
void Algo_6_38(BiTree T)
{
	SqStack S;
	BiTree p;
	SElemType_Sq e;
	int StackMark[100] = {};							//模拟栈，设置各结点访问标记 
	int k;

	InitStack_Sq(&S);
	p = T;
	k = -1;
		
	while(1)
	{
		while(p)
		{
			Push_Sq(&S, p);
			k++;
			StackMark[k] = 1;
			p = p->lchild;
		}
			
		while(!p && !StackEmpty_Sq(S))			//p为空但栈不为空 
		{
			GetTop_Sq(S, &p);
			
			if(StackMark[k]==1)				//已访问过一次，当前是第二次访问 
			{
				StackMark[k] = 2;				
				p = p->rchild;
			}
			else							//已访问过两次，当前是第三次访问 
			{
				printf("%c ", p->data);
				Pop_Sq(&S, &e);
				StackMark[k] = 0;
				k--;
				p = NULL;
			}
		}
		
		if(StackEmpty_Sq(S))
			break;
	}		
}
