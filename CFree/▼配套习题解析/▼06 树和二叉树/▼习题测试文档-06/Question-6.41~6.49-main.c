#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
Status Algo_6_41(BiTree T, TElemType *e, int *order, int k);
int Algo_6_42(BiTree T);
void Algo_6_43(BiTree T);
int Algo_6_44(BiTree T, TElemType x);
void Algo_6_45(BiTree *T, TElemType x);
void Algo_6_46(BiTree T, BiTree *Tx);
void Algo_6_47(BiTree T);
BiTree Algo_6_48(BiTree T, TElemType p, TElemType q);
Status FindPath_6_48(BiTree T, TElemType p, BiTree path[100]);
Status Algo_6_49(BiTree T);

int main(int argc, char *argv[])
{ 
	BiTree T, Tx, Tmp;
	TElemType e;
	int k, order;								//orderΪ�������									 
	char x;
	FILE *fp;
	int mark;									//��֤���
		
	printf("�������������������У�T�� ABDG^^^EH^^I^^CF^J^^^...\n");
	InitBiTree(&T); 
	fp = fopen("Data/Algo_6_41-6_49.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("������TΪ��\n");
	PrintTree(T);
	printf("\n");

	printf("��֤�� 6.41 - 6.49 �ֱ����� 1 - 9��");
	fflush(stdin);
	scanf("%d", &mark);
	printf("\n");
	
	if(mark==1)
	{
		printf("������ �� 6.41 ��֤... ������\n");
		while(1)
		{
			printf("������kֵ��0�˳���֤���� ");
			fflush(stdin);
			scanf("%d", &k);
	
			order = 0;									//��0��ʼ���� 
			
			if(k==0)
				break;
			else
			{
				if(Algo_6_41(T, &e, &order, k))
					printf("���������е� %d ��Ԫ��Ϊ %c \n", k, e);		
				else
					printf("�˴�Ԫ�ز����ڣ�\n");
				printf("\n");		
			}
		}
	}
	
	if(mark==2)
	{
		printf("������ �� 6.42 ��֤... ������\n");
		printf("��������Ҷ�ӽ�����Ϊ�� %d��\n", Algo_6_42(T));	
	}	
	
	if(mark==3)
	{
		printf("������ �� 6.43 ��֤... ������\n");
		printf("���������������������������Ϊ��\n");
		Algo_6_43(T); 
		PrintTree(T);
	}
	
	if(mark==4)
	{
		printf("������ �� 6.44 ��֤... ������\n");
		while(1)
		{
			printf("������ĳ�����ĸ���� 'x'��0�˳���֤����");
			fflush(stdin);
			scanf("%c", &x);
			
			if(x=='0')
				break;
			
			printf("���� %c �����Ϊ�� %d\n", x, Algo_6_44(T, x));
			printf("\n");	
		}
	}
	
	if(mark==5)
	{
		printf("������ �� 6.45 ��֤... ������\n");
		printf("����������ĳ����� 'x'��");
		fflush(stdin);
		scanf("%c", &x);
		printf("\n");
		
		printf("ɾ������ %c �󣬶�����Ϊ��\n", x);
		Algo_6_45(&T, x); 
		PrintTree(T);			
	}
	
	if(mark==6)
	{
		printf("������ �� 6.46 ��֤... ������\n");
		printf("���� T �� Tx �󣬶�����TxΪ��\n");
		Algo_6_46(T, &Tx); 
		PrintTree(Tx);			
	}
	
	if(mark==7)
	{
		printf("������ �� 6.47 ��֤... ������\n");
		printf("�����������������Ϊ��");  
		Algo_6_47(T);
		printf("\n");			
	}
	
	if(mark==8)
	{
		printf("������ �� 6.48 ��֤... ������\n");
		Tmp = Algo_6_48(T, 'G', 'H');
		printf("'%c' �� '%c' �������ͬ����Ϊ��'%c'\n", 'G', 'H', Tmp->data);	
	}
	
	if(mark==9)
	{
		printf("������ �� 6.49 ��֤... ������\n");
		printf("�˶�����");
		Algo_6_49(T) ? printf("��") : printf("����");
		printf("��ȫ��������\n");	
	}
			
	printf("\n");
		
	return 0;
}

/*������������������������������������
����6.41�������������е�k������ֵ ��
������������������������������������*/
Status Algo_6_41(BiTree T, TElemType *e, int *order, int k)	//order�������� 
{
	if(T)
	{
		(*order)++;
		
		if(*order==k)
		{
			*e = T->data;		
			return OK;					
		}
		else
		{		
			if(Algo_6_41(T->lchild, e, order, k))
				return OK;
			if(Algo_6_41(T->rchild, e, order, k))
				return OK;
		}
	}
	
	return ERROR;
}

/*����������������������������������
����6.42�������������Ҷ�ӽ����Ŀ��
����������������������������������*/
int Algo_6_42(BiTree T)
{
	int count = 0;
	
	if(T)
	{
		if(T->lchild==NULL && T->rchild==NULL)
			count++;
		else
		{
			count += Algo_6_42(T->lchild);
			count += Algo_6_42(T->rchild);
		}	
	}
	
	return count;	 
}

/*������������������������������
����6.43������������������������
������������������������������*/
void Algo_6_43(BiTree T)
{
	BiTree p;
	
	if(T)
	{
		p = T->lchild;
		T->lchild = T->rchild;
		T->rchild = p;

		Algo_6_43(T->lchild);
		Algo_6_43(T->rchild);
	}
}

/*����������������������������������������������
����6.44������������Խ��'x'Ϊ������������� ��
����������������������������������������������*/
int Algo_6_44(BiTree T, TElemType x)
{
	 BiTree p;
	 
	 p = LocationBiTree_2(T, x);			//��һ���ݹ����x��λ�ã���ָ����ʽ����
	 
	 return BiTreeDepth(p);				//�ڶ����ݹ��������x����� 
}

/*��������������������������������������������������������
����6.45��ɾ��Ԫ��ֵΪ'x'�Ľ�㣨���ܲ�ֹһ������������ ��
��������������������������������������������������������*/
void Algo_6_45(BiTree *T, TElemType x)
{
	if(*T)
	{
		if((*T)->data==x)
			ClearBiTree(T);						//�ݹ�������� 
		else
		{
			Algo_6_45(&((*T)->lchild), x);		//�ݹ�����������Ѱ�� 
			Algo_6_45(&((*T)->rchild), x);
		}
	}
}

/*��������������������������������
����6.46�����ƶ������ķǵݹ��㷨��
��������������������������������*/
void Algo_6_46(BiTree T, BiTree *Tx)
{
	SqStack ST, STx;
	SElemType_Sq e;
	BiTree p, q;
	 
	if(!BiTreeEmpty(T))
	{
		InitStack_Sq(&ST);
		InitStack_Sq(&STx);
		
		Push_Sq(&ST, T);
		p = (BiTree)malloc(sizeof(BiTNode));
		if(!p)
			exit(OVERFLOW);
		p->data = T->data;
		*Tx = p;
		Push_Sq(&STx, *Tx);
		
		while(!StackEmpty_Sq(ST))
		{
			GetTop_Sq(ST, &e);
			GetTop_Sq(STx, &q);
			
			if(e->lchild)								//������� 
			{
				Push_Sq(&ST, e->lchild);
				p = (BiTree)malloc(sizeof(BiTNode));
				if(!p)
					exit(OVERFLOW);
				p->data = e->lchild->data;
				q->lchild = p;
				Push_Sq(&STx, q->lchild);			
			}
			else										//���ҷ��ʲ����� 
			{
				q->lchild = NULL;
				while(!StackEmpty_Sq(ST))
				{
					Pop_Sq(&ST, &e);
					Pop_Sq(&STx, &q);
										
					if(e->rchild)
					{	
						Push_Sq(&ST, e->rchild);
						p = (BiTree)malloc(sizeof(BiTNode));
						if(!p)
							exit(OVERFLOW);
						p->data = e->rchild->data;
						q->rchild = p;
						Push_Sq(&STx, q->rchild);						
						break;					
					}
					else
						q->rchild = NULL;				
				}
			}
		}
	}
}

/*������������������������
����6.47�����������������
������������������������*/
void Algo_6_47(BiTree T)
{
	int i, j;
	BiTree p[100];					//��ָ�����飬����ģ����� 
	
	i = j = 0;
	
	if(T)
		p[j++] = T;
		
	while(i<j)
	{
		printf("%c ", p[i]->data);
		if(p[i]->lchild)
			p[j++] = p[i]->lchild;
		if(p[i]->rchild)
			p[j++] = p[i]->rchild;
		i++;		
	}
}

/*����������������������������������������������������������
��������Ѱ�Ҹ���㵽p����·����path�洢·���ϸ����ָ�� ��
����������������������������������������������������������*/
Status FindPath_6_48(BiTree T, TElemType p, BiTree path[100])
{
	BiTNode node[100];
	int i = 0;
	
	if(T==NULL)
		return ERROR;
	
	path[i] = T;
	node[i] = *T;
		
	while(i>=0)
	{
		while(node[i].lchild || path[i]->data==p)
		{
			if(path[i]->data==p)						//Ѱ·�ɹ� 
				return OK;
			else
			{
				path[i+1] = node[i].lchild;
				node[i+1] = *(node[i].lchild);
				node[i].lchild = NULL;
				i++;			
			}
		}
		
		if(node[i].rchild)
		{
			path[i+1] = node[i].rchild;
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		else
		{
			path[i] = NULL;
			i--;
		}		
	}
	
	if(i<0)												//Ѱ·ʧ�� 
		return ERROR;
}

/*����������������������������
����6.48���������Ĺ�ͬ���ȩ�
����������������������������*/
BiTree Algo_6_48(BiTree T, TElemType p, TElemType q)		//p��q��Ϊ�����Ԫ�أ�ԭ���� 
{
	BiTree path_1[100] = {};
	BiTree path_2[100] = {}; 
	int k, x;
	
	if(FindPath_6_48(T, p, path_1) && FindPath_6_48(T, q, path_2))	//������·��Ѱ�Һ��� 
	{	
		k = 0;
		if(path_1[k]->data!=p && path_2[k]->data!=q)
		{
			while(path_1[k]->data==path_2[k]->data)
				k++;
			
			return path_1[k-1];		
		}
	}

	return NULL;
}

/*������������������������������������
����6.49���ж϶������Ƿ�Ϊ��ȫ��������
������������������������������������*/
Status Algo_6_49(BiTree T)
{
	int i, j;
	BiTree p[100] = {};					//��ָ�����飬ģ����� 
	int order[100] = {}; 
	
	i = j = 0;
	
	if(T)								//������ͬʱΪ������� 
	{
		p[j] = T;	
		order[j] = 1;
		j++;
		
		while(i<j)
		{
			if(i>0 && order[i]>order[i-1]+1)
				return ERROR;			//�������Ų������������ȫ������ 
				
			if(p[i]->lchild)
			{
				p[j] = p[i]->lchild;
				order[j] = 2*order[i];
				j++;			
			}

			if(p[i]->rchild)
			{
				p[j] = p[i]->rchild;
				order[j] = 2*order[i]+1;
				j++;
			}
			
			i++;		
		}
	}
	
	return OK;
} 
