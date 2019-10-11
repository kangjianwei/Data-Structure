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
	int DescNum;
}BiTNode;										//二叉树结点 
typedef BiTNode* BiTree;						//指向二叉树结点的指针 

/* 函数原型 */
int Algo_6_55(FILE *fp, BiTree *T);
void InitBiTree(BiTree *T);
void PrePrint(BiTree T);

int main(int argc, char *argv[])
{
	BiTree T;
	int way[100];
	int i;
	FILE *fp;
	
	printf("创建二叉树（先序序列）T→ ABDG^^^EH^^I^^CF^J^^^...\n");
	InitBiTree(&T); 
	fp = fopen("Data/Algo_6_55.txt", "r");
	Algo_6_55(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("先序输出二叉树结点值及其相应的子孙数目：\n");
	PrePrint(T);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题6.55：先序创建二叉树，并统计每个结点的子孙数目┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/
int Algo_6_55(FILE *fp, BiTree *T)	//改编自二叉树先序创建算法 
{
	char ch;
	int LDe, RDe;					//记录左右子树子孙数目 
	
	Scanf(fp, "%c", &ch);
	
	if(ch == '^')					//此处结点为空，则视为“欠”一个结点，返回-1 
	{
		*T = NULL;
		return -1;	
	} 
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		LDe = Algo_6_55(fp, &(*T)->lchild);
		RDe = Algo_6_55(fp, &(*T)->rchild);
	}
	
	(*T)->DescNum = LDe + RDe + 2;
	
	return (*T)->DescNum;
}

void InitBiTree(BiTree *T)						//构造空二叉树T 
{
	*T = NULL;
}

void PrePrint(BiTree T)							//先序输出二叉树及各结点其子孙数目 
{
	if(T)
	{
		printf("结点值：%c，子孙数目：%d  \n", T->data, T->DescNum);
		PrePrint(T->lchild);
		PrePrint(T->rchild);
	}
}
