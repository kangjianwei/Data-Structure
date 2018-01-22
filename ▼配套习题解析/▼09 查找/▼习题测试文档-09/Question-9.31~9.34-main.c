#include <stdio.h>
#include <limits.h>
#include "../../../▲课本算法实现/▲09 查找/06 BinarySortTree/BinarySortTree.c"	//**▲09 查找**//								

/* 宏定义 */
#define FAIL INT_MAX			//未找到合适值时的标记 
#define MINKEY INT_MIN			//关键字的下限 

/* 函数原型 */
void Algo_9_31(BSTree BST, int *pre, int *flag);
void Algo_9_32(BSTree BST, int x, int *a, int *b, BSTree ptr[], int *count);
void Algo_9_33(BSTree BST, int x);
void Algo_9_34(BSTree *BST, int x);
void DestoryTree_9_34(BSTree *BST);

int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T;
	BSTree BST;
	int x = 42;
	
	printf("创建并输出查找表...\n");
	fp = fopen("Data/Algo_9_31-9_34.txt", "r");	
	Create(fp, &T, 12);		
	printf("T = ");	
	Traverse(T, PrintKey);
	printf("\n"); 

	printf("构造二叉排序树，并由小到大输出其关键字：\n");
	CreateBSTree(&BST, T);
	printf("BST = ");
	InOrderTraverse_BST(BST, PrintKey); 
	printf("\n\n");	
	
	printf("███ 题 9.31 验证... ███\n");
	{
		int pre = MINKEY;
		int flag = TRUE;
		Algo_9_31(BST, &pre, &flag);
		printf("此树"); 
		flag ? printf("是") : printf("不是");
		printf("二叉排序树！\n");
		printf("\n"); 
	}
		
	printf("███ 题 9.32 验证... ███\n");
	{		
		int a ,b ,count;			//count用来计数，初始值设为0 				
		BSTree ptr[12];				//数组容量与二叉排序树关键字个数相等
		a = b = FAIL;
		count = 0;
		Algo_9_32(BST, x, &a, &b, ptr, &count);
		printf("a<x<b：%d < %d < %d\n", a, x, b);
		printf("\n");
	}
	
	printf("███ 题 9.33 验证... ███\n");
	{
		printf("从大到小输出大于 %d 的关键字：", x);
		Algo_9_33(BST, x);
		printf("\n\n");	
	}
	
	printf("███ 题 9.34 验证... ███\n");
	{
		printf("删除二叉排序树中关键字不小于 %d 的结点...\n", x);
		Algo_9_34(&BST, x);
		printf("BST = ");
		InOrderTraverse_BST(BST, PrintKey);
		printf("\n\n");	
	}
			
	return 0;
}

void Algo_9_31(BSTree BST, int *pre, int *flag)
{
	if(*flag==TRUE)
	{
		if(BST->lchild)
			Algo_9_31(BST->lchild, pre, flag);
		
		if(BST->data.key>=*pre)
			*pre = BST->data.key;	
		else
			*flag = FALSE;			
		
		if(BST->rchild)	
			Algo_9_31(BST->rchild, pre, flag);
	}
}

void Algo_9_32(BSTree BST, int x, int *a, int *b, BSTree ptr[], int *count)
{			//count初值为0，用来计数，a、b初值设为标记FAIL，其含义是未找到合适的值 
	if(BST)								//从小到大遍历 
	{
		Algo_9_32(BST->lchild, x, a, b, ptr, count);
		ptr[(*count)++] = BST;
		if(*count>=2)
		{
			if(ptr[*count-2]->data.key<x&&x<=ptr[*count-1]->data.key)
				*a = ptr[*count-2]->data.key;
			if(ptr[*count-2]->data.key<=x&&x<ptr[*count-1]->data.key)
				*b = ptr[*count-1]->data.key;
			if(*a!=FAIL&&*b!=FAIL)		//a、b均找到时结束函数 
				return;
		}
		Algo_9_32(BST->rchild, x, a, b, ptr, count);
	}
}

void Algo_9_33(BSTree BST, int x)
{
	if(BST)									//逆中序遍历
	{
		Algo_9_33(BST->rchild, x);
		
		if(BST->data.key>=x)
			printf("%d ", BST->data.key);
		else
			return;
			
		Algo_9_33(BST->lchild, x);
	}
}

void Algo_9_34(BSTree *BST, int x)
{
	BSTree p;
	
	if(*BST)
	{		
		if((*BST)->data.key>=x)
		{
			p = *BST;
			*BST = p->lchild;
			p->lchild = NULL;		
			DestoryTree_9_34(&p);			//销毁当前结点及当前结点的右子树 
			
			Algo_9_34(BST, x);				//继续考察左子树 
		}			
		else
			Algo_9_34(&(*BST)->rchild, x);	//考察右子树 
	} 
}

void DestoryTree_9_34(BSTree *BST)
{
	if(*BST)
	{
		DestoryTree_9_34(&(*BST)->lchild);	//销毁左子树 
		DestoryTree_9_34(&(*BST)->rchild);	//销毁右子树 
		free(*BST);
		*BST = NULL;
	}
}
