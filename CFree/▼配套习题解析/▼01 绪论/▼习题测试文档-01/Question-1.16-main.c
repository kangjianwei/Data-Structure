#include <stdio.h>

/* ����ԭ�� */
void Algo_1_16(int i, int j, int k);

int main(int argc, char *argv[])
{
	int i, j, k;
	
	i = 3;
	j = 7;
	k = 1;
	
	printf("��Ϊʾ�����趨���ζ������������Ϊ��%d %d %d...\n", i, j, k);
	printf("���������Ӵ�С��˳��Ϊ��");
	
	Algo_1_16(i, j, k);
	printf("\n");
	
	return 0;
}

/*��������������������������������������
����1.16����3���������Ӵ�С˳����� ��
��������������������������������������*/
void Algo_1_16(int i, int j, int k)
{
	int tmp;
	
	if(i<j)
	{
		tmp = i;
		i = j;
		j = tmp;
	}
	
	if(j<k)
	{
		tmp = j;
		j = k;
		k = tmp;	
	}
	
	if(i<j)
	{
		tmp = i;
		i = j;
		j = tmp;
	}	
	
	printf("%d %d %d\n", i, j, k);
}
