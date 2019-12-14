#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  							//**��01 ����**//

/* ����ԭ�� */
void Algo_5_18(int a[], int n, int k);
Status Reversal_5_18(int a[], int n, int start, int end);

int main(int argc, char *argv[])
{
	int A[10] = {1,2,3,4,5,6,7,8,9,10}; 
	int i;
	int k = 5;										//����λ�� 
	
	printf("����A������Ԫ��Ϊ��\n��");
	for(i=0; i<10; i++) 
		printf("%2d ", A[i]);
	printf("\n");
	
	printf("��Ԫ��A[0]��A[9]ѭ������ %d ��λ�ú������Ϊ��\n��", k);
	Algo_5_18(A, 10, k);
	for(i=0; i<10; i++) 
		printf("%2d ", A[i]);
	printf("\n\n");	
	
	return 0;
}

/*��������������������������������������������
����5.18��������a[n]�е�Ԫ��ѭ������k��λ�� ��
��������������������������������������������*/
void Algo_5_18(int a[], int n, int k)
{
	int p = k%n;									//ʵ��ѭ�����Ƶ�λ��
	
	if(p)											//����λ����Ϊ0����� 
	{
		Reversal_5_18(a, n, 1, n);
		Reversal_5_18(a, n, 1, p);
		Reversal_5_18(a, n, p+1, n);	
	}
}

/* ��������a[n]�е�start�����end��֮���Ԫ��*/
Status Reversal_5_18(int a[], int n, int start, int end)
{
	int e, i;									//ֻ��eһ���ռ���ʱ�洢��������� 
	
	if(start<1 || end>n || start>end)
		return ERROR;
	
	for(i=0; i<(end-start+1)/2; ++i)			//��"������"����
	{
		e = a[end-i-1];
		a[end-i-1] = a[start+i-1];
		a[start+i-1] = e;
	}
	
	return OK;
}
