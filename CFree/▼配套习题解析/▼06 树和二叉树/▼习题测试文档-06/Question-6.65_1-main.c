#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
Status Algo_6_65_1(BiTree *T, char pre[], char in[]);
int RelativePosition_6_65(char *s, char A, char B);		//����������A���B��λ����Ϣ

int main(int argc, char *argv[])
{
	BiTree T;
	char pre[] = "ABDGEHICFJ";
	char in[] =  "GDBHEIAFJC";
	
	printf("��������������Ϊ��%s\n", pre);
	printf("��������������Ϊ��%s\n", in);
	printf("\n");
		
	Algo_6_65_1(&T, pre, in);	
	printf("�ɴ˹���Ķ�����Ϊ��\n");
	PrintTree(T);
	printf("\n");
	
	return 0;
}

/*������������������������������������������
����6.65������ǰ�����к��������д�����������
������������������������������������������*/
/* ����1�����÷ǵݹ���ʽ����ǰ�����д��������� */
Status Algo_6_65_1(BiTree *T, char pre[], char in[])
{
	SqStack S;
	SElemType_Sq e;
	int k;
	BiTree p, q;
	 
	*T = NULL;	
	k = -1;
	
	InitStack_Sq(&S);
	
	while(pre[k+1]!='\0')							//������������ 
	{
		k++;
		
		p = (BiTree)malloc(sizeof(BiTNode));
		if(!p)
			exit(OVERFLOW);
		p->data = pre[k];
		p->lchild = p->rchild = NULL;
		
		if(!(*T))
			*T = p;
		else
		{
			GetTop_Sq(S, &e);
			
			if(RelativePosition_6_65(in, pre[k], e->data)<0)//�����������жϵ�ǰ������λ�� 
				e->lchild = p;								//pre[k]�� e->data����� 
			else											//pre[k]�� e->data���ұ�ʱһֱ��ջ�ҵ����һ�����ұߵ� 
			{
				do
				{
					Pop_Sq(&S, &e);
					if(!StackEmpty_Sq(S))
						GetTop_Sq(S, &q);
					else
						break;
				}
				while(RelativePosition_6_65(in, pre[k], q->data)>0);
				
				e->rchild = p;	
			}
		}
		
		Push_Sq(&S, p);
	}
	
	return OK;
}

int RelativePosition_6_65(char *s, char A, char B)		//����������A���B��λ����Ϣ 
{														//�����ַ���s��A��B��������Ψһ 
	int k, a, b;
	
	k = a = b = -1;
	
	while(s[k+1]!='\0')
	{
		k++;
		
		if(s[k]==A)
			a = k;
		if(s[k]==B)
			b = k;
	}
	
	if(a>=0 && b>=0)
	{
		if(a<b)
			return -1;								//A��B�����
		if(a>b)
			return 1;								//A��B���ұ�		
	}
	else
		return 0;									//��ʾ�������˳� 
}
