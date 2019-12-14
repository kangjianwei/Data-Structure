#include <stdio.h>
#include <stdlib.h>							//�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  			//**��01 ����**//

/* ����ԭ�� */
float Algo_3_26_1(float A, float p, float e);
float Algo_3_26_2(float A, float p, float e);

int main(int argc, char *argv[])
{
	printf("��10 = %f\n", Algo_3_26_1(10, 1, 0.000001));
	printf("\n");
	printf("��50 = %f\n", Algo_3_26_2(50, 1, 0.000001));
	printf("\n");
	
	return 0;
}

/*������������������������
����3.26���ݹ����ƽ������
������������������������*/
/* ����1���ݹ鷨 */ 
float Algo_3_26_1(float A, float p, float e)
{
	if(A<0.0)
		exit(ERROR);
		
	if((p*p-A)>-e && (p*p-A)<e)
		return p;
	else
		return Algo_3_26_1(A, (p+A/p)/2, e);
}

/*������������������������
����3.26����������ƽ������
������������������������*/
/* ����2�������� */
float Algo_3_26_2(float A, float p, float e)
{
	if(A<0.0)
		exit(ERROR);
		
	while((p*p-A)>=e || (p*p-A)<=-e)
		p = (p + A/p) / 2;
		
	if((p*p-A)>-e && (p*p-A)<e)
		return p;
}
