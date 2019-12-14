#include <stdio.h>
#include <stdlib.h>										//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	//**��01 ����**//

/* ����ԭ�� */
int Algo_1_17_1(int k, int m);
int Algo_1_17_2(int k, int m);

int main(int argc, char *argv[])
{
	int k, m;
	
	k = 3;
	m = 10;
	
	printf("��Ϊʾ������� %d ��쳲��������е� %d ���ֵΪ��%d \n", k, m, Algo_1_17_1(k, m));
	
	printf("��Ϊʾ������� %d ��쳲��������е� %u ���ֵΪ��%d \n", k, 2*m, Algo_1_17_2(k, 2*m));
	
	printf("\n");
	
	return 0;
}

/*��������������������������������������
����1.17������k��쳲��������е�m���ֵ��
��������������������������������������*/
/* ����1���ݹ��㷨 */
int Algo_1_17_1(int k, int m)			//��m���ʱ�������ٶȻ�ݼ� 
{
	int i, value;
	
	if(k<2 || m<0)
		exit(OVERFLOW);
	
	if(m<k-1)
		return 0;
	else if(m==k-1)
		return 1;
	else
	{
		for(i=1,value=0; i<=k; i++)
			value += Algo_1_17_1(k, m-i);
		
		return value;
	}
}

/*��������������������������������������
����1.17������k��쳲��������е�m���ֵ��
��������������������������������������*/
/* ����2�����ƣ��������㷨 */
int Algo_1_17_2(int k, int m)
{
	int i, j;
	int fib[m+1];
	
	if(k<1 || m<0)
		exit(OVERFLOW);
	
	i = 0;
	while(i<k-1)
	{
		fib[i] = 0;
		i++;		
	}
		
	fib[i] = 1;							//i = k-1
	i++;
			
	while(i<=m)							//i = k
	{	
		for(j=i-1,fib[i]=0; j>=i-k; j--)
			fib[i] += fib[j];
		i++;
	}
	
	return fib[m];	
}
