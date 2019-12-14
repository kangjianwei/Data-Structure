#include <stdio.h>
#include <stdlib.h>								//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/07 ChildSiblingTree/ChildSiblingTree.c" //**��06 ���Ͷ�����**//

/* ���Ͷ��� */
typedef	struct 
{
	TElemType_CS e;						//����ֵ 
	int d;								//���Ķ� 
}TreeNode;

/* ����ԭ�� */
void Algo_6_68(CSTree *T, TreeNode node[]);

int main(int argc, char *argv[])
{
	CSTree T;
	TreeNode node[100];
	
	node[0].e = '\0'; node[0].d = 10;		//0�ŵ�Ԫd�洢������ 
	node[1].e = 'R';  node[1].d = 3;
	node[2].e = 'A';  node[2].d = 2;
	node[3].e = 'B';  node[3].d = 0;
	node[4].e = 'C';  node[4].d = 1;
	node[5].e = 'D';  node[5].d = 0;
	node[6].e = 'E';  node[6].d = 0;
	node[7].e = 'F';  node[7].d = 3;
	node[8].e = 'G';  node[8].d = 0;
	node[9].e = 'H';  node[9].d = 0;
	node[10].e = 'K'; node[10].d = 0;
	
	Algo_6_68(&T, node); 
	
	printf("�����ĺ����ֵܶ�����Ϊ��\n");
	Print_CS(T);
	printf("\n");
	
	return 0;
}

/*��������������������������������
�� ��6.68���������ĺ���-�ֵܽṹ��
��������������������������������*/
void Algo_6_68(CSTree *T, TreeNode node[])				//node�д洢����㼰��ȵ���Ϣ			
{
	int i, j, count;
	int m;
	CSTree p, q;
	CSTree tmp[100];
	
	*T = NULL;
	
	if(node[0].d)										//����Ϊ�� 
	{
		i = j = 1;
		
		*T = (CSTree)malloc(sizeof(CSNode));			//����� 
		if(!(*T))
			exit(OVERFLOW);
		(*T)->data = node[j].e;
		(*T)->firstchild = (*T)->nextsibling = NULL;
			
		tmp[j] = (*T);
		
		count = 0;
		while(j+1<=node[0].d)							//j�����ٶȽϿ� 
		{
			if(count<node[i].d)							//ͳ��i���ĺ��� 
			{
				++count;
				++j;			
		
				p = (CSTree)malloc(sizeof(CSNode));	
				if(!p)
					exit(OVERFLOW);
				p->data = node[j].e;
				p->firstchild = p->nextsibling = NULL;
					
				tmp[j] = p;			
				
				if(tmp[i]->firstchild==NULL)			//��Ϊ��һ������ 
					tmp[i]->firstchild = p;
				else
				{
					q = tmp[i]->firstchild;				//Ѱ�Һ��������ĩ�� 
					while(q->nextsibling)
						q = q->nextsibling;
					q->nextsibling = p;
				}
			}
			
			if(count==node[i].d)						//i���ĺ����ѱ����� 
			{
				i++;									//��ʼ�µĽ�� 
				count = 0;
			}
		}
	}
}
