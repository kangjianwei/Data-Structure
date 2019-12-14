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
	int DescNum;
}BiTNode;										//��������� 
typedef BiTNode* BiTree;						//ָ�����������ָ�� 

/* ����ԭ�� */
int Algo_6_55(FILE *fp, BiTree *T);
void InitBiTree(BiTree *T);
void PrePrint(BiTree T);

int main(int argc, char *argv[])
{
	BiTree T;
	int way[100];
	int i;
	FILE *fp;
	
	printf("�������������������У�T�� ABDG^^^EH^^I^^CF^J^^^...\n");
	InitBiTree(&T); 
	fp = fopen("Data/Algo_6_55.txt", "r");
	Algo_6_55(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("����������������ֵ������Ӧ��������Ŀ��\n");
	PrePrint(T);
	printf("\n");
	
	return 0;
}

/*��������������������������������������������������
����6.55�����򴴽�����������ͳ��ÿ������������Ŀ��
��������������������������������������������������*/
int Algo_6_55(FILE *fp, BiTree *T)	//�ı��Զ��������򴴽��㷨 
{
	char ch;
	int LDe, RDe;					//��¼��������������Ŀ 
	
	Scanf(fp, "%c", &ch);
	
	if(ch == '^')					//�˴����Ϊ�գ�����Ϊ��Ƿ��һ����㣬����-1 
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

void InitBiTree(BiTree *T)						//����ն�����T 
{
	*T = NULL;
}

void PrePrint(BiTree T)							//����������������������������Ŀ 
{
	if(T)
	{
		printf("���ֵ��%c��������Ŀ��%d  \n", T->data, T->DescNum);
		PrePrint(T->lchild);
		PrePrint(T->rchild);
	}
}
