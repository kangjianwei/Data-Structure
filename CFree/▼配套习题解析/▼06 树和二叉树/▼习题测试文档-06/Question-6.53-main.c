#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
Status Algo_6_53(BiTree T, int way[100]);

int main(int argc, char *argv[])
{
	BiTree T;
	int way[100];
	int i;
	FILE *fp;
	
	printf("�������������������У�T�� ABD^^EG^^^CF^HI^^J^^^\n��");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_53.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("������TΪ��\n");
	PrintTree(T);
	printf("\n");
	
	Algo_6_53(T, way);
	printf("�������㵽Ҷ�ӽ���·��������һ����");	
	for(i=1; i<=way[0]+1; i++)
		printf("%c ", way[i]);
	printf("\n\n");
	
	return 0;
}

/*����������������������������������������������������
����6.53��Ѱ�Ҹ���㵽Ҷ�ӽ���·��������һ����
����������������������������������������������������*/
Status Algo_6_53(BiTree T, int way[100])
{
	int path[100][100] = {};		//���д�������ҵ���·������0�д��·������ 
	BiTNode node[100];				//��ʱ��ű����и����ĸ���Ʒ 
	int count, max_len;				//count��¼·��������max_len��¼·����󳤶� 
	int i, k;
	
	if(!T)
		return ERROR;
	
	i = 0;
	count = max_len = 0;
	
	node[i] = *T;
	
	while(i>=0)
	{
		while(node[i].lchild)					//��������ʵ���ͷ 
		{
			node[i+1] = *(node[i].lchild);
			node[i].lchild = NULL;
			i++;
		}
		
		if(node[i].rchild)						//������Ϊ��ʱ������������ 
		{
			node[i+1] = *(node[i].rchild);
			node[i].rchild = NULL;
			i++;
		}
		else									//����Ҷ�ӽ�� 
		{
			count++;							//·��������һ 
			path[count-1][0] = i;				//�洢·������ 
			for(k=0; k<=i; k++)
				path[count-1][k+1] = node[k].data;
			if(max_len<i)						//��¼���·������ 
				max_len = i;
			i--;
		}
	}//����ȫ��·�����ҳ� 
			
	for(k=0; k<count; k++)
	{
		if(path[k][0]==max_len) 
		{
			for(i=0; i<=max_len+1; i++)
				way[i] = path[k][i];
			break;								//�ҵ������һ������ 
		}
	}
	
	return OK;
}
