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
}BiTNode;										//二叉树结点 
typedef BiTNode* BiTree;						//指向二叉树结点的指针

/* 函数原型 */
void Algo_6_40(BiTree T);
Status CreateBiTree_6_40(FILE *fp, BiTree *T, BiTree p);	//构造二叉树

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("创建二叉树（先序序列）T→ ABDG^^^EH^^I^^CF^J^^^...\n");
	fp = fopen("Data/Algo_6_40.txt", "r");
	CreateBiTree_6_40(fp, &T, NULL);
	fclose(fp);
	printf("\n");

	printf("二叉树中序遍历序列为：");  
	Algo_6_40(T);		
	printf("\n\n");	

	return 0;
}

/*━━━━━━━━━━━━━┓
┃题6.40：中序遍历的递推形式┃
┗━━━━━━━━━━━━━*/
void Algo_6_40(BiTree T)						//关键是分辨当前结点第几次被访问 
{
	BiTree p = T;
	
	while(p)
	{	
 		if(p->lchild)							//第一次访问结点，向左访问 
 			p = p->lchild;
		else
		{
			printf("%c ", p->data);				//从左子树返回的结点第二次被访问,要输出 
			
			while(!(p->rchild))					
			{									//若当前结点属于右分支，返回到父结点后要跳过父结点
				while(p->parent && p->parent->rchild==p)
					p = p->parent;				//从右子树返回的结点第三次被访问，不输出 
					
				if(p->parent)
				{
					if(p->parent->lchild==p)	//若当前结点属于左分支，返回到父结点后要访问父结点	 
					{
						p = p->parent;
						printf("%c ", p->data);//同样返回自左子树
					}
				}
				else
					return;						//从右子树返回到根结点时，遍历完成 
			}
			
			p = p->rchild;
		}
	}
}

Status CreateBiTree_6_40(FILE *fp, BiTree *T, BiTree p)			//构造二叉树
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
		CreateBiTree_6_40(fp, &(*T)->lchild, *T);
		CreateBiTree_6_40(fp, &(*T)->rchild, *T);
	}
	
	return OK;
}
