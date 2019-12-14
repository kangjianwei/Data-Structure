#include <stdio.h>
#include <stdlib.h>							//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h" //**��01 ����**//

/* ����ԭ�� */
int Algo_3_25_1(int n);
int Algo_3_25_2(int n);

int main(int argc, char *argv[])
{
	printf("F( 5) = %d\n", Algo_3_25_1(5));
	printf("\n");
	printf("F(10) = %d\n", Algo_3_25_2(10));
	printf("\n");
	
	return 0;
}

/*����������������������
����3.25���ݹ����F(n)��
����������������������*/
/* ����1���ݹ鷨��⣬�ŵ����㷨�� */ 
int Algo_3_25_1(int n)
{
	if(n<0)
		exit(ERROR);
		
	if(!n)
		return n + 1;
	else
		return n * Algo_3_25_1(n/2);
}

/*����������������������
����3.25����������F(n)��
����������������������*/
/* ����2�������ݹ�ĵ��������ŵ��Ǵ洢����һ�������ֵ */
int Algo_3_25_2(int n)
{
	int a[n+1];
	int i;
	
	if(n<0)
		exit(ERROR);		
	
	for(i=1,a[0]=1; i<=n; i++)
		a[i] = i * a[i/2];
	
	return a[n];
}
