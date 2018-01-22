#include <stdio.h>
#include "../../../▲课本算法实现/▲09 查找/07 BalancedBinarySortTree/BalancedBinarySortTree.c" //**▲09 查找**//

/* 宏定义 */
#define Max 15

/* 函数原型 */
BBSTree Algo_9_40(BBSTree BBST, int k);	//找出平衡二叉树中第k小的结点 
int fLsize_9_40(BBSTree BBST);			//计算lsize值

int main(int argc, char *argv[])
{	

	FILE *fp;
	Table T;
	BBSTree BBST, p;
	int k = 5;
		
	printf("创建并输出一个查找表...\n");
	fp = fopen("Data/Algo_9_40.txt", "r");	
	Create(fp, &T, Max);	
	Traverse(T, PrintKey);	
	printf("\n");	
		
	printf("构造并打印二叉排序树中的关键字：");
	CreateAVL(&BBST, T);	
	printf("打印平衡二叉树：\n");
	PrintAVLTree(BBST);
	printf("\n");

	fLsize_9_40(BBST);				 
	p = Algo_9_40(BBST, k);
	printf("平衡二叉树中从小到大排列第 %d 个关键字为 %d 。\n", k, p->data);
	printf("\n");
		
	return 0;
}

BBSTree Algo_9_40(BBSTree BBST, int k)
{
	if(!BBST)
		return NULL;
	else
	{
		if(k==BBST->lsize)
			return BBST;
		else if(k<BBST->lsize)
			return Algo_9_40(BBST->lchild, k);
		else
			return Algo_9_40(BBST->rchild, k-BBST->lsize);	//k值改变 
	}
}

int fLsize_9_40(BBSTree BBST)
{
	int lnum, rnum;
	
	if(BBST)
	{
		lnum = fLsize_9_40(BBST->lchild);	//左子树结点个数 
		rnum = fLsize_9_40(BBST->rchild);	//右子树结点个数 
		
		BBST->lsize = lnum + 1;
		
		return lnum+rnum+1;
	}
	else
		return 0;
}
