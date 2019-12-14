#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"	//**▲01 绪论**//

/* 类型定义 */
typedef char TElemType;							//假设二叉树元素均为字符 
typedef struct BiTNode							//二叉树二叉链表存储表示
{
	TElemType data;								//结点元素 
	struct BiTNode* lchild;						//左孩子指针 
	struct BiTNode* rchild;						//右孩子指针
	struct BiTNode* parent;
	int mark;
}BiTNode;										//二叉树结点 
typedef BiTNode* BiTree;						//指向二叉树结点的指针

/* 函数原型 */
void Algo_6_39(BiTree T);
Status CreateBiTree_6_39(FILE *fp, BiTree *T, BiTree p);//构造二叉树

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("创建二叉树（先序序列）T→ ABDG^^^EH^^I^^CF^J^^^...\n");
	fp = fopen("Data/Algo_6_39.txt", "r");
	CreateBiTree_6_39(fp, &T, NULL);
	fclose(fp);
	printf("\n");

	printf("二叉树后序遍历序列为：");  
	Algo_6_39(T);		
	printf("\n\n");	

	return 0;
}

/*━━━━━━━━━━━━━┓
┃题6.39：后序遍历的递推形式┃
┗━━━━━━━━━━━━━*/
void Algo_6_39(BiTree T)
{
	BiTree p = T;
	
	while(p)
	{
		if(p->mark==0)
		{
			p->mark = 1;		
			if(p->lchild)
				p = p->lchild;
		}
		else if(p->mark==1)
		{
			p->mark = 2;
			if(p->rchild)	
				p = p->rchild;			
		}
		else					//T->mark==2
		{
			printf("%c ", p->data);
			p = p->parent;
		}
	}
}

Status CreateBiTree_6_39(FILE *fp, BiTree *T, BiTree p)		//构造二叉树
{
	char ch;

	Scanf(fp, "%c", &ch);
	
	if(ch == '^')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		(*T)->parent = p;
		(*T)->mark = 0;
		CreateBiTree_6_39(fp, &(*T)->lchild, *T);
		CreateBiTree_6_39(fp, &(*T)->rchild, *T);
	}
	
	return OK;
}
