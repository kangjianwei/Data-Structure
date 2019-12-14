#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"	//**��01 ����**//

/* ���Ͷ��� */
typedef char TElemType;							//���������Ԫ�ؾ�Ϊ�ַ� 
typedef struct BiTNode							//��������������洢��ʾ
{
	TElemType data;								//���Ԫ�� 
	struct BiTNode* lchild;						//����ָ�� 
	struct BiTNode* rchild;						//�Һ���ָ��
	struct BiTNode* parent;
	int mark;
}BiTNode;										//��������� 
typedef BiTNode* BiTree;						//ָ�����������ָ��

/* ����ԭ�� */
void Algo_6_39(BiTree T);
Status CreateBiTree_6_39(FILE *fp, BiTree *T, BiTree p);//���������

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("�������������������У�T�� ABDG^^^EH^^I^^CF^J^^^...\n");
	fp = fopen("Data/Algo_6_39.txt", "r");
	CreateBiTree_6_39(fp, &T, NULL);
	fclose(fp);
	printf("\n");

	printf("�����������������Ϊ��");  
	Algo_6_39(T);		
	printf("\n\n");	

	return 0;
}

/*����������������������������
����6.39����������ĵ�����ʽ��
����������������������������*/
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

Status CreateBiTree_6_39(FILE *fp, BiTree *T, BiTree p)		//���������
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
