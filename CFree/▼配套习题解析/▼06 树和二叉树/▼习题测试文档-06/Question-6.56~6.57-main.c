#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/04 ThreadBinaryTree/ThreadBinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
ThrBiTree Algo_6_56(ThrBiTree p);
ThrBiTree Algo_6_57(ThrBiTree p);

int main(int argc, char *argv[])
{	
	int mark;
	ThrBiTree Thrt, T;
	ThrBiTree p;
	FILE *fp;
	
	printf("��֤�� 6.56 ���� 1 ����֤�� 6.57 ���� 2 ��");
	fflush(stdin);
	scanf("%d", &mark);
	printf("\n");
	
	printf("��Ϊʾ��¼���������У�ABDG^^^EH^^I^^CF^J^^^\n\n");
	fp = fopen("Data/Algo_6_56-6.57.txt", "r");
	CreateBiTree_Thr(fp, &T);
	fclose(fp);
	
	p = T->lchild;									//���ڲ��Ե�p 
		
	if(mark==1)
	{
		printf("������ �� 6.56 ��֤... ������\n");
		PreOrderThreading_Thr(&Thrt, T);
		printf("�����������������У�%c �ĺ��Ϊ��", p->data);
		p = Algo_6_56(p);
		printf("%c ��\n\n", p->data);
	}
	
	if(mark==2)
	{
		printf("������ �� 6.57 ��֤... ������\n");
		ParentPtr_Thr(T);
		PosOrderThreading_Thr(&Thrt, T);
		printf("�ں��������������У� %c �ĺ��Ϊ��", p->data);
		p = Algo_6_57(p);
		printf(" %c ��\n\n", p->data);
	}

	return 0;
}

/*��������������������������������������������
����6.56����������������������Ѱ��p�ĺ�� ��
��������������������������������������������*/
ThrBiTree Algo_6_56(ThrBiTree p)
{
	if(p->RTag==Thread)
		p = p->rchild;
	else
	{
		if(p->lchild)
			p = p->lchild;
		else
			p = p->rchild;
	}
	
	if(p->data)					//�ж�p�Ƿ�ָ��ͷ��� 
		return p;
	else
		return NULL;			//���һ������޺�� 
}

/*��������������������������������������������
����6.57���ں�����������������Ѱ��p�ĺ�� ��
��������������������������������������������*/
ThrBiTree Algo_6_57(ThrBiTree p)
{
	if(p->parent==NULL)									//����������һ����㣬�޺�� 
		return NULL;
	else
	{
		if(p->RTag==Thread)								//�Һ���Ϊ���� 
			return p->rchild;
		else
		{												
			if(p==p->parent->rchild)					//��ǰ��������� 
				return p->parent;
			else
			{		
				if(p->parent->RTag!=Link)				//˫��û���Һ��� 
					p = p->parent;
				else
				{
					p = p->parent->rchild;
					while(1)							//Ѱ�����ֵܱ������ 
					{
						while(p->lchild)					 
							p = p->lchild;		
			
						if(p->rchild && p->RTag!=Thread)
							p = p->rchild;
						else
							break;
					}
				}
				
				return p;				
			}
		}
	}
}
