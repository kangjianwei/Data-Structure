#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c" //**��06 ���Ͷ�����**//

/* �궨�� */
#define MAX_TREE_SIZE 100						//����������� 

/* ����˫�״洢���Ͷ��� */
typedef struct PTNode							//���ṹ 
{
	char data;
	int parent;									//˫��λ���� 
}PTNode; 
typedef struct									//���ṹ 
{
	PTNode nodes[MAX_TREE_SIZE];				//�����λ��Ĭ�ϵ�0��Ϊ�˲�������
	int n;										//���Ľ����
}PTree;

/* ����ԭ�� */
CSTree Algo_6_66(PTree T); 

int main(int argc, char *argv[])
{
	PTree PT;
	CSTree CST;
	
	PT.n = 10;
	
	PT.nodes[0].data = 'R'; PT.nodes[0].parent = -1;
	PT.nodes[1].data = 'A'; PT.nodes[1].parent = 0;
	PT.nodes[2].data = 'B'; PT.nodes[2].parent = 0;
	PT.nodes[3].data = 'C'; PT.nodes[3].parent = 0;
	PT.nodes[4].data = 'D'; PT.nodes[4].parent = 1;
	PT.nodes[5].data = 'E'; PT.nodes[5].parent = 1;
	PT.nodes[6].data = 'F'; PT.nodes[6].parent = 3;
	PT.nodes[7].data = 'G'; PT.nodes[7].parent = 6;
	PT.nodes[8].data = 'H'; PT.nodes[8].parent = 6;
	PT.nodes[9].data = 'K'; PT.nodes[9].parent = 6;
	
	CST = Algo_6_66(PT); 
	
	printf("�����ĺ����ֵܶ�����Ϊ��\n");
	Print_CS(CST);
	printf("\n");
	
	return 0;
}

/*����������������������������������������������
�� ��6.66������˫�ױ�ʾ�������ĺ���-�ֵܱ�ʾ����
����������������������������������������������*/
CSTree Algo_6_66(PTree T) 						//������˫�׽ṹ�����������ĺ���-�ֵ����� 
{
	int i, j, k;
	CSTree p, q;
	CSTree tmp[100];
	
	for(i=0,j=0; i<T.n; i++)					//˫�ױ�����洢
	{
		k = T.nodes[i].parent;
		
		p = (CSTree)malloc(sizeof(CSNode));
		if(!p)
			exit(OVERFLOW);
		p->data = T.nodes[i].data;
		p->firstchild = p->nextsibling = NULL;
		
		if(k!=-1)
		{
			if(tmp[k]->firstchild==NULL)		//��Ϊ��һ������ 
				tmp[k]->firstchild = p;
			else
			{
				q = tmp[k]->firstchild;			//Ѱ�Һ��������ĩ�� 
				while(q->nextsibling)
					q = q->nextsibling;
				q->nextsibling = p;
			}	
		}
		
		tmp[j++] = p;	
	}
	
	if(j)
		return tmp[0];
	else
		return NULL;
}
