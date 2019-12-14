#include <stdio.h>
#include "../../../���α��㷨ʵ��/��09 ����/06 BinarySortTree/BinarySortTree.c"	//**��09 ����**//								

/* ����ԭ�� */
void Algo_9_38(BSTree BST1, BSTree *BST2, void(*InsertNode)(BSTree*,BSTree));	//������������BST2�ϲ���BST1�� 
void Algo_9_39(BSTree *BST, BSTree *BST1, BSTree *BST2, int x, void(*InsertNode)(BSTree*,BSTree));//�ֽ�BST 
void InsertNode_9_38(BSTree *BST, BSTree p);	//��pָʾ�Ľ����뵽����������BST�к��ʵ�λ�� 

int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T1, T2;
	BSTree BST1, BST2, BST3;
	int x = 45;
		
	printf("����������������ұ�...\n");
	fp = fopen("Data/Algo_9_38-9_39.txt", "r");	
	Create(fp, &T1, 8);
	Create(fp, &T2, 10);		
	printf("T1 = ");
	Traverse(T1, PrintKey);	
	printf("T2 = ");
	Traverse(T2, PrintKey);
	printf("\n"); 
	
	printf("�������ö���������������С���������ؼ��֣�\n");
	CreateBSTree(&BST1, T1);
	CreateBSTree(&BST2, T2);
	printf("BST1 = ");
	InOrderTraverse_BST(BST1, PrintKey);
	printf("\n");
	printf("BST2 = ");
	InOrderTraverse_BST(BST2, PrintKey); 
	printf("\n\n");	
	
	printf("������ �� 9.38 ��֤... ������\n");
	printf("�� BST2 �ϲ��� BST1 ...\n");
	Algo_9_38(BST1, &BST2, InsertNode_9_38);
	printf("BST1 = ");
	InOrderTraverse_BST(BST1, PrintKey);
	printf("\n\n");	

	printf("������ �� 9.39 ��֤... ������\n");
	printf("�ֽ� BST1 �� BST2 �� BST3 ���� %d Ϊ��...\n", x);
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
{											//InsertNode��������������
	BSTree l, r;
	
	if(*BST2)
	{
		l = (*BST2)->lchild;					 
		r = (*BST2)->rchild;
		(*BST2)->lchild = (*BST2)->rchild = NULL;	//���ӽ��Ҫ��ʱ����
		
		Algo_9_38(BST1, &l, InsertNode);
		InsertNode(&BST1, *BST2); 
		Algo_9_38(BST1, &r, InsertNode);		
	}
	
	*BST2 = NULL;
}

void Algo_9_39(BSTree *BST, BSTree *BST1, BSTree *BST2, int x, void(*InsertNode)(BSTree*,BSTree))
{												//InsertNode��������������
	BSTree l, r;
	
	if(*BST)
	{
		l = (*BST)->lchild;					 
		r = (*BST)->rchild;
		(*BST)->lchild = (*BST)->rchild = NULL;	//���ӽ��Ҫ��ʱ����

		Algo_9_39(&l, BST1, BST2, x, InsertNode);//�ȱ����������� 
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
