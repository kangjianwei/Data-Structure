#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
Status Algo_6_54(BiTree *T, TElemType sa[100]);

int main(int argc, char *argv[])
{
	BiTree T;
	TElemType sa[100], e;
	FILE *fp;
	int i;
	
	i = 0;
	fp = fopen("Data/Algo_6_54.txt", "r");
	Scanf(fp, "%c", &e);				//初始化数组sa存放二叉树的顺序结构
	while(!feof(fp))
	{
		sa[++i] = e;
		Scanf(fp, "%c", &e);		
	}
	fclose(fp);
	sa[0] = i;
	
	printf("创建二叉树，其顺序序列为T→ ABCDEF^G^HI^J\n");
	InitBiTree(&T); 
	Algo_6_54(&T, sa);
	printf("\n");
	
	printf("二叉树T为：\n");
	PrintTree(T);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━┓
┃题6.54：根据顺序表创建二叉树┃
┗━━━━━━━━━━━━━━*/
Status Algo_6_54(BiTree *T, TElemType sa[100])
{	
	int len = sa[0];								//0号单元存储二叉树长度（按满二叉树计算） 
	int i, k; 
	BiTree p;
	BiTree node[100];								//临时存放遍历中各结点指针的复制品 
	
	for(i=1,k=1; i<=sa[0]; i++)
	{
		if(sa[i]=='^')
			p = NULL;
		else
		{
			p = (BiTree)malloc(sizeof(BiTNode));
			if(!p)
				exit(OVERFLOW);
			p->data = sa[i];
			p->lchild = p->rchild = NULL;		
		}
		
		if(i==1)
			*T = p;
		else
		{
			while(i/2!=k)
				k++;
			
			if(i==2*k)
				node[k]->lchild = p;
			if(i==2*k+1)
				node[k]->rchild = p;    
		}
												 
		node[i] = p;								//为了与sa同步，node的0号单元弃用
	}
	
	return OK;
}
