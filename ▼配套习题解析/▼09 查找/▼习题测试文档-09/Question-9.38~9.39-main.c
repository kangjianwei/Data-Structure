#include <stdio.h>
#include "../../../▲课本算法实现/▲09 查找/06 BinarySortTree/BinarySortTree.c"	//**▲09 查找**//								

/* 函数原型 */
void Algo_9_38(BSTree BST1, BSTree *BST2, void(*InsertNode)(BSTree*,BSTree));	//将二叉排序树BST2合并到BST1上 
void Algo_9_39(BSTree *BST, BSTree *BST1, BSTree *BST2, int x, void(*InsertNode)(BSTree*,BSTree));//分解BST 
void InsertNode_9_38(BSTree *BST, BSTree p);	//将p指示的结点插入到二叉排序树BST中合适的位置 

int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T1, T2;
	BSTree BST1, BST2, BST3;
	int x = 45;
		
	printf("创建并输出两个查找表...\n");
	fp = fopen("Data/Algo_9_38-9_39.txt", "r");	
	Create(fp, &T1, 8);
	Create(fp, &T2, 10);		
	printf("T1 = ");
	Traverse(T1, PrintKey);	
	printf("T2 = ");
	Traverse(T2, PrintKey);
	printf("\n"); 
	
	printf("构造两棵二叉排序树，并由小到大输出其关键字：\n");
	CreateBSTree(&BST1, T1);
	CreateBSTree(&BST2, T2);
	printf("BST1 = ");
	InOrderTraverse_BST(BST1, PrintKey);
	printf("\n");
	printf("BST2 = ");
	InOrderTraverse_BST(BST2, PrintKey); 
	printf("\n\n");	
	
	printf("███ 题 9.38 验证... ███\n");
	printf("将 BST2 合并到 BST1 ...\n");
	Algo_9_38(BST1, &BST2, InsertNode_9_38);
	printf("BST1 = ");
	InOrderTraverse_BST(BST1, PrintKey);
	printf("\n\n");	

	printf("███ 题 9.39 验证... ███\n");
	printf("分解 BST1 到 BST2 和 BST3 ，以 %d 为界...\n", x);
	BST2 = BST3 = NULL;
	Algo_9_39(&BST1, &BST2, &BST3, x, InsertNode_9_38);
	printf("BST2 = ", x);
	InOrderTraverse_BST(BST2, PrintKey);
	printf("\n");
	printf("BST3 = ", x);
	InOrderTraverse_BST(BST3, PrintKey);
	printf("\n\n");
		
	return 0;
}

void Algo_9_38(BSTree BST1, BSTree *BST2, void(*InsertNode)(BSTree*,BSTree))
{											//InsertNode函数用来插入结点
	BSTree l, r;
	
	if(*BST2)
	{
		l = (*BST2)->lchild;					 
		r = (*BST2)->rchild;
		(*BST2)->lchild = (*BST2)->rchild = NULL;	//与子结点要及时分离
		
		Algo_9_38(BST1, &l, InsertNode);
		InsertNode(&BST1, *BST2); 
		Algo_9_38(BST1, &r, InsertNode);		
	}
	
	*BST2 = NULL;
}

void Algo_9_39(BSTree *BST, BSTree *BST1, BSTree *BST2, int x, void(*InsertNode)(BSTree*,BSTree))
{												//InsertNode函数用来插入结点
	BSTree l, r;
	
	if(*BST)
	{
		l = (*BST)->lchild;					 
		r = (*BST)->rchild;
		(*BST)->lchild = (*BST)->rchild = NULL;	//与子结点要及时分离

		Algo_9_39(&l, BST1, BST2, x, InsertNode);//先遍历左右子树 
		Algo_9_39(&r, BST1, BST2, x, InsertNode);
		
		if((*BST)->data.key>=x)
			InsertNode(BST1, *BST);
		else
			InsertNode(BST2, *BST);
	}
	
	*BST = NULL;
}

void InsertNode_9_38(BSTree *BST, BSTree p)
{	
	if(*BST)
	{
		if(p->data.key<(*BST)->data.key)
		{
			if((*BST)->lchild==NULL)
				(*BST)->lchild = p;
			else
				InsertNode_9_38(&(*BST)->lchild, p);
		}		
		else if(p->data.key>(*BST)->data.key)
		{
			if((*BST)->rchild==NULL)
				(*BST)->rchild = p;
			else
				InsertNode_9_38(&(*BST)->rchild, p);
		}
		else
			free(p);
	}
	else
		*BST = p;
}
