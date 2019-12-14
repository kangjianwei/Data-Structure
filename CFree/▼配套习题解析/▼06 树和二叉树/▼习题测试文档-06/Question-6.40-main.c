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
}BiTNode;										//��������� 
typedef BiTNode* BiTree;						//ָ�����������ָ��

/* ����ԭ�� */
void Algo_6_40(BiTree T);
Status CreateBiTree_6_40(FILE *fp, BiTree *T, BiTree p);	//���������

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("�������������������У�T�� ABDG^^^EH^^I^^CF^J^^^...\n");
	fp = fopen("Data/Algo_6_40.txt", "r");
	CreateBiTree_6_40(fp, &T, NULL);
	fclose(fp);
	printf("\n");

	printf("�����������������Ϊ��");  
	Algo_6_40(T);		
	printf("\n\n");	

	return 0;
}

/*����������������������������
����6.40����������ĵ�����ʽ��
����������������������������*/
void Algo_6_40(BiTree T)						//�ؼ��Ƿֱ浱ǰ���ڼ��α����� 
{
	BiTree p = T;
	
	while(p)
	{	
 		if(p->lchild)							//��һ�η��ʽ�㣬������� 
 			p = p->lchild;
		else
		{
			printf("%c ", p->data);				//�����������صĽ��ڶ��α�����,Ҫ��� 
			
			while(!(p->rchild))					
			{									//����ǰ��������ҷ�֧�����ص�������Ҫ���������
				while(p->parent && p->parent->rchild==p)
					p = p->parent;				//�����������صĽ������α����ʣ������ 
					
				if(p->parent)
				{
					if(p->parent->lchild==p)	//����ǰ����������֧�����ص�������Ҫ���ʸ����	 
					{
						p = p->parent;
						printf("%c ", p->data);//ͬ��������������
					}
				}
				else
					return;						//�����������ص������ʱ��������� 
			}
			
			p = p->rchild;
		}
	}
}

Status CreateBiTree_6_40(FILE *fp, BiTree *T, BiTree p)			//���������
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
