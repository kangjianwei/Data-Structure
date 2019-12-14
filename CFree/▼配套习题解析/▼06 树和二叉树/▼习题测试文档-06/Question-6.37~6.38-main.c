#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"				//**01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**06 ���Ͷ�����**//

/* ����ԭ�� */
void Algo_6_37(BiTree T);
void Algo_6_38(BiTree T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("�������������������У�T�� ABDG^^^EH^^I^^CF^J^^^...\n");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_37-6_38.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("������TΪ��\n");
	PrintTree(T);
	printf("\n");

	printf("�������� 6.37 ��֤...������\n");
	{
		printf("�����������������Ϊ��");  
		Algo_6_37(T);
		printf("\n\n");	
	}
	
	printf("�������� 6.38 ��֤...������\n");
	{
		printf("�����������������Ϊ��");  
		Algo_6_38(T);
		printf("\n\n");	
	}
	
	return 0;
}
/*������������������������������
����6.37����������ķǵݹ���ʽ��
������������������������������*/
void Algo_6_37(BiTree T)
{
	SqStack S;
	SElemType_Sq e;
	
	if(!BiTreeEmpty(T))
	{
		InitStack_Sq(&S);
		Push_Sq(&S, T);
		
		while(!StackEmpty_Sq(S))
		{
			GetTop_Sq(S, &e);
			printf("%c ", e->data);
			
			if(e->lchild)
				Push_Sq(&S, e->lchild);
			else
			{
				while(!StackEmpty_Sq(S))
				{
					Pop_Sq(&S, &e);
					
					if(e->rchild)
					{
						Push_Sq(&S, e->rchild);
						break;					
					}
				}
			}
		}
	}
}

/*������������������������������
����6.38����������ķǵݹ���ʽ��
������������������������������*/
void Algo_6_38(BiTree T)
{
	SqStack S;
	BiTree p;
	SElemType_Sq e;
	int StackMark[100] = {};							//ģ��ջ�����ø������ʱ�� 
	int k;

	InitStack_Sq(&S);
	p = T;
	k = -1;
		
	while(1)
	{
		while(p)
		{
			Push_Sq(&S, p);
			k++;
			StackMark[k] = 1;
			p = p->lchild;
		}
			
		while(!p && !StackEmpty_Sq(S))			//pΪ�յ�ջ��Ϊ�� 
		{
			GetTop_Sq(S, &p);
			
			if(StackMark[k]==1)				//�ѷ��ʹ�һ�Σ���ǰ�ǵڶ��η��� 
			{
				StackMark[k] = 2;				
				p = p->rchild;
			}
			else							//�ѷ��ʹ����Σ���ǰ�ǵ����η��� 
			{
				printf("%c ", p->data);
				Pop_Sq(&S, &e);
				StackMark[k] = 0;
				k--;
				p = NULL;
			}
		}
		
		if(StackEmpty_Sq(S))
			break;
	}		
}
