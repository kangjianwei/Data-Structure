#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/04 ThreadBinaryTree/ThreadBinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
ThrBiTree Algo_6_56(ThrBiTree p);
ThrBiTree Algo_6_57(ThrBiTree p);

int main(int argc, char *argv[])
{	
	int mark;
	ThrBiTree Thrt, T;
	ThrBiTree p;
	FILE *fp;
	
	printf("验证题 6.56 输入 1 ，验证题 6.57 输入 2 ：");
	fflush(stdin);
	scanf("%d", &mark);
	printf("\n");
	
	printf("作为示例录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n\n");
	fp = fopen("Data/Algo_6_56-6.57.txt", "r");
	CreateBiTree_Thr(fp, &T);
	fclose(fp);
	
	p = T->lchild;									//用于测试的p 
		
	if(mark==1)
	{
		printf("███ 题 6.56 验证... ███\n");
		PreOrderThreading_Thr(&Thrt, T);
		printf("在先序线索二叉树中，%c 的后继为：", p->data);
		p = Algo_6_56(p);
		printf("%c 。\n\n", p->data);
	}
	
	if(mark==2)
	{
		printf("███ 题 6.57 验证... ███\n");
		ParentPtr_Thr(T);
		PosOrderThreading_Thr(&Thrt, T);
		printf("在后序线索二叉树中， %c 的后继为：", p->data);
		p = Algo_6_57(p);
		printf(" %c 。\n\n", p->data);
	}

	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━┓
┃题6.56：在先序后继线索二叉树中寻找p的后继 ┃
┗━━━━━━━━━━━━━━━━━━━━━*/
ThrBiTree Algo_6_56(ThrBiTree p)
{
	if(p->RTag==Thread)
		p = p->rchild;
	else
	{
		if(p->lchild)
			p = p->lchild;
		else
			p = p->rchild;
	}
	
	if(p->data)					//判断p是否指向头结点 
		return p;
	else
		return NULL;			//最后一个结点无后继 
}

/*━━━━━━━━━━━━━━━━━━━━━┓
┃题6.57：在后序后继线索二叉树中寻找p的后继 ┃
┗━━━━━━━━━━━━━━━━━━━━━*/
ThrBiTree Algo_6_57(ThrBiTree p)
{
	if(p->parent==NULL)									//根结点是最后一个结点，无后继 
		return NULL;
	else
	{
		if(p->RTag==Thread)								//右孩子为线索 
			return p->rchild;
		else
		{												
			if(p==p->parent->rchild)					//当前结点是左孩子 
				return p->parent;
			else
			{		
				if(p->parent->RTag!=Link)				//双亲没有右孩子 
					p = p->parent;
				else
				{
					p = p->parent->rchild;
					while(1)							//寻找右兄弟遍历起点 
					{
						while(p->lchild)					 
							p = p->lchild;		
			
						if(p->rchild && p->RTag!=Thread)
							p = p->rchild;
						else
							break;
					}
				}
				
				return p;				
			}
		}
	}
}
