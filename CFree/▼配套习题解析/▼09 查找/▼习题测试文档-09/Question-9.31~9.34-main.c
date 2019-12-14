#include <stdio.h>
#include <limits.h>
#include "../../../���α��㷨ʵ��/��09 ����/06 BinarySortTree/BinarySortTree.c"	//**��09 ����**//								

/* �궨�� */
#define FAIL INT_MAX			//δ�ҵ�����ֵʱ�ı�� 
#define MINKEY INT_MIN			//�ؼ��ֵ����� 

/* ����ԭ�� */
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
	
	printf("������������ұ�...\n");
	fp = fopen("Data/Algo_9_31-9_34.txt", "r");	
	Create(fp, &T, 12);		
	printf("T = ");	
	Traverse(T, PrintKey);
	printf("\n"); 

	printf("�������������������С���������ؼ��֣�\n");
	CreateBSTree(&BST, T);
	printf("BST = ");
	InOrderTraverse_BST(BST, PrintKey); 
	printf("\n\n");	
	
	printf("������ �� 9.31 ��֤... ������\n");
	{
		int pre = MINKEY;
		int flag = TRUE;
		Algo_9_31(BST, &pre, &flag);
		printf("����"); 
		flag ? printf("��") : printf("����");
		printf("������������\n");
		printf("\n"); 
	}
		
	printf("������ �� 9.32 ��֤... ������\n");
	{		
		int a ,b ,count;			//count������������ʼֵ��Ϊ0 				
		BSTree ptr[12];				//��������������������ؼ��ָ������
		a = b = FAIL;
		count = 0;
		Algo_9_32(BST, x, &a, &b, ptr, &count);
		printf("a<x<b��%d < %d < %d\n", a, x, b);
		printf("\n");
	}
	
	printf("������ �� 9.33 ��֤... ������\n");
	{
		printf("�Ӵ�С������� %d �Ĺؼ��֣�", x);
		Algo_9_33(BST, x);
		printf("\n\n");	
	}
	
	printf("������ �� 9.34 ��֤... ������\n");
	{
		printf("ɾ�������������йؼ��ֲ�С�� %d �Ľ��...\n", x);
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
{			//count��ֵΪ0������������a��b��ֵ��Ϊ���FAIL���京����δ�ҵ����ʵ�ֵ 
	if(BST)								//��С������� 
	{
		Algo_9_32(BST->lchild, x, a, b, ptr, count);
		ptr[(*count)++] = BST;
		if(*count>=2)
		{
			if(ptr[*count-2]->data.key<x&&x<=ptr[*count-1]->data.key)
				*a = ptr[*count-2]->data.key;
			if(ptr[*count-2]->data.key<=x&&x<ptr[*count-1]->data.key)
				*b = ptr[*count-1]->data.key;
			if(*a!=FAIL&&*b!=FAIL)		//a��b���ҵ�ʱ�������� 
				return;
		}
		Algo_9_32(BST->rchild, x, a, b, ptr, count);
	}
}

void Algo_9_33(BSTree BST, int x)
{
	if(BST)									//���������
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
			DestoryTree_9_34(&p);			//���ٵ�ǰ��㼰��ǰ���������� 
			
			Algo_9_34(BST, x);				//�������������� 
		}			
		else
			Algo_9_34(&(*BST)->rchild, x);	//���������� 
	} 
}

void DestoryTree_9_34(BSTree *BST)
{
	if(*BST)
	{
		DestoryTree_9_34(&(*BST)->lchild);	//���������� 
		DestoryTree_9_34(&(*BST)->rchild);	//���������� 
		free(*BST);
		*BST = NULL;
	}
}
