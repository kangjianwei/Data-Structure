#include <stdio.h>
#include <stdlib.h>								//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/06 ChildTree/ChildTree.c" //**��06 ���Ͷ�����**//

/* ȫ�ֱ��� */
CTree H;								//�Զ���ʼ����Ĭ�ϸ������0�ŵ�Ԫ 

/* ����ԭ�� */
void Algo_6_75(FILE *fp, int parent);
void Algo_6_76_1(CTree H, int i);
void Algo_6_76_2(CTree H, int i);

int main(int argc, char *argv[])
{
	FILE *fp; 

	printf("�� 6.75 ��֤...\n");	
	printf("��Ϊʾ����¼�����У�A(B(E,F),C(G),D)...\n");
	printf("��������-�ֵ�����...\n");
	fp = fopen("Data/Algo_6_75-6.76.txt", "r");
	Algo_6_75(fp, -1);
	fclose(fp);
	Print_C_2(H, H.r, 0);
	printf("\n");

	printf("�� 6.76 ��֤...\n");	
	printf("��������ӡ��������...\n");
	printf("���� 1 ��");
	Algo_6_76_1(H, H.r);
	printf("\n");
	printf("���� 2 ��");
	Algo_6_76_2(H, H.r);
	printf("\n\n");
			
	return 0;
}

/*����������������������������������������
����6.75��������������(��δ����˫�׽��)��
����������������������������������������*/
void Algo_6_75(FILE *fp, int parent)	//parent��ǵ�ǰλ�ý���˫�׽��λ�� 
{										//��������������Ϊȫ�ֱ�����
	char c;	
	ChildPtr p, q;
	
	while(1)
	{	
		Scanf(fp, "%c", &c);
		if(feof(fp))
			break;

		if(c>='A' && c<='Z')
		{
			H.nodes[H.n].data = c;		//H.n����׷�ٽ�����			
						
			if(parent!=-1)
			{
				p = (ChildPtr)malloc(sizeof(CTNode));
				p->child = H.n;
				p->next = NULL;
			
				q = H.nodes[parent].firstchild;
				if(!q)
					H.nodes[parent].firstchild = p;
				else
				{			
					while(q->next)
						q = q->next;
					q->next = p;			
				}			
			}

			H.n++;
		}
		else if(c=='(')
			Algo_6_75(fp, H.n-1);		//��һ������
		else if(c==',')					//�����ֵܽ�� 
		{
			Algo_6_75(fp, parent);
			break;		
		}
		else
			break;			
	}
}

/*����������������������������������������������������
����6.76���������ʽ��ӡ��������(��δ����˫�׽��)��
����������������������������������������������������*/
/* ����1 */
void Algo_6_76_1(CTree H, int i)
{
	ChildPtr p;

	if(H.n)
	{
		printf("%c", H.nodes[i].data);		//��ӡ˫�׽�� 
		
		if(H.nodes[i].firstchild)	
		{
			printf("(");

			p = H.nodes[i].firstchild;
			
			while(p)						//��ӡ�����ӽ�� 
			{
				Algo_6_76_1(H, p->child);
				p = p->next;				//���������� 
				if(p)
					printf(",");
				else
					printf(")");
			}		
		}			
	}
}

/* ����2���ı���ѭ����ʽ */
void Algo_6_76_2(CTree H, int i)
{
	ChildPtr p;

	if(H.n)
	{
		printf("%c", H.nodes[i].data);					//��ӡ˫�׽�� 
		
		if(H.nodes[i].firstchild)	
		{
			printf("(");
			
			for(p=H.nodes[i].firstchild; p; p=p->next)	//�߱����ߴ�ӡ 
			{
				Algo_6_76_2(H, p->child);
				if(p->next)
					printf(",");
			}
			
			printf(")");			
		}			
	}
}
