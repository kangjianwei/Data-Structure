#include <stdio.h>
#include <limits.h>										//�ṩ��INT_MAX 
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//

/* �궨�� */
#define arrsize 20										//���鳤�� 
#define maxint INT_MAX									//�������� 

/* ����ԭ�� */
Status Algo_1_19(int i, int a[]);

int main(int argc, char *argv[])
{
	int i, a[arrsize];
	
	i = 5;
	
	printf("����i!*2^i...\n");
	
	if(Algo_1_19(i, a)==OK)
		printf("��Ϊʾ�������㵱i = %d ʱ��a[i-1] = %d\n", i, a[i-1]);
	printf("\n");
	
	return 0;
}
 
/*����������������������������������������
����1.19������i!*2^i����a[i-1]��i���Ϊ1��
����������������������������������������*/
Status Algo_1_19(int i, int a[])
{
	int j;
	
	if(i<1 || i>arrsize)
		return ERROR;
	
	for(j=1; j<=i; j++)
	{
		if(j==1)
			a[j-1] = 2;
		else
		{
			if(maxint/(2*j)<a[j-2])
				return OVERFLOW;
				
			a[j-1] = 2 * j * a[j-2];		
		}	
	}
	
	return OK;
}
