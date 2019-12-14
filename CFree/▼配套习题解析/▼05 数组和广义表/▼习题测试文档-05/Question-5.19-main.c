#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//

/* �궨�� */
#define MAX 256 

/* ���Ͷ��� */
typedef struct
{
	int x;
	int y;
	int value;
}Node;
typedef Node SNode;

/* ����ԭ�� */
Status Algo_5_19(int a[MAX][MAX], int row, int col, SNode p[MAX]);
void Min_row(int a[MAX][MAX], int col, int i, Node min[MAX]);
Status IsMax_col(int a[MAX][MAX], int row, Node v);

int main(int argc, char *argv[])
{
	SNode p[MAX];	
	int row = 4;
	int col = 4;
	int a[MAX][MAX] = {{ 1, 2,  1, 4},
					   {-1, 6, -5, 2},
					   {-2, 7,  0, 1},
					   { 1, 2,  1, 3}};
	int i, j, k;
	
	printf("����Ϊ...\n");
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%3d ", a[i][j]);
		
		printf("\n");
	}
	
	printf("\n");
	
	if(Algo_5_19(a, row, col, p))
	{
		printf("�˾����д�������...\n");
		for(k=1; k<=p[0].value; k++)
			printf("�� %d �е� %d �е����� %d\n", p[k].x, p[k].y, p[k].value);
	}
	else
		printf("�˾����в���������...\n");
	
	printf("\n");
	
	return 0;
}

/*��������������������
����5.19��Ѱ�����㩧
��������������������*/
Status Algo_5_19(int a[MAX][MAX], int row, int col, SNode p[MAX])
{
	int i, k;
	Node min[MAX];
	
	p[0].value = 0;
	
	for(i=0; i<row; i++)
	{
		Min_row(a, col, i, min);
		for(k=1; k<=min[0].value; k++)
		{
			if(IsMax_col(a, row, min[k]))
			{
				p[0].value++;
				p[p[0].value] = min[k];
			}
		}
	}
	
	if(p[0].value)
		return TRUE;
	else
		return FALSE;	
}

/* �ҳ�����a�е�i�е���Сֵ */
void Min_row(int a[MAX][MAX], int col, int i, Node min[MAX])
{
	int j;
	
	min[0].value = 0;
	
	for(j=0; j<col; j++)
	{
		if(!j || a[i][j]==min[j-1].value)
			min[0].value++;
		else
		{
			if(a[i][j]<min[j-1].value)
				min[0].value = 1;
			else
				continue;
		}
			
		min[min[0].value].x = i;
		min[min[0].value].y = j;
		min[min[0].value].value = a[i][j];			
	}
}

/* �ж�v�е�ֵ�Ƿ�Ϊ�������е����ֵ */
Status IsMax_col(int a[MAX][MAX], int row, Node v)
{
	int i;
	
	for(i=0; i<row; i++)
	{
		if(a[i][v.y]>v.value)
			return FALSE;
	}
	
	return TRUE;
}
