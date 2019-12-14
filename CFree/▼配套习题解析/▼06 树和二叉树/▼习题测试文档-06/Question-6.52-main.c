#include <stdio.h>
#include <math.h>								//�ṩpow��logԭ�� 
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/02 BinaryTree/BinaryTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
int Algo_6_52(BiTree T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("�������������������У�T�� ABDG^^^EH^^I^^CF^J^^^...\n");
	InitBiTree(&T); 
	fp = fopen("Data/Algo_6_52.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("������TΪ��\n");
	PrintTree(T);
	printf("\n");
		
	printf("���ķ�ï��Ϊ�� %d", Algo_6_52(T));		
	printf("\n\n");
	
	return 0;
}

/*����������������������������
����6.52������������ķ�ï�ȩ�
����������������������������*/
int Algo_6_52(BiTree T)
{
	int i, j, level, v;
	float f;
	int max_row, max_col;				//��¼������������������� 
	BiTree p[100] = {};					//��ָ�����飬ģ����� 
	int order[100] = {}; 				//��Ÿ������ţ��������������㣩 
	int count[100] = {};				//�±����㣬��������Ϊ��������� 

	v = 0;
	i = j = 0;
	max_row = max_col = 0;

	if(T)								//������ͬʱΪ������� 
	{
		p[j] = T;	
		order[j] = 1;
		j++;
		
		while(i<j)
		{
			f = log(order[i])/log(2);
			level = (int)f + 1;			//���㵱ǰ������ڲ���
			if(max_row<level)
				max_row = level;
		
			count[level]++;				//������ǰ������� 
			if(max_col<count[level])
				max_col = count[level];
			
			if(p[i]->lchild)
			{
				p[j] = p[i]->lchild;
				order[j] = 2*order[i];
				j++;			
			}

			if(p[i]->rchild)
			{
				p[j] = p[i]->rchild;
				order[j] = 2*order[i]+1;
				j++;
			}
			
			i++;		
		}
	}
	
	v = max_row * max_col;				//���㷱ï�� 
	
	return v;
}
