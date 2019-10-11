#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"							//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
Status Algo_6_65_1(BiTree *T, char pre[], char in[]);
int RelativePosition_6_65(char *s, char A, char B);		//返回序列中A相对B的位置信息

int main(int argc, char *argv[])
{
	BiTree T;
	char pre[] = "ABDGEHICFJ";
	char in[] =  "GDBHEIAFJC";
	
	printf("二叉树先序序列为：%s\n", pre);
	printf("二叉树中序序列为：%s\n", in);
	printf("\n");
		
	Algo_6_65_1(&T, pre, in);	
	printf("由此构造的二叉树为：\n");
	PrintTree(T);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━┓
┃题6.65：根据前序序列和中序序列创建二叉树┃
┗━━━━━━━━━━━━━━━━━━━━*/
/* 方法1：采用非递归形式遍历前序序列创建二叉树 */
Status Algo_6_65_1(BiTree *T, char pre[], char in[])
{
	SqStack S;
	SElemType_Sq e;
	int k;
	BiTree p, q;
	 
	*T = NULL;	
	k = -1;
	
	InitStack_Sq(&S);
	
	while(pre[k+1]!='\0')							//访问先序序列 
	{
		k++;
		
		p = (BiTree)malloc(sizeof(BiTNode));
		if(!p)
			exit(OVERFLOW);
		p->data = pre[k];
		p->lchild = p->rchild = NULL;
		
		if(!(*T))
			*T = p;
		else
		{
			GetTop_Sq(S, &e);
			
			if(RelativePosition_6_65(in, pre[k], e->data)<0)//由中序序列判断当前结点相对位置 
				e->lchild = p;								//pre[k]在 e->data的左边 
			else											//pre[k]在 e->data的右边时一直出栈找到最后一个在右边的 
			{
				do
				{
					Pop_Sq(&S, &e);
					if(!StackEmpty_Sq(S))
						GetTop_Sq(S, &q);
					else
						break;
				}
				while(RelativePosition_6_65(in, pre[k], q->data)>0);
				
				e->rchild = p;	
			}
		}
		
		Push_Sq(&S, p);
	}
	
	return OK;
}

int RelativePosition_6_65(char *s, char A, char B)		//返回序列中A相对B的位置信息 
{														//假设字符串s中A、B若存在则唯一 
	int k, a, b;
	
	k = a = b = -1;
	
	while(s[k+1]!='\0')
	{
		k++;
		
		if(s[k]==A)
			a = k;
		if(s[k]==B)
			b = k;
	}
	
	if(a>=0 && b>=0)
	{
		if(a<b)
			return -1;								//A在B的左边
		if(a>b)
			return 1;								//A在B的右边		
	}
	else
		return 0;									//表示非正常退出 
}
